#ifndef WIND_NONE_H
#define WIND_NONE_H

#include "WindObject.h"

// The None type class
class WindNone : public WindObject
{
public:
WindNone()
{
        setType(WindObject::Type_None);
}
~WindNone()
{
}

void debugInfo(void) const
{
        std::cout << "Object:{type = Type_None}\n";
}

void print(void) const
{
        std::cout << "None";
}

static WindNone* create(int amount = 1)
{
        return new WindNone[amount];
}

};

#endif
