/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: cvutil_figure.cpp

Authors: 
Anand Seethepalli (anand.seethepalli@yahoo.co.in)
Larry York (larry.york@gmail.com)

This file is part of Computer Vision UTILity toolkit (cvutil)

cvutil is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

cvutil is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with cvutil; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.
*/

#include "cvutil_figure.h"
#include "cvutil.h"
#include "MainWindow/logger.h"

// These macros may be defined when Windows.h is included prior to
// including Qt headers. It is necessary to undefine them before
// working with Qt.
#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QToolBar>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCore/QPoint>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>

// QT_CHARTS_USE_NAMESPACE

using namespace std;
using namespace cv;
using namespace cvutil;
using namespace QtCharts;

int figure_impl::figure_number = 0;
int figure_impl::default_precision = 2;

void figure_impl::barplot(Mat x, vector<string> categories, Mat y, vector<string> groups)
{
    QBarSet **sets;

    sets = new QBarSet*[y.cols];

    // To create sets for plotting
    if (groups.empty())
    {
        for (int i = 0; i < y.cols; i++)
            sets[i] = new QBarSet(QString::fromStdString(to_string(i)));
    }
    else
    {
        CV_ASSERT2(groups.size() == y.cols, "The number of caterory names must be equal to the columns in y.");

        for (int i = 0; i < y.cols; i++)
            sets[i] = new QBarSet(QString::fromStdString(groups[i]));
    }
    
    // To populate sets with data.
    Mat ydata = y.clone();
    ydata.convertTo(ydata, CV_64FC1);
    double *yptr = ydata.ptr<double>();

    for (int i = 0; i < y.cols; i++)
        for (int j = 0; j < y.rows; j++)
            *sets[i] << yptr[j * y.cols + i];
    // Get range to be set on y-axis
    auto range = getRange(y);

    // Add all the series to the chart
    QBarSeries *series = new QBarSeries();

    for (int i = 0; i < y.cols; i++)
        series->append(sets[i]);
    
    QChart *barchart;
    
    if (!holdon)
        barchart = new QChart();
    else
        barchart = (charts.back() != nullptr) ? charts.back() : new QChart();

    barchart->addSeries(series);
    barchart->setAnimationOptions(QChart::SeriesAnimations);
    
    QBarCategoryAxis *xaxis = nullptr;
    QValueAxis *yaxis = nullptr;

    // Set x-axis values
    if (categories.size() > 0)
    {
        QStringList categoryvalues;
        
        for (int i = 0; i < y.rows; i++)
            categoryvalues << tr(categories[i].c_str());

        if (!holdon)
            xaxis = new QBarCategoryAxis();
        else
            xaxis = qobject_cast<QBarCategoryAxis *>(barchart->axes(Qt::Horizontal, serieslist.back())[0]);
        
        xaxis->append(categoryvalues);
        
        if (!holdon)
            yaxis = new QValueAxis();
        else
            yaxis = qobject_cast<QValueAxis *>(barchart->axes(Qt::Vertical, serieslist.back())[0]);

        yaxis->applyNiceNumbers();
        
        if (!holdon)
        {
            barchart->addAxis(xaxis, Qt::AlignBottom);
            barchart->addAxis(yaxis, Qt::AlignLeft);
        }

        series->attachAxis(xaxis);
        series->attachAxis(yaxis);
    }
    else
    {
        QStringList categoryvalues;
        double *xptr = x.ptr<double>();
        double minv, maxv;
        minMaxLoc(x, &minv, &maxv);
        for (int i = 0; i < y.rows; i++)
        {
            ostringstream stream;
            stream << fixed << std::setprecision(precision) << xptr[i];
            categoryvalues << tr(stream.str().c_str());
        }
        
        if (!holdon)
            xaxis = new QBarCategoryAxis();
        else
            xaxis = qobject_cast<QBarCategoryAxis *>(barchart->axes(Qt::Horizontal, serieslist.back())[0]);
        
        xaxis->append(categoryvalues);
        
        if (!holdon)
            yaxis = new QValueAxis();
        else
            yaxis = qobject_cast<QValueAxis *>(barchart->axes(Qt::Vertical, serieslist.back())[0]);
        
        yaxis->applyNiceNumbers();
        
        if (!holdon)
        {
            barchart->addAxis(xaxis, Qt::AlignBottom);
            barchart->addAxis(yaxis, Qt::AlignLeft);
        }

        series->attachAxis(xaxis);
        series->attachAxis(yaxis);
    }

    // Store series for future usage
    serieslist.push_back(series);

    // Set legend settings
    if (groups.empty())
        barchart->legend()->setVisible(false);
    else
    {
        barchart->legend()->setVisible(true);
        barchart->legend()->setAlignment(Qt::AlignRight);
    }
    
    // Make grid lines invisible
    //barchart->axisX(serieslist.back())->setGridLineVisible(false);
    //barchart->axisY(serieslist.back())->setGridLineVisible(false);
    xaxis->setGridLineVisible(false);
    yaxis->setGridLineVisible(false);

    // Set y-axis range and tick count
    yaxis->setRange(range.first, range.second);
    QFont font;
    font.setPixelSize(16);
    font.setBold(true);
    barchart->setTitleFont(font);
    barchart->setContentsMargins(0, 0, 0, 0);

    if (holdon)
        return;

    views[nsubplot] = new QChartView(barchart);
    views[nsubplot]->setRenderHint(QPainter::Antialiasing);
    if (!subplotenabled)
        baseLayout->addWidget(views[nsubplot]);
    else
    {
        CV_ASSERT2(((nsubplot >= 0) && (nsubplot < nsubplots)), "The plot number must be any number from 1 to the number of plots the grid can support.");
        baseLayout->addWidget(views[nsubplot], nsubplot / ncols, nsubplot % ncols);
        baseLayout->setRowStretch(nsubplot / ncols, 1);
        baseLayout->setColumnStretch(nsubplot % ncols, 1);
    }
    
    viewtypes[nsubplot] = ViewTypes::ChartView;
    charts[nsubplot] = barchart;
    images[nsubplot] = nullptr;
    cvimages[nsubplot] = Mat();
    
    barchart->update();
    QRectF r = barchart->geometry();
    qreal h = r.height(), w = r.width();
    yratio[nsubplot] = r.height() / yaxis->tickCount();
    
    /*if (categories.size() == 0)
        xratio[nsubplot] = r.width() / xaxis->tickCount();*/
}

