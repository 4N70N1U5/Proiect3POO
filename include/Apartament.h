#ifndef Apartament_H
#define Apartament_H

#include "Locuinta.h"

class Apartament: public Locuinta
{
public:
    Apartament();
    Apartament(std::string, int, double, int);
    Apartament(const Apartament&);
    ~Apartament();

    void operator=(const Apartament&);

    friend std::istream& operator>>(std::istream&, Apartament&);
    friend std::ostream& operator<<(std::ostream&, const Apartament&);

    double CalculChirie(int);
private:
    int etaj;
};

std::istream& operator>>(std::istream&, Apartament&);
std::ostream& operator<<(std::ostream&, const Apartament&);

#endif
