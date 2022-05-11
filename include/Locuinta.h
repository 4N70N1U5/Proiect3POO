#ifndef Locuinta_H
#define Locuinta_H

#include <iostream>
#include <string>

class Locuinta
{
public:
    Locuinta();
    Locuinta(std::string, int, double);
    Locuinta(const Locuinta&);
    ~Locuinta();

    static void setValStandard();

    void operator=(const Locuinta&);
    
    friend std::istream& operator>>(std::istream&, Locuinta&);
    friend std::ostream& operator<<(std::ostream&, const Locuinta&);

    virtual double CalculChirie(int) = 0;
protected:
    static int valoareStandard;
    std::string numeClient;
    int suprafataUtila;
    double discount;
};

std::istream& operator>>(std::istream&, Locuinta&);
std::ostream& operator<<(std::ostream&, const Locuinta&);

#endif