void figure_impl::stackedbarplot(cv::Mat x, std::vector<std::string> categories, cv::Mat y, std::vector<std::string> groups)
{
    QBarSet **sets;

    sets = new QBarSet*[y.cols];

    // To create sets for plotting
    if (groups.empty())
    {
        for (int i = 0; i < y.cols; i++)
            sets[i] = new QBarSet(QString::fromStdString(to_string(i)));
    }
    else
    {
        CV_ASSERT2(groups.size() == y.cols, "The number of caterory names must be equal to the columns in y.");

        for (int i = 0; i < y.cols; i++)
            sets[i] = new QBarSet(QString::fromStdString(groups[i]));
    }

    // To populate sets with data.
    Mat ydata = y.clone();
    ydata.convertTo(ydata, CV_64FC1);
    double *yptr = ydata.ptr<double>();

    for (int i = 0; i < y.cols; i++)
        for (int j = 0; j < y.rows; j++)
            *sets[i] << yptr[j * y.cols + i];
    // Get range to be set on y-axis
    auto range = getRange(y);

    // Add all the series to the chart
    QStackedBarSeries *series = new QStackedBarSeries();

    for (int i = 0; i < y.cols; i++)
        series->append(sets[i]);

    QChart *barchart;

    if (!holdon)
        barchart = new QChart();
    else
        barchart = (charts.back() != nullptr) ? charts.back() : new QChart();

    barchart->addSeries(series);
    barchart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *xaxis = nullptr;
    QValueAxis *yaxis = nullptr;

    // Set x-axis values
    if (categories.size() > 0)
    {
        QStringList categoryvalues;

        for (int i = 0; i < y.rows; i++)
            categoryvalues << tr(categories[i].c_str());

        if (!holdon)
            xaxis = new QBarCategoryAxis();
        else
            xaxis = qobject_cast<QBarCategoryAxis *>(barchart->axes(Qt::Horizontal, serieslist.back())[0]);

        xaxis->append(categoryvalues);

        if (!holdon)
            yaxis = new QValueAxis();
        else
            yaxis = qobject_cast<QValueAxis *>(barchart->axes(Qt::Vertical, serieslist.back())[0]);

        yaxis->applyNiceNumbers();

        if (!holdon)
        {
            barchart->addAxis(xaxis, Qt::AlignBottom);
            barchart->addAxis(yaxis, Qt::AlignLeft);
        }

        series->attachAxis(xaxis);
        series->attachAxis(yaxis);
    }
    else
    {
        QStringList categoryvalues;
        double *xptr = x.ptr<double>();
        double minv, maxv;
        minMaxLoc(x, &minv, &maxv);
        for (int i = 0; i < y.rows; i++)
        {
            ostringstream stream;
            stream << fixed << std::setprecision(precision) << xptr[i];
            categoryvalues << tr(stream.str().c_str());
        }

        if (!holdon)
            xaxis = new QBarCategoryAxis();
        else
            xaxis = qobject_cast<QBarCategoryAxis *>(barchart->axes(Qt::Horizontal, serieslist.back())[0]);

        xaxis->append(categoryvalues);

        if (!holdon)
            yaxis = new QValueAxis();
        else
            yaxis = qobject_cast<QValueAxis *>(barchart->axes(Qt::Vertical, serieslist.back())[0]);

        yaxis->applyNiceNumbers();

        if (!holdon)
        {
            barchart->addAxis(xaxis, Qt::AlignBottom);
            barchart->addAxis(yaxis, Qt::AlignLeft);
        }

        series->attachAxis(xaxis);
        series->attachAxis(yaxis);
    }

    // Store series for future usage
    serieslist.push_back(series);

    // Set legend settings
    if (groups.empty())
        barchart->legend()->setVisible(false);
    else
    {
        barchart->legend()->setVisible(true);
        barchart->legend()->setAlignment(Qt::AlignRight);
    }

    // Make grid lines invisible
    //barchart->axisX(serieslist.back())->setGridLineVisible(false);
    //barchart->axisY(serieslist.back())->setGridLineVisible(false);
    xaxis->setGridLineVisible(false);
    yaxis->setGridLineVisible(false);

    // Set y-axis range and tick count
    yaxis->setRange(range.first, range.second);
    QFont font;
    font.setPixelSize(16);
    font.setBold(true);
    barchart->setTitleFont(font);

    if (holdon)
        return;

    views[nsubplot] = new QChartView(barchart);
    views[nsubplot]->setRenderHint(QPainter::Antialiasing);
    if (!subplotenabled)
        baseLayout->addWidget(views[nsubplot]);
    else
    {
        CV_ASSERT2(((nsubplot >= 0) && (nsubplot < nsubplots)), "The plot number must be any number from 1 to the number of plots the grid can support.");
        baseLayout->addWidget(views[nsubplot], nsubplot / ncols, nsubplot % ncols);
        baseLayout->setRowStretch(nsubplot / ncols, 1);
        baseLayout->setColumnStretch(nsubplot % ncols, 1);
    }

    viewtypes[nsubplot] = ViewTypes::ChartView;
    charts[nsubplot] = barchart;
    images[nsubplot] = nullptr;
    cvimages[nsubplot] = Mat();

    barchart->update();
    QRectF r = barchart->geometry();
    qreal h = r.height(), w = r.width();
    yratio[nsubplot] = r.height() / yaxis->tickCount();

    /*if (categories.size() == 0)
    xratio[nsubplot] = r.width() / xaxis->tickCount();*/
}

