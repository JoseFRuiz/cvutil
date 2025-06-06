/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: MainWindow.h

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

#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QtWidgets>
//#include <ImageProcessor.h>

#include <PluginInterfaces.h>
#include <PluginManager.h>

#include <RoiManager.h>

//#include "ParameterListWidget.h"
#include "InteractiveExtractorThread.h"
#include "GraphicsScene.h"
#include "../figure.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT;

private:
    GraphicsScene *gscene;
    QGraphicsPixmapItem *pix = nullptr;
    int rotation = 0;
    bool enabletransformations = false;

protected:
    virtual void wheelEvent(QWheelEvent *);
    //virtual void keyPressEvent(QKeyEvent *event);
    //virtual void mouseReleaseEvent(QMouseEvent *event);
    //virtual void mouseMoveEvent(QMouseEvent *event);
    //virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);

public:
    GraphicsView();
    GraphicsView(QWidget *parent);

    void setPixmap(QImage image);
    double GetScale();
    void SetScale(double s, bool updateTransform = true);

    MouseMode getMouseMode() const { return gscene->getMouseMode(); }
    void setMouseMode(MouseMode _mode) { gscene->setMouseMode(_mode); }

    void setRotation(int rot);
    int getRotation();

    void setEnabledTransformations(bool on);

    double scaleval = 1.0;
    const double scalemultiplier = 1.1;

public slots:
    void propagatePixelInfo(int rowid, int colid);

signals:
    void showPixelInfo(int rowid, int colid);
    void openFile(QString filename);
};

class ProgressReporter : public QDialog
{
    Q_OBJECT;

private:
    QLabel *lblstatus;
    QProgressBar *pbar;
    QPushButton* cbtn;
    InteractiveExtractorThread *worker;
    IPlugin *pl;
    bool canceled = false;

public:
    ProgressReporter(IPlugin *plugin);
    ~ProgressReporter();
    void start();
    bool wasCanceled();

public slots:
    void UpdateProgress(QString status);
    void finished();
    void cancelProgress();
};

class HeaderViewWithWordWrap : public QHeaderView
{
    Q_OBJECT;
    
public:
    explicit HeaderViewWithWordWrap(QStandardItemModel* mdl, Qt::Orientation orientation, QWidget *parent = 0) : QHeaderView(orientation, parent)
    {
        QHeaderView::setModel(mdl);
        setContentsMargins(0, 0, 0, 0);
        setSectionsClickable(true);
        setHighlightSections(true);
    }

    virtual QSize sectionSizeFromContents(int logicalIndex) const override
    {
        QString headerText = model()->headerData(logicalIndex, QHeaderView::orientation(), Qt::DisplayRole).toString();
        ensurePolished();
        QFontMetrics metrics(font());
        auto maxWidth = QHeaderView::sectionSize(logicalIndex);
        const QSize margin(0, 20);
        auto rect = metrics.boundingRect(QRect(0, 0, maxWidth, 5000), Qt::TextWordWrap | Qt::AlignCenter, headerText, 4);
        return rect.size() + margin;
    }
};

class MainWindow : public QMainWindow, public cvutilWindow
{
    Q_OBJECT;

    GraphicsView *view;
    
    QList<QString> pixelformats = { "RGB", "HSV", "HLS", "Lab", "Luv" };
    QString pfmt = "RGB";

    // Docking cpabilities for options
    QDockWidget *actiondocker, *logdocker, *roipropdocker;

    QSpinBox *spx, *spy, *spw, *sph;
    QLineEdit *classname, *roiname;
    QListWidget *roilist;
    bool uilistselecting = false, updatingroilist = false;

    bool updatingROI = false;

    bool roienabled = true;
    bool actionsenabled = true;

    int curridx = 0;
    QComboBox *pnamelist = nullptr;
    //QPushButton *execute = nullptr;
    bool IsCustomWidget = false;

    std::vector<QWidget *> pwidgets;
    QVBoxLayout *vl = nullptr;
    IPlugin *mainplugin = nullptr;

