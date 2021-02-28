#include "apluginloader.h"

#include <QDir>

APluginLoader::APluginLoader(QString pPluginFolderPath, QString pPluginContainerFileName)
    : mPluginFolderPath(pPluginFolderPath)
    , mPluginContainerFileName(pPluginContainerFileName)
{

}

APluginLoader::~APluginLoader(){
    clear();
}

bool APluginLoader::loadPlugins(){

    clear();

    QVector<QString> pluginNames = readPluginNameFromContainerFile();
    if(pluginNames.size() == 0){
        qDebug() << "WidgetPluginLoader::loadPlugins pluginNames.size == 0";
        return false;
    }

    for (int i = 0; i < pluginNames.size(); ++i) {
        QString pluginPath = mPluginFolderPath + "/" + mPluginContainerFileName + "/" + pluginNames.at(i);
#ifdef __linux__
        pluginPath.append(".so");
#elif _WIN32
        // windows code goes here
        pluginPath.append(".dll");
#endif
        DerivedFactoryLoader *pluginLoader = new DerivedFactoryLoader(pluginPath);
        if(pluginLoader->load()){
            mFactoryOfPlugins.insert(pluginNames.at(i), pluginLoader);
        }else {
            delete pluginLoader;
        }

    }


    return true;
}

QVector<QString> APluginLoader::readPluginNameFromContainerFile(){

    QVector<QString> pluginNames;
    QDir pluginFolder = QDir(mPluginFolderPath);
    if(!pluginFolder.exists()){
        qDebug() << "WidgetPluginLoader::readPluginNameFromContainerFile plugin folder not found";
        return pluginNames;
    }

    QFile file(mPluginFolderPath + "/" + mPluginContainerFileName + ".txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "WidgetPluginLoader::readPluginNameFromContainerFile error opening file: " << file.error();
        return pluginNames;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()){
        QString pluginName = stream.readLine();
        if(!pluginName.isEmpty())
            pluginNames.append(pluginName);
    }
    file.close();

    return pluginNames;
}

void APluginLoader::clear(){
    qDeleteAll(mFactoryOfPlugins);
    mFactoryOfPlugins.clear();
}
