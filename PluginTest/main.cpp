#include <QApplication>
#include "pluginloader/parserpluginloader.h"
#include "pluginloader/widgetpluginloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString parserplugins  = "parserplugins";
    QString widgetplugins = "widgetplugins";

    QString pathOfPluginsFolder = "home/oscar/Desktop/Proje/Plugin/Plugins";

    ParserPluginLoader *parserPluginLoader = new ParserPluginLoader(pathOfPluginsFolder, parserplugins);
    if(parserPluginLoader->loadPlugins()){
        ParserBase *parserBase = parserPluginLoader->getPluginFromName("ParserPlugin");
        if(parserBase != nullptr){
            parserBase->setData(5);
            qDebug() << "getter:" << parserBase->data();
        }
    }


    WidgetPluginLoader *widgetPluginLoader = new WidgetPluginLoader(pathOfPluginsFolder, widgetplugins);
    if(widgetPluginLoader->loadPlugins()){
        WidgetBase *widgetBase = widgetPluginLoader->getPluginFromName("WidgetPlugin");
        if(widgetBase != nullptr){
            widgetBase->show();
        }
        WidgetBase *widgetBase2 = widgetPluginLoader->getPluginFromName("WidgetPlugin2");
        if(widgetBase2 != nullptr){
            widgetBase2->show();
        }
    }

    return a.exec();
}
