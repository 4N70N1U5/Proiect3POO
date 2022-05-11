#include "../include/Locuinta.h"

#include <iostream>
#include <string>

int Locuinta::valoareStandard;

Locuinta::Locuinta()
{
    this->numeClient = "";
    this->suprafataUtila = 0;
    this->discount = 0.0;
}

Locuinta::Locuinta(std::string numeClient, int suprafataUtila, double discount)
{
    this->numeClient = numeClient;
    this->suprafataUtila = suprafataUtila;
    this->discount = discount;
}

Locuinta::Locuinta(const Locuinta& L)
{
    this->numeClient = L.numeClient;
    this->suprafataUtila = L.suprafataUtila;
    this->discount = L.discount;
}

Locuinta::~Locuinta()
{
    
}

void Locuinta::setValStandard()
{
    std::cout << "Te rog introdu o suma pentru valoarea standard a chiriei / metru patrat: ";
    std::cin >> valoareStandard;
    std::cin.get();
}

void Locuinta::operator=(const Locuinta& L)
{
    this->numeClient = L.numeClient;
    this->suprafataUtila = L.suprafataUtila;
    this->discount = L.discount;
}

std::istream& operator>>(std::istream& i, Locuinta& L)
{
    std::cout << "Numele clientului: ";
    std::getline(i, L.numeClient);
    std::cout << "Discountul aplicat (procent): ";
    i >> L.discount;
    std::cout << "Suprafata utila: ";
    i >> L.suprafataUtila;

    return i;
}

std::ostream& operator<<(std::ostream& o, const Locuinta& L)
{
    o << "Numele clientului: " << L.numeClient << "\n";
    o << "Discountul aplicat: " << L.discount << "%\n";
    o << "Suprafata utila: " << L.suprafataUtila << "\n";

    return o;
}