void figure_impl::imshowplot(QImage &img)
{
    QGraphicsScene* scene = new QGraphicsScene();
    views[nsubplot] = new QChartView();
    views[nsubplot]->setScene(scene);
    views[nsubplot]->setAlignment(Qt::AlignCenter);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
    
    scene->addItem(item);
    views[nsubplot]->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    if (!subplotenabled)
        baseLayout->addWidget(views[nsubplot]);
    else
    {
        //Qt::Alignment al;
        //al.setFlag(Qt::AlignmentFlag::)
        CV_ASSERT2(((nsubplot >= 0) && (nsubplot < nsubplots)), "The plot number must be any number from 1 to the number of plots the grid can support.");
        baseLayout->addWidget(views[nsubplot], nsubplot / ncols, nsubplot % ncols);
        baseLayout->setRowStretch(nsubplot / ncols, 1);
        baseLayout->setColumnStretch(nsubplot % ncols, 1);
    }

    viewtypes[nsubplot] = ViewTypes::ImageView;
    charts[nsubplot] = nullptr;
    images[nsubplot] = &img;
}

void figure_impl::makewindow()
{
    qInstallMessageHandler(logger);
    setWindowTitle(QString("Figure ") + tr(to_string(figno).c_str()));
    resize(900, 600);
    // Create layout for figures
    widget = new QWidget();
    widget->setContentsMargins(0, 0, 0, 0);
    baseLayout = new QGridLayout();
    baseLayout->setSpacing(0);
    baseLayout->setContentsMargins(0, 0, 0, 0);
    baseLayout->setAlignment(Qt::AlignCenter);
    //baseLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
    widget->setLayout(baseLayout);
    // To create actions
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    //saveAct->setStatusTip(tr("Save the chart to disk"));
    connect(saveAct, &QAction::triggered, this, &figure_impl::save);
    fileMenu->addAction(saveAct);
    QAction *saveAsAct = fileMenu->addAction(tr("Save &As..."), this, &figure_impl::saveAs);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    //saveAsAct->setStatusTip(tr("Save the chart under a new name"));

    fileMenu->addSeparator();
    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &figure_impl::close);
    exitAct->setShortcuts(QKeySequence::Quit);
    this->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setSpacing(0);
    setCentralWidget(widget);
    //QMainWindow::show();
}

