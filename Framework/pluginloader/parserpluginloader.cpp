#include "parserpluginloader.h"

ParserPluginLoader::ParserPluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName)
    : APluginLoader(pPluginFolderPath, pPluginContainerFileName)
{

}

ParserBase *ParserPluginLoader::getPluginFromName(QString pName)
{
    if(!mFactoryOfPlugins.contains(pName)){
        return nullptr;
    }
    return (ParserBase *)mFactoryOfPlugins[pName]->create();
}
