#ifndef WIDGETPLUGINLOADER_H
#define WIDGETPLUGINLOADER_H

#include "loader/apluginloader.h"
#include "pluginbases/WidgetBase.h"

class WidgetPluginLoader : public APluginLoader
{
public:
   explicit WidgetPluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName);

    // APluginLoader interface
public:
    WidgetBase *getPluginFromName(QString pName);
};

#endif // WIDGETPLUGINLOADER_H
