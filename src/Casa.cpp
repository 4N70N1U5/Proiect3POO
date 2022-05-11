#include "../include/Casa.h"

#include <iostream>
#include <string>

Casa::Casa(): Locuinta()
{
    this->suprafataCurte = 0;
}

Casa::Casa(std::string numeClient, int suprafataUtila, double discount, int suprafataCurte): 
Locuinta(numeClient, suprafataUtila, discount)
{
    this->suprafataCurte = suprafataCurte;
}

Casa::Casa(const Casa& C): Locuinta(C)
{
    this->suprafataCurte = C.suprafataCurte;
}

Casa::~Casa()
{
    
}

void Casa::operator=(const Casa& C)
{
    const Locuinta& L = C;
    this->Locuinta::operator=(L);

    this->suprafataCurte = C.suprafataCurte;
}

std::istream& operator>>(std::istream& i, Casa& C)
{
    Locuinta& L = C;

    i >> L;

    std::cout << "Suprafata curtii: ";
    i >> C.suprafataCurte;

    return i;
}

std::ostream& operator<<(std::ostream& o, const Casa& C)
{
    const Locuinta& L = C;
    
    o << L;
    
    o << "Suprafata curtii: " << C.suprafataCurte << "\n";
    
    return o;
}

double Casa::CalculChirie(int aplicareDiscount)
{
    return valoareStandard * (suprafataUtila + 0.2 * suprafataCurte) * (1 - aplicareDiscount * discount / 100.0);
}
