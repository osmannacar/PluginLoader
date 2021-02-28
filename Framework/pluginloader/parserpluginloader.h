#ifndef PARSERPLUGINLOADER_H
#define PARSERPLUGINLOADER_H

#include "loader/apluginloader.h"
#include "pluginbases/ParserBase.h"

class ParserPluginLoader : public APluginLoader
{
public:
    explicit ParserPluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName);

    // APluginLoader interface
public:
    ParserBase *getPluginFromName(QString pName);
};

#endif // PARSERPLUGINLOADER_H
