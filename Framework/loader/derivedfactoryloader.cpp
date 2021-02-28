#include "derivedfactoryloader.h"
#include <QDebug>

DerivedFactoryLoader::DerivedFactoryLoader(QString pPluginPath)
    : mPluginPath(pPluginPath)
    , handler(nullptr)
    , creator(nullptr)
{

}

DerivedFactoryLoader::~DerivedFactoryLoader() {
    if (handler) {
        dlclose(handler);
    }
}

bool DerivedFactoryLoader::load()
{
    if(handler){
        qDebug() << "PluginLoader::load plugin has been loaded";
        return false;
    }
    handler = dlopen(mPluginPath.toStdString().c_str(), RTLD_NOW);
    if (!handler) {
          qDebug() << "DerivedFactoryLoader::load " << dlerror();
          return false;
    }
    resetDLError();
    creator = reinterpret_cast<Base_creator_t>(dlsym(handler, "create"));
    checkDLError();

    if(creator == nullptr){
        qDebug() << "PluginLoader::load plugin not loaded";
        return false;
    }
    return true;
}

Base *DerivedFactoryLoader::create() const {
    if(!handler){
        return nullptr;
    }
    return creator();
}

void DerivedFactoryLoader::resetDLError() {
    dlerror();
}

void DerivedFactoryLoader::checkDLError() {
    const char * dlsym_error = dlerror();
    if (dlsym_error) {
        qDebug() << "DerivedFactoryLoader::checkDLError " << dlsym_error;
    }
}
