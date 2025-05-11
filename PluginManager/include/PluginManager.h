/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: PluginManager.h

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

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

//#include <cvutil.h>
#include <QWidget>
#include <QLayout>
#include <QMatrix>
#include <QTransform>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsTransform>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef WIN32
#if (!defined PLUGINAPI)
#if (defined PLUGINMANAGER_SOURCE)
#define PLUGINAPI __declspec(dllexport)
#else
#define PLUGINAPI __declspec(dllimport)
#endif
#endif
#endif

#include "PluginInterfaces.h"

#if (defined PLUGINMANAGER_SOURCE)
#include "PluginUI/ParameterListWidget.h"
#endif

class PLUGINAPI PluginManager : public QObject
{
    Q_OBJECT
public:
    PluginManager(QObject *parent = nullptr);
    ~PluginManager();

    void loadPlugin(QString pluginPath);
    void unloadPlugin(QString pluginPath);
    void unloadAllPlugins();
    std::vector<IPlugin*> getPlugins();
    IPlugin* getPlugin(QString name);
    void setPluginUI(QWidget* ui);
    QWidget* getPluginUI();
    void setPluginEnabled(QString name, bool enabled);
    bool isPluginEnabled(QString name);
    void setPluginVisible(QString name, bool visible);
    bool isPluginVisible(QString name);
    void setPluginSelected(QString name, bool selected);
    bool isPluginSelected(QString name);
    void setPluginColor(QString name, QColor color);
    QColor getPluginColor(QString name);
    void setPluginPen(QString name, QPen pen);
    QPen getPluginPen(QString name);
    void setPluginBrush(QString name, QBrush brush);
    QBrush getPluginBrush(QString name);
    void setPluginZValue(QString name, qreal z);
    qreal getPluginZValue(QString name);
    void setPluginTransform(QString name, QTransform transform);
    QTransform getPluginTransform(QString name);
    void setPluginPos(QString name, QPointF pos);
    QPointF getPluginPos(QString name);
    void setPluginRotation(QString name, qreal angle);
    qreal getPluginRotation(QString name);
    void setPluginScale(QString name, qreal sx, qreal sy);
    QPointF getPluginScale(QString name);
    void setPluginShear(QString name, qreal sh, qreal sv);
    QPointF getPluginShear(QString name);
    void setPluginTranslation(QString name, qreal dx, qreal dy);
    QPointF getPluginTranslation(QString name);
    void setPluginMatrix(QString name, QMatrix matrix);
    QMatrix getPluginMatrix(QString name);
    void setPluginItemTransform(QString name, QGraphicsTransform* transform);
    QGraphicsTransform* getPluginItemTransform(QString name);
    void setPluginItemFlags(QString name, QGraphicsItem::GraphicsItemFlags flags);
    QGraphicsItem::GraphicsItemFlags getPluginItemFlags(QString name);
    void setPluginItemCacheMode(QString name, QGraphicsItem::CacheMode mode);
    QGraphicsItem::CacheMode getPluginItemCacheMode(QString name);
    void setPluginItemBoundingRegionGranularity(QString name, qreal granularity);
    qreal getPluginItemBoundingRegionGranularity(QString name);
    void setPluginItemAcceptDrops(QString name, bool on);
    bool getPluginItemAcceptDrops(QString name);
    void setPluginItemAcceptHoverEvents(QString name, bool on);
    bool getPluginItemAcceptHoverEvents(QString name);
    void setPluginItemAcceptTouchEvents(QString name, bool on);
    bool getPluginItemAcceptTouchEvents(QString name);
    void setPluginItemAcceptsHoverEvents(QString name, bool on);
    bool getPluginItemAcceptsHoverEvents(QString name);
    void setPluginItemAcceptsTouchEvents(QString name, bool on);
    bool getPluginItemAcceptsTouchEvents(QString name);
    void setPluginItemAcceptsDrops(QString name, bool on);
    bool getPluginItemAcceptsDrops(QString name);
    void setPluginItemAcceptsHover(QString name, bool on);
    bool getPluginItemAcceptsHover(QString name);
    void setPluginItemAcceptsTouch(QString name, bool on);
    bool getPluginItemAcceptsTouch(QString name);
    void setPluginItemAcceptsDrop(QString name, bool on);
    bool getPluginItemAcceptsDrop(QString name);

signals:
    void pluginLoaded(QString name);
    void pluginUnloaded(QString name);
    void pluginEnabled(QString name, bool enabled);
    void pluginVisible(QString name, bool visible);
    void pluginSelected(QString name, bool selected);
    void pluginColorChanged(QString name, QColor color);
    void pluginPenChanged(QString name, QPen pen);
    void pluginBrushChanged(QString name, QBrush brush);
    void pluginZValueChanged(QString name, qreal z);
    void pluginTransformChanged(QString name, QTransform transform);
    void pluginPosChanged(QString name, QPointF pos);
    void pluginRotationChanged(QString name, qreal angle);
    void pluginScaleChanged(QString name, QPointF scale);
    void pluginShearChanged(QString name, QPointF shear);
    void pluginTranslationChanged(QString name, QPointF translation);
    void pluginMatrixChanged(QString name, QMatrix matrix);
    void pluginItemTransformChanged(QString name, QGraphicsTransform* transform);
    void pluginItemFlagsChanged(QString name, QGraphicsItem::GraphicsItemFlags flags);
    void pluginItemCacheModeChanged(QString name, QGraphicsItem::CacheMode mode);
    void pluginItemBoundingRegionGranularityChanged(QString name, qreal granularity);
    void pluginItemAcceptDropsChanged(QString name, bool on);
    void pluginItemAcceptHoverEventsChanged(QString name, bool on);
    void pluginItemAcceptTouchEventsChanged(QString name, bool on);
    void pluginItemAcceptsHoverEventsChanged(QString name, bool on);
    void pluginItemAcceptsTouchEventsChanged(QString name, bool on);
    void pluginItemAcceptsDropsChanged(QString name, bool on);
    void pluginItemAcceptsHoverChanged(QString name, bool on);
    void pluginItemAcceptsTouchChanged(QString name, bool on);
    void pluginItemAcceptsDropChanged(QString name, bool on);

private:
    std::vector<IPlugin*> plugins;
    std::map<QString, QWidget*> pluginUIs;
    std::map<QString, bool> pluginEnabled;
    std::map<QString, bool> pluginVisible;
    std::map<QString, bool> pluginSelected;
    std::map<QString, QColor> pluginColor;
    std::map<QString, QPen> pluginPen;
    std::map<QString, QBrush> pluginBrush;
    std::map<QString, qreal> pluginZValue;
    std::map<QString, QTransform> pluginTransform;
    std::map<QString, QPointF> pluginPos;
    std::map<QString, qreal> pluginRotation;
    std::map<QString, QPointF> pluginScale;
    std::map<QString, QPointF> pluginShear;
    std::map<QString, QPointF> pluginTranslation;
    std::map<QString, QMatrix> pluginMatrix;
    std::map<QString, QGraphicsTransform*> pluginItemTransform;
    std::map<QString, QGraphicsItem::GraphicsItemFlags> pluginItemFlags;
    std::map<QString, QGraphicsItem::CacheMode> pluginItemCacheMode;
    std::map<QString, qreal> pluginItemBoundingRegionGranularity;
    std::map<QString, bool> pluginItemAcceptDrops;
    std::map<QString, bool> pluginItemAcceptHoverEvents;
    std::map<QString, bool> pluginItemAcceptTouchEvents;
    std::map<QString, bool> pluginItemAcceptsHoverEvents;
    std::map<QString, bool> pluginItemAcceptsTouchEvents;
    std::map<QString, bool> pluginItemAcceptsDrops;
    std::map<QString, bool> pluginItemAcceptsHover;
    std::map<QString, bool> pluginItemAcceptsTouch;
    std::map<QString, bool> pluginItemAcceptsDrop;
};

#endif

