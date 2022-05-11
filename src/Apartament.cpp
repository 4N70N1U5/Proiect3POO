#include "../include/Apartament.h"

#include <iostream>
#include <string>

Apartament::Apartament(): Locuinta()
{
    this->etaj = 0;
}

Apartament::Apartament(std::string numeClient, int suprafataUtila, double discount, int etaj): 
Locuinta(numeClient, suprafataUtila, discount)
{
    this->etaj = etaj;
}

Apartament::Apartament(const Apartament& A): Locuinta(A)
{
    this->etaj = A.etaj;
}

Apartament::~Apartament()
{
    
}

void Apartament::operator=(const Apartament& A)
{
    const Locuinta& L = A;
    this->Locuinta::operator=(L);

    this->etaj = A.etaj;
}

std::istream& operator>>(std::istream& i, Apartament& A)
{
    Locuinta& L = A;

    i >> L;

    std::cout << "Etajul: ";
    i >> A.etaj;

    return i;
}

std::ostream& operator<<(std::ostream& o, const Apartament& A)
{
    const Locuinta& L = A;

    o << L;

    o <<  "Etajul: " << A.etaj << "\n";

    return o;
}

double Apartament::CalculChirie(int aplicareDiscount)
{
    return valoareStandard * suprafataUtila * (1 - aplicareDiscount * discount / 100.0);
}
