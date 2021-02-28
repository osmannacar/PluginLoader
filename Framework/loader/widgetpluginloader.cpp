#include "widgetpluginloader.h"

WidgetPluginLoader::WidgetPluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName)
    : APluginLoader(pPluginFolderPath, pPluginContainerFileName)
{

}

WidgetBase *WidgetPluginLoader::getPluginFromName(QString pName)
{
    if(!mFactoryOfPlugins.contains(pName)){
        return nullptr;
    }
    return (WidgetBase *)mFactoryOfPlugins[pName]->create();
}
