#ifndef LocuintaFactory_H
#define LocuintaFactory_H

#include "Locuinta.h"

#include <string>

class LocuintaFactory
{
public:
    static Locuinta* ConstruiesteLocuinta(std::string);
    static Locuinta* ConstruiesteLocuinta(std::string, std::string, int, double, int);
};

#endif
