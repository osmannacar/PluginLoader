#include "pluginbases/ParserBase.h"

class Parse : public ParserBase
{
public:
    Parse() {}

    // Base interface
public:
    int data() const override{
        return mData;
    }
    void setData(int data) override{
        mData = data;
    }

private:
    int mData;
};

IMPORT_PLUGIN(Parse)
