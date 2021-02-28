# PluginLoader
PluginLoader

PluginLoader project load widget and console plugins, if your want to load different class that has different properties, follow these steps;

1)create your own base class and inherit from Framework/pluginbases/Base.h(example: WidgetBase.h)
2)Write your own project or systems and compile as lib(example: Plugin Example/WidgetPlugin)
3)create file and rename as your own plugin system name(example: Plugins/widgetplugins.txt)
4)write plugin names in your own plugin system file(example: Plugins/widgetplugins.txt/WidgetPlugin)
5)Create folder in same directory and rename as plugin system name(example: Plugins/widgetplugins)
6)Put your dll or .so file in folder when we created state 5(Not: rename as .so extentions of your plugins in linux)
7)Inspect main file in project of PluginTest 

