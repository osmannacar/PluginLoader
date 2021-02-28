#ifndef APLUGINLOADER_H
#define APLUGINLOADER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QDebug>
#include "pluginbases/Base.h"
#include "derivedfactoryloader.h"


class APluginLoader
{
public:
    explicit APluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName);
    ~APluginLoader();
    bool loadPlugins();

    virtual Base *getPluginFromName(QString pName) = 0;

private:
    QVector<QString> readPluginNameFromContainerFile();
    void clear();

private:
    QString mPluginFolderPath;
    QString mPluginContainerFileName;
protected:
    QMap<QString, DerivedFactoryLoader *> mFactoryOfPlugins;
};


#endif // APLUGINLOADER_H
