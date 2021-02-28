#ifndef BASE_H
#define BASE_H

class Base
{
public:
};

using Base_creator_t = Base *(*)();

#define IMPORT_PLUGIN(derived_class) \
    extern "C" { \
    Base * create() { \
    return new derived_class; \
    } \
    } \

#endif // BASE_H
