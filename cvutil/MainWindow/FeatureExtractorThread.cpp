/*
Copyright (C) 2021, Anand Seethepalli and Larry York
Copyright (C) 2020, Courtesy of Noble Research Institute, LLC

File: FeatureExtractorThread.cpp

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

#include "FeatureExtractorThread.h"
#include "../../PluginManager/include/PluginManager.h"

//#include <ImageProcessor.h>
#include "../cvutil_core.h"

using namespace std;
using namespace cv;

FeatureExtractorThread::FeatureExtractorThread(QObject *parent) : QThread(parent)
{
    moveToThread(this);
    reset();
}

void FeatureExtractorThread::reset()
{
    fileidx = 0;
}

void FeatureExtractorThread::setfilelist(vector<QString> flist)
{
    filelist = flist;
}

void FeatureExtractorThread::setsavelocation(QString location)
{
    saveloc = location;
}

void FeatureExtractorThread::setMainPlugin(IPlugin *p)
{
    mainplugin = p;
}

// We wanted to implement our own "finished"
// functionality than using the isFinished()
// because the thread we implemented is 
// pausable. The function below returns false
// when the thread is stopped due to a pause
// action.
bool FeatureExtractorThread::isfinished()
{
    return workfinished;
}

void FeatureExtractorThread::run()
{
    workfinished = false;
    Mat inp, out;
    IPlugin *plugin;

    auto pluginManager = PluginManager::GetInstance();
    auto plugins = pluginManager->GetPlugins();
    if (plugins.size() > 0) {
        auto plugin = plugins[plugin_index];
        mainplugin = plugin;
    }

    if (mainplugin->getOutputType() == OutputType::ImageAndValues ||
        mainplugin->getOutputType() == OutputType::ImagesAndValues)
        mainplugin->writeHeader(saveloc);

    for (; fileidx < filelist.size(); fileidx++)
    {
        if (isInterruptionRequested())
            return;
        
        emit ReportProgress(filelist[fileidx], fileidx);

        QFileInfo finfo(filelist[fileidx]);

        //qDebug() << "DEBUG :: " << filelist[fileidx];
        inp = cvutil::imread(filelist[fileidx]);
        if (inp.channels() == 3)
            cvtColor(inp, inp, COLOR_BGR2RGB);

        mainplugin->setImage(inp, finfo.fileName());
        mainplugin->execute();
        mainplugin->saveOutput(saveloc, filelist[fileidx]);

        //pfunc(&config, features);
    }

    workfinished = true;
}

