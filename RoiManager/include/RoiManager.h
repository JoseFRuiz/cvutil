/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: RoiManager.h

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

#ifndef ROIMANAGER_H
#define ROIMANAGER_H

#include "PluginAPI.h"
#include "PluginInterfaces.h"
#include <QtWidgets>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib, "Qt6Cored.lib")
#pragma comment(lib, "Qt6Guid.lib")
#pragma comment(lib, "Qt6Widgetsd.lib")
#else
#pragma comment(lib, "Qt6Core.lib")
#pragma comment(lib, "Qt6Gui.lib")
#pragma comment(lib, "Qt6Widgets.lib")
#endif

//#include <GraphicsScene.h>
enum class MouseMode { PixelValue, ImagePanning, RegionOfInterest };
enum class RegionOfInterestSubMode { PixelValue, ImagePanning, RegionOfInterest };
enum class BorderHoverMode { None, TopLeft, Top, TopRight, Right, BottomRight, Bottom, BottomLeft, Left };

class PLUGINAPI RoiManager : public QObject
{
    Q_OBJECT

    //GraphicsScene *gscene = nullptr;

    // Roi management
    std::vector<QGraphicsRectItem *> rois;
    std::vector<QString> roinames;
    std::vector<QString> classes;
    QString roinameprefix = "roi_";
    QString defaultclassname = "class1";
    int roicount = 1;
    double zoomscale;

    // Current state variables.
    bool IsROICreating = false;
    bool IsROIMoving = false;
    QColor roicolor = QColor::fromRgb(255, 0, 0);
    int penwidth = 1;

    RoiManager(QObject *parent = nullptr) { /*selectedrois.reserve(100);*/ }
    ~RoiManager() {}

public:
    static RoiManager* GetInstance();

    // To prevent copies
    RoiManager(RoiManager const&) = delete;
    void operator=(RoiManager const&) = delete;

    // Create new ROI
    QGraphicsRectItem *createROI(int x1, int y1, int x2, int y2, qreal w, qreal h, bool update);

    // Moves selected ROIs
    void moveROIs(int x1, int y1, int x2, int y2, qreal w, qreal h);

    // Resize the ROIs.
    void resizeROIs(BorderHoverMode m, QRectF hoverrect, std::vector<QRectF> srois, int x1, int y1, int x2, int y2, qreal w, qreal h);

    // Delete a list of ROIs.
    void deleteList(std::vector<int> indices);

    // Set x, y, width and height for selected ROIs
    void setX(int x, qreal scenewidth);
    void setY(int y, qreal sceneheight);
    void setWidth(int width, qreal scenewidth);
    void setHeight(int height, qreal sceneheight);

    //void setScene(GraphicsScene *scene);
    std::vector<QGraphicsRectItem *> getROIs();
    int getROICount();
    int getSelectedROICount();
    QGraphicsRectItem * getROI(int idx);
    std::vector<QGraphicsRectItem *> getSelectedROIs();
    std::vector<int> getSelectedIndices();
    void moveSelected(int xp, int yp);
    void setSelectable(bool on);
    std::vector<QGraphicsRectItem *> copypaste(std::vector<int> copyrois, std::vector<QRectF> copyroirects, qreal w, qreal h);

    BorderHoverMode hoverMode(int idx, qreal x, qreal y);

    std::string getClassName(int idx);
    void setClassName(int idx, std::string cname);
    void setDefaultClassName(std::string cname);
    std::string getROIName(int idx);
    void setROIName(int idx, std::string cname);
    void selectROIbyName(std::string name);

    void addROI(QGraphicsRectItem* roi, QString name = "", QString classname = "");
    void removeROI(QGraphicsRectItem* roi);
    void clearROIs();
    void setROIClass(QGraphicsRectItem* roi, QString classname);
    void setROIName(QGraphicsRectItem* roi, QString name);
    QString getROIClass(QGraphicsRectItem* roi);
    QString getROIName(QGraphicsRectItem* roi);
    std::vector<QString> getROINames();
    std::vector<QString> getROIClasses();
    void setROIDimensions(QGraphicsRectItem* roi, QRectF rect);
    QRectF getROIDimensions(QGraphicsRectItem* roi);
    void setROISelected(QGraphicsRectItem* roi, bool selected);
    bool isROISelected(QGraphicsRectItem* roi);
    void setROIVisible(QGraphicsRectItem* roi, bool visible);
    bool isROIVisible(QGraphicsRectItem* roi);
    void setROIColor(QGraphicsRectItem* roi, QColor color);
    QColor getROIColor(QGraphicsRectItem* roi);
    void setROIPen(QGraphicsRectItem* roi, QPen pen);
    QPen getROIPen(QGraphicsRectItem* roi);
    void setROIBrush(QGraphicsRectItem* roi, QBrush brush);
    QBrush getROIBrush(QGraphicsRectItem* roi);
    void setROIZValue(QGraphicsRectItem* roi, qreal z);
    qreal getROIZValue(QGraphicsRectItem* roi);
    void setROITransform(QGraphicsRectItem* roi, QTransform transform);
    QTransform getROITransform(QGraphicsRectItem* roi);
    void setROIPos(QGraphicsRectItem* roi, QPointF pos);
    QPointF getROIPos(QGraphicsRectItem* roi);
    void setROIRotation(QGraphicsRectItem* roi, qreal angle);
    qreal getROIRotation(QGraphicsRectItem* roi);
    void setROIScale(QGraphicsRectItem* roi, qreal sx, qreal sy);
    QPointF getROIScale(QGraphicsRectItem* roi);
    void setROIShear(QGraphicsRectItem* roi, qreal sh, qreal sv);
    QPointF getROIShear(QGraphicsRectItem* roi);
    void setROITranslation(QGraphicsRectItem* roi, qreal dx, qreal dy);
    QPointF getROITranslation(QGraphicsRectItem* roi);
    void setROIMatrix(QGraphicsRectItem* roi, QMatrix matrix);
    QMatrix getROIMatrix(QGraphicsRectItem* roi);
    void setROIItemTransform(QGraphicsRectItem* roi, QGraphicsTransform* transform);
    QGraphicsTransform* getROIItemTransform(QGraphicsRectItem* roi);
    void setROIItemFlags(QGraphicsRectItem* roi, QGraphicsItem::GraphicsItemFlags flags);
    QGraphicsItem::GraphicsItemFlags getROIItemFlags(QGraphicsRectItem* roi);
    void setROIItemCacheMode(QGraphicsRectItem* roi, QGraphicsItem::CacheMode mode);
    QGraphicsItem::CacheMode getROIItemCacheMode(QGraphicsRectItem* roi);
    void setROIItemBoundingRegionGranularity(QGraphicsRectItem* roi, qreal granularity);
    qreal getROIItemBoundingRegionGranularity(QGraphicsRectItem* roi);
    void setROIItemAcceptDrops(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptDrops(QGraphicsRectItem* roi);
    void setROIItemAcceptHoverEvents(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptHoverEvents(QGraphicsRectItem* roi);
    void setROIItemAcceptTouchEvents(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptTouchEvents(QGraphicsRectItem* roi);
    void setROIItemAcceptsHoverEvents(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsHoverEvents(QGraphicsRectItem* roi);
    void setROIItemAcceptsTouchEvents(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsTouchEvents(QGraphicsRectItem* roi);
    void setROIItemAcceptsDrops(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsDrops(QGraphicsRectItem* roi);
    void setROIItemAcceptsHover(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsHover(QGraphicsRectItem* roi);
    void setROIItemAcceptsTouch(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsTouch(QGraphicsRectItem* roi);
    void setROIItemAcceptsDrop(QGraphicsRectItem* roi, bool on);
    bool getROIItemAcceptsDrop(QGraphicsRectItem* roi);

public slots:
    // Delete all ROIs.
    void deleteAll();

    // Delete all selected ROIs.
    void deleteSelected();

    // Delete ROI.
    //void deleteROI(int idx);
    //void deleteROI(std::string name);

    // Select ROI
    void selectROI(int idx);

    // Clear selection
    void clearSelection();
    void clearSelection(int idx);

    // Select All
    void selectAll();

    // Set the width of the ROI borders so that the ROIs
    // are visible when user zooms in or out of the image.
    void setROIBorderWidth(double s);

    // Slot to invoke when an image with different dimensions is loaded.
    void updateBoundaries(qreal w, qreal h);

    // Load ROIs from a text file
    std::vector<QGraphicsRectItem *> loadAnnotation(QString filepath);

    // Load ROIs from a text file
    void saveAnnotation(QString filepath);

    // Enable messaging to main window that utilizes RoiManager
    void setMessageHandler(QtMessageHandler logger);

signals:
    void selectedROIDimensionChanged(QGraphicsRectItem* roi, QRectF rect);
};

#endif
