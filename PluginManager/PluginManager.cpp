/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: PluginManager.cpp

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

#include "include/PluginManager.h"
#include "PluginUI/ParameterListWidget.h"
#include <QApplication>
#include <QDir>
#include <QPluginLoader>

using namespace std;

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
}

PluginManager::~PluginManager()
{
    unloadAllPlugins();
}

void PluginManager::loadPlugin(QString pluginPath)
{
    QPluginLoader loader(pluginPath);
    QObject *plugin = loader.instance();
    
    if (plugin)
    {
        IPlugin *p = qobject_cast<IPlugin *>(plugin);
        if (p)
        {
            plugins.push_back(p);
            QString name = QString::fromStdString(p->getName());
            m_pluginEnabled[name] = true;
            m_pluginVisible[name] = true;
            m_pluginSelected[name] = false;
            emit pluginLoaded(name);
            qInfo().noquote().nospace() << "Plugin " << name << " loaded.";
        }
    }
}

void PluginManager::unloadPlugin(QString pluginPath)
{
    for (auto it = plugins.begin(); it != plugins.end(); ++it)
    {
        QString name = QString::fromStdString((*it)->getName());
        if (name == pluginPath)
        {
            plugins.erase(it);
            m_pluginEnabled.erase(name);
            m_pluginVisible.erase(name);
            m_pluginSelected.erase(name);
            emit pluginUnloaded(name);
            break;
        }
    }
}

void PluginManager::unloadAllPlugins()
{
    for (auto plugin : plugins)
    {
        QString name = QString::fromStdString(plugin->getName());
        emit pluginUnloaded(name);
    }
    plugins.clear();
    m_pluginEnabled.clear();
    m_pluginVisible.clear();
    m_pluginSelected.clear();
}

std::vector<IPlugin*> PluginManager::getPlugins()
{
    return plugins;
}

IPlugin* PluginManager::getPlugin(QString name)
{
    for (auto plugin : plugins)
    {
        if (QString::fromStdString(plugin->getName()) == name)
            return plugin;
    }
    return nullptr;
}

void PluginManager::setPluginUI(QWidget* ui)
{
    if (ui)
    {
        QString name = ui->objectName();
        pluginUIs[name] = ui;
    }
}

QWidget* PluginManager::getPluginUI()
{
    if (pluginUIs.empty())
        return nullptr;
    return pluginUIs.begin()->second;
}

void PluginManager::setPluginEnabled(QString name, bool enabled)
{
    m_pluginEnabled[name] = enabled;
    emit pluginEnabled(name, enabled);
}

bool PluginManager::isPluginEnabled(QString name)
{
    return m_pluginEnabled[name];
}

void PluginManager::setPluginVisible(QString name, bool visible)
{
    m_pluginVisible[name] = visible;
    emit pluginVisible(name, visible);
}

bool PluginManager::isPluginVisible(QString name)
{
    return m_pluginVisible[name];
}

void PluginManager::setPluginSelected(QString name, bool selected)
{
    m_pluginSelected[name] = selected;
    emit pluginSelected(name, selected);
}

bool PluginManager::isPluginSelected(QString name)
{
    return m_pluginSelected[name];
}