    int displayidx = -1;

    QMenu *viewMenu = nullptr;
    QAction *roitoolbaract = nullptr;
    std::string abttxt;
    QPixmap appimage;
    QIcon appicon;

    // Image rotation management
    // QAction *rot90clock = nullptr, *rot90anti = nullptr, *rot180 = nullptr;
    QLabel *lbrotation;
    QComboBox *cbrotation;

    // For enabling zooming and rotation
    QToolBar *zoomtb, *colinvtb, *rottb, *mousemodetb, *pixelstattb, *browseimagetb, *executetb;
    QToolBar *plugintb;
    QAction *invertColors;

    // Model to store extracted features for viewing
    QStandardItemModel *featureitemmodel = nullptr;
    QDockWidget* featureWidget = nullptr;
    QDockWidget* chartWidget = nullptr;
    QTableView* featureview = nullptr;

    // Banner management
    QGraphicsPixmapItem *orgbanneritem = nullptr, *appbanneritem = nullptr;
    QGraphicsTextItem *appitem = nullptr, *wflowitem = nullptr;

    // For syncing with featureview
    std::vector<std::vector<double>> featureviewsync;
    std::vector<QString> roisync;
    std::vector<QString> filenamesync;
    QStringList colnamelist;

    enum class SaveAsMode { DisplayedImage, Annotation, Features, Settings };
    SaveAsMode currsavemode = SaveAsMode::DisplayedImage;

    QString inputfileloc, imgbasename;
    int currimagelistidx = -1;
    QStringList imagelist;
    QFileSystemWatcher *fswatcher = nullptr;

    QString savefile;
    bool initialized = false;
    QImage img;
    QString inputfilename;
    cv::Mat input;
    std::vector<cv::Mat> output;

private:
    void createmenus();
    void createtoolbars();
    
    void setPluginUI();
    void setROIUI();
    void processImage();
    
    void copyItems();
    void saveas(SaveAsMode savmode, QString fileName = "");
    void populateFileList();
    void loadNextImage(bool front);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void wheelEvent(QWheelEvent *event) override;

private slots:
    //void formatchanged();
    
    void open();
    void open(QString filename, bool refreshlist = true);
    void save();
    void about();

    void zoomout();
    void zoomin();
    void zoomfit();

    void displayPixelInfo(int x, int y);
    void displayImageStats(std::vector<QRectF> rois);

    void batchAnalysis();

    void pixelformatchanged();
    void setROILimits();
    void updateROIDimensions();

    void loadAnnotation();
    //void saveAnnotation();

    void reinitfeatureview();
    void viewcontextmenu(const QPoint &pos);

    void watcherDirectoryChanged(const QString & path);
    void setRotation(int angle);

    void logUpdated(); // Potential bug: Multiple image processing windows.
public:
    static QTextEdit *logbox;
    static bool showDebugMessages;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // cvutilWindow interface functions
    void show() { QMainWindow::showMaximized(); }
    void loadPlugins(IPlugin *plugin = nullptr);
    void refreshPlugins();

    void addNewDockWidget(QDockWidget *w);
    void enableROI(bool on);
    void enableActions(bool on);

    void setAboutText(std::string txt, QPixmap applicationimage, QIcon applicationicon);
    void setInitialBanner(QPixmap initbanner, QPixmap orgbanner, std::string appbanner, std::string inistr);
    cv::Mat getLoadedImage();
    int getDisplayOutputIndex();
    void setDisplayOutputIndex(int idx);
    //DisplayMode getDisplayMode();
    void addToolBar(QToolBar *tbar);
    
    void setVisibleROI(bool on);
    void setVisibleActions(bool on);

    void showChartWidget(QChart *chart);
    int getRotation();
    bool colorInversionEnabled();
    void setColorInversionEnabled(bool on);

public slots:
    void setImage(cv::Mat m);
    
signals:
    void imageChanged();
};



#endif