pair<qreal, qreal> figure_impl::getRange(Mat yvals)
{
    double minv, maxv, powv;
    minMaxLoc(yvals, &minv, &maxv);

    powv = pow(10.0, double(floorf(float(log10(maxv)))));
    maxv = double(ceilf(float(maxv / powv))) * powv;

    if (minv >= 0.0)
        return{ 0.0, maxv };
    else
    {
        minv *= (-1.0);
        powv = pow(10.0, double(floorf(float(log10(minv)))));
        minv = double(ceilf(float(minv / powv))) * powv * (-1.0);

        return{ minv, maxv };
    }
}

bool figure_impl::saveFile(const QString &fileName)
{
    QFile file(fileName);
    
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("SDI"),
            tr("Cannot write file %1:\n%2.")
            .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }

    widget->grab().save(fileName);

    saveFilename = fileName;
    return true;
}

void figure_impl::adjustticks(QChart* chart, int idx)
{
    QRectF r = chart->geometry();

    if (chart->axes(Qt::Horizontal, serieslist.back())[0]->type() == QAbstractAxis::AxisType::AxisTypeValue)
    {
        QValueAxis *temp = ((QValueAxis *)chart->axes(Qt::Horizontal, serieslist.back())[0]);
        int k = int(r.width() / xratio[idx]);
        double qr = (temp->max() - temp->min()) / (k - 1);

        if (std::floor(qr) == std::ceil(qr))
        {
            temp->setTickCount(int(r.width() / xratio[idx]));
        }

        temp->applyNiceNumbers();
    }

    if (chart->axes(Qt::Vertical, serieslist.back())[0]->type() == QAbstractAxis::AxisType::AxisTypeValue)
    {
        QValueAxis *temp = ((QValueAxis *)chart->axes(Qt::Vertical, serieslist.back())[0]);
        int k = int(r.height() / yratio[idx]);
        double qr = (temp->max() - temp->min()) / (k - 1);

        if (std::floor(qr) == std::ceil(qr))
        {
            temp->setTickCount(int(r.height() / yratio[idx]));
        }

        temp->applyNiceNumbers();
    }
}

bool figure_impl::save()
{
    return (saveFilename.isEmpty()) ? saveAs() : saveFile(saveFilename);
}

