#ifndef PARSERBASE_H
#define PARSERBASE_H
#include "Base.h"
class ParserBase : public Base
{
public:
    virtual int data() const = 0;
    virtual void setData(int data) = 0;
};

#endif // PARSERBASE_H
