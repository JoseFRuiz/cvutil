#include "PluginManager.h"
#include "PluginInterfaces.h"
#include <QtWidgets/QWidget>
#include <vector>
#include <string>

PluginManager* PluginManager::GetInstance()
{
    static PluginManager instance;
    return &instance;
}

std::vector<QWidget*> PluginManager::GetPluginUIs()
{
    std::vector<QWidget*> uis;
    for (const auto& pair : pluginUIs) {
        uis.push_back(pair.second);
    }
    return uis;
}

std::vector<IPlugin*> PluginManager::GetPlugins()
{
    return plugins;
}

std::vector<QString> PluginManager::ListNames()
{
    std::vector<QString> names;
    for (const auto& plugin : plugins) {
        names.push_back(plugin->getName());
    }
    return names;
}

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
}

PluginManager::~PluginManager()
{
    unloadAllPlugins();
}

void PluginManager::loadPlugin(QString pluginPath)
{
    // Implementation needed
}

void PluginManager::unloadPlugin(QString pluginPath)
{
    // Implementation needed
}

void PluginManager::unloadAllPlugins()
{
    for (auto plugin : plugins) {
        if (plugin) {
            delete plugin;
        }
    }
    plugins.clear();
    pluginUIs.clear();
}

IPlugin* PluginManager::getPlugin(QString name)
{
    for (auto plugin : plugins) {
        if (plugin->getName() == name) {
            return plugin;
        }
    }
    return nullptr;
}

void PluginManager::setPluginUI(QWidget* ui)
{
    if (ui) {
        pluginUIs[ui->objectName()] = ui;
    }
}

QWidget* PluginManager::getPluginUI()
{
    if (!pluginUIs.empty()) {
        return pluginUIs.begin()->second;
    }
    return nullptr;
} 