#pragma once

#ifndef PLUGINAPI_H
#define PLUGINAPI_H

#ifdef WIN32
#if (!defined PLUGINAPI)
#if (defined PLUGINMANAGER_SOURCE || defined ROIMANAGER_SOURCE)
#define PLUGINAPI __declspec(dllexport)
#else
#define PLUGINAPI __declspec(dllimport)
#endif
#endif
#else
#define PLUGINAPI
#endif

#endif // PLUGINAPI_H 