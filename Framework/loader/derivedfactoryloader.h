#ifndef DERIVEDFACTORYLOADER_H
#define DERIVEDFACTORYLOADER_H

#include <QString>
#include <dlfcn.h>
#include "pluginbases/Base.h"

class DerivedFactoryLoader {
public:
    explicit DerivedFactoryLoader(QString pPluginPath);
    ~DerivedFactoryLoader();

    bool load();
    Base* create() const;

private:
    static void resetDLError();
    static void checkDLError();
private:
    void *handler;
    Base_creator_t creator;
    QString mPluginPath;

};

#endif // DERIVEDFACTORYLOADER_H