bool figure_impl::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, 
        tr("Save As"), saveFilename, 
        "PNG file (*.png);;JPEG file (*.jpg);;All files (*.*)", 
        new QString("PNG file (*.png)"));
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void figure_impl::resizeEvent(QResizeEvent* event)
{
    for (auto &a : views)
    {
        a->fitInView(a->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
        a->update();
    }

    /*for (int i = 0; i < nsubplots; i++)
    {
        if (charts[i] == nullptr)
            continue;

        adjustticks(charts[i], i);
    }*/
}

figure_impl::figure_impl() : figure_impl(figure_impl::figure_number + 1)
{

}

figure_impl::figure_impl(int n)
{
    figno = n;
    makewindow();
    //this->chart.clear();
    //this->views.clear();
    this->mode = MouseModes::Pointer;
    this->nrows = 1;
    this->ncols = 1;
    this->precision = default_precision;
    this->subplotenabled = false;
    this->nsubplot = 0;
    this->nsubplots = 1;
    views.resize(1);
    for (auto &a : views)
        a = nullptr;
    viewtypes.resize(1);
    //serieslist.resize(1);
    for (auto &a : serieslist)
        a = nullptr;
    charts.resize(1);
    for (auto &a : charts)
        a = nullptr;
    images.resize(1);
    cvimages.resize(1);
    xratio.resize(1);
    yratio.resize(1);
    figure_number++;
}

figure_impl::~figure_impl()
{
    for (auto i : charts)
    {
        if (i != nullptr)
            i->deleteLater();
    }

    for (auto& i : images)
    {
        if (i != nullptr)
        {
            delete i;
            i = nullptr;
        }
    }

    for (auto i : serieslist)
    {
        if (i != nullptr)
            i->deleteLater();
    }

    for (auto i : views)
    {
        if (i != nullptr)
            i->deleteLater();
    }

    baseLayout->deleteLater();
    widget->deleteLater();
}

void figure_impl::setprecision(int p)
{

}

void figure_impl::bar(vector<string> &x, InputArray y, vector<string> groups, string style)
{
    Mat ymat = getMat(y);

    CV_ASSERT2(x.size() == ymat.rows, "The number of x values and y values must be same.");
    CV_ASSERT2(style == "grouped" || style == "stacked", "The bar plot style should be \"normal\" or \"stacked\".");

    if (style == "grouped")
        barplot(Mat(), x, ymat, groups);
    else
        stackedbarplot(Mat(), x, ymat, groups);
}

void figure_impl::bar(InputArray x, InputArray y, vector<string> groups, string style)
{
    CV_ASSERT2(style == "grouped" || style == "stacked", "The bar plot style should be \"normal\" or \"stacked\".");

    if ((!x.empty()) && (!y.empty()))
    {
        Mat ymat = getMat(y);
        Mat xmat = getMat(x);

        CV_ASSERT2(xmat.cols == 1, "x value should be only one for each sample.");
        CV_ASSERT2(xmat.rows == ymat.rows, "The number of x values and y values must be same.");
        
        if (style == "grouped")
            barplot(xmat, vector<string>(), ymat, groups);
        else
            stackedbarplot(xmat, vector<string>(), ymat, groups);
    }
    else if ((!x.empty()) && (y.empty()))
    {
        Mat ymat = getMat(x);
        Mat xmat = Mat::zeros(ymat.rows, 1, CV_64FC1);
        double *xptr = xmat.ptr<double>();
        
        for (int i = 0; i < ymat.rows; i++)
            xptr[i] = double(i + 1);
        
        if (style == "grouped")
            barplot(xmat, vector<string>(), ymat, groups);
        else
            stackedbarplot(xmat, vector<string>(), ymat, groups);
    }
    else
    {
        return;
    }
}

void figure_impl::scatter(InputArray x, InputArray y, vector<string> groups)
{
    if ((!x.empty()) && (!y.empty()))
    {
        Mat ymat = getMat(y);
        Mat xmat = getMat(x);

        CV_ASSERT2(xmat.cols == ymat.cols, "x value should be only one for each sample.");
        CV_ASSERT2(xmat.rows == ymat.rows, "The number of x values and y values must be same.");

        barplot(xmat, vector<string>(), ymat, groups);
    }
    else if ((!x.empty()) && (y.empty()))
    {
        Mat ymat = getMat(x);
        Mat xmat = Mat::zeros(ymat.rows, 1, CV_64FC1);
        double *xptr = xmat.ptr<double>();

        for (int i = 0; i < ymat.rows; i++)
            xptr[i] = double(i + 1);

        barplot(xmat, vector<string>(), ymat, groups);
    }
    else
    {
        return;
    }
}

void figure_impl::subplot(int rows, int cols, int nplot)
{
    CV_ASSERT2(((subplotenabled) && (nrows == rows && ncols == cols) || (!subplotenabled)), "Number of subplots must not be changed after setting them once.");

    nrows = rows;
    ncols = cols;
    nsubplot = nplot - 1;

    if (!subplotenabled)
    {
        nsubplots = rows * cols;

        views.resize(nsubplots);
        for (auto &a : views)
            a = nullptr;
        viewtypes.resize(nsubplots);
        serieslist.resize(nsubplots);
        for (auto &a : serieslist)
            a = nullptr;
        charts.resize(nsubplots);
        for (auto &a : charts)
            a = nullptr;
        images.resize(nsubplots);
        cvimages.resize(nsubplots);
        xratio.resize(nsubplots);
        yratio.resize(nsubplots);

        subplotenabled = true;
    }
}

void figure_impl::imshow(Mat &img)
{
    Mat imgmat = img.clone();
    QImage::Format format;
    double minv, maxv;

    //CV_ASSERT2(img.depth() != CV_USRTYPE1, "User-defined depths not supported.");
    CV_ASSERT2(img.channels() == 1 || img.channels() == 3, "The image should be either a single-channel grayscale or a 3-channel color image.");

    if (img.channels() == 1)
    {
        minMaxLoc(img, &minv, &maxv);
        
        if (img.depth() == CV_32F || img.depth() == CV_64F)
        {
            if (maxv <= 1.0)
                imgmat = img * 255.0;
        }
        else if (img.depth() == CV_16U || img.depth() == CV_16S || img.depth() == CV_32S)
        {
            if (maxv > 255)
                imgmat = img / 256;
        }

        img.convertTo(imgmat, CV_8UC1);
        format = QImage::Format_Grayscale8;
        cvimages[nsubplot] = img;
    }
    else
    {
        Mat temp = img.reshape(1, img.rows);
        cvtColor(img, imgmat, COLOR_BGR2RGB);

        minMaxLoc(temp, &minv, &maxv);

        if (img.depth() == CV_32F || img.depth() == CV_64F)
        {
            if (maxv <= 1.0)
                imgmat = img * 255.0;
        }
        else if (img.depth() == CV_16U || img.depth() == CV_16S || img.depth() == CV_32S)
        {
            if (maxv > 255)
                imgmat = img / 256;
        }

        imgmat.convertTo(imgmat, CV_8UC3);
        format = QImage::Format_RGB888;
        cvimages[nsubplot] = img;
    }
    
    QImage qimg(imgmat.data, imgmat.cols, imgmat.rows, int(imgmat.step), QImage::Format_RGB888);
    imshowplot(qimg);
}

void figure_impl::title(string txt)
{
    if (this->charts.size() == 0 || this->charts.back() == nullptr)
        return;

    charts.back()->setTitle(tr(txt.c_str()));
}

void figure_impl::xlabel(string lab, int fontSize, string fontWeight)
{
    if (this->charts.size() == 0 || this->charts.back() == nullptr)
        return;

    QFont font;

    if (fontSize > 0)
        font.setPixelSize(fontSize);
    else
        font.setPixelSize(13);

    if (fontWeight == "bold")
        font.setBold(true);
    else
        font.setBold(false);

    charts.back()->axes(Qt::Horizontal, serieslist.back())[0]->setTitleFont(font);
    charts.back()->axes(Qt::Horizontal, serieslist.back())[0]->setTitleText(tr(lab.c_str()));
}

void figure_impl::ylabel(string lab, int fontSize, string fontWeight)
{
    if (this->charts.size() == 0 || this->charts.back() == nullptr)
        return;

    QFont font;

    if (fontSize > 0)
        font.setPixelSize(fontSize);
    else
        font.setPixelSize(13);

    if (fontWeight == "bold")
        font.setBold(true);
    else
        font.setBold(false);

    charts.back()->axes(Qt::Vertical, serieslist.back())[0]->setTitleFont(font);
    charts.back()->axes(Qt::Vertical, serieslist.back())[0]->setTitleText(tr(lab.c_str()));
}

void figure_impl::showgrid(bool on)
{
    charts.back()->axes(Qt::Horizontal, serieslist.back())[0]->setGridLineVisible(on);
    charts.back()->axes(Qt::Vertical, serieslist.back())[0]->setGridLineVisible(on);
}

void figure_impl::hold(bool on)
{
    holdon = true;
}

//QWidget *figure_impl::getChartWidget()
//{
//    return takeCentralWidget();
//}

// TODO: Get chart based on subplot.
QChart* figure_impl::getChart()
{
    return charts.back();
}

void figure_impl::show()
{
    QMainWindow::show();
}

void figure_impl::wait()
{
    QApplication::instance()->exec();
    //GlobalValues::app->exec();
}

void figure_impl::release()
{
    delete this;
}

#ifdef CVUTIL_EXPORTS
cv::Ptr<figure> cvutil::createfigure()
{
    return cv::Ptr<figure>(new Figure());
}

cv::Ptr<figure> cvutil::createfigure(int n)
{
    return cv::Ptr<figure>(new Figure(n));
}
#endif
