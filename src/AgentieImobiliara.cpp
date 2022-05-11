#include "../include/AgentieImobiliara.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

AgentieImobiliara::AgentieImobiliara()
{
    // Initial am adaugat cateva locuinte in agentia imobiliara folosind constructorul pentru
    // a-mi fi mai usor sa testez, dar am decis sa le pastrez si in varianta finala.
    // De aceea, exista deja aceste patru locuinte in agentie inca de la inceput.
    this->locuinte.push_back(new Apartament("Carmen", 90, 10, 1));
    this->locuinte.push_back(new Apartament("Daniel", 70, 5, 3));
    this->locuinte.push_back(new Casa("Sebi", 300, 10, 150));
    this->locuinte.push_back(new Casa("Lidia", 350, 15, 200));
}

AgentieImobiliara::AgentieImobiliara(std::vector<Locuinta*> locuinte)
{
    this->locuinte = locuinte;
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara& AI)
{
    this->locuinte = AI.locuinte;
}

AgentieImobiliara::~AgentieImobiliara()
{
    this->locuinte.clear();
}

void AgentieImobiliara::operator=(const AgentieImobiliara& AI)
{
    this->locuinte = AI.locuinte;
}

std::istream& operator>>(std::istream& i, AgentieImobiliara& AI)
{
    using namespace std;
    {
        string tip;

        CitireTip:
        cout << "Tip locuinta (Apartament sau Casa): ";
        getline(i, tip);
        transform(tip.begin(), tip.end(), tip.begin(), ::tolower);

        cout << '\n';
        
        if (tip == "apartament")
        {
            cout << "A fost selectat apartament.\n\n";
            Apartament* A = new Apartament();
            i >> *A;
            AI.locuinte.push_back(A);
        }
        else if (tip == "casa")
        {
            cout << "A fost selectata casa.\n\n";
            Casa* C = new Casa();
            i >> *C;
            AI.locuinte.push_back(C);
        }
        else
        {
            cout << "Va rog repetati selectia.\n";
            goto CitireTip;
        }

        cout << '\n';

        cout << "Locuinta a fost adaugata.\n";
    } // namespace std
    
    return i;
}

std::ostream& operator<<(std::ostream& o, const AgentieImobiliara& AI)
{
    for (int i = 0; i < AI.locuinte.size(); i++)
    {
        o << "Locuinta " << i + 1 << ":\n";
        if (dynamic_cast<Apartament*>(AI.locuinte[i]))
        {
            Apartament* A = dynamic_cast<Apartament*>(AI.locuinte[i]);
            o << *A << '\n';
        }
        else if (dynamic_cast<Casa*>(AI.locuinte[i]))
        {
            Casa* C = dynamic_cast<Casa*>(AI.locuinte[i]);
            o << *C << '\n';
        }
    }

    return o;
}

void AgentieImobiliara::AfisareApartamente()
{
    int indice = 1;

    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Apartament* A = dynamic_cast<Apartament*>(this->locuinte[i]);
        if (A != NULL)
        {
            std::cout << "Apartamentul " << indice << ":\n";
            std::cout << *A << '\n';
            indice++;
        }
    }
}

void AgentieImobiliara::AfisareCase()
{
    int indice = 1;

    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Casa* C = dynamic_cast<Casa*>(this->locuinte[i]);
        if (C != NULL)
        {
            std::cout << "Casa " << indice << ":\n";
            std::cout << *C << '\n';
            indice++;
        }
    }
}

void AgentieImobiliara::ModificareLocuinta()
{
    std::cout << *this;
    std::cout << "Alege locuinta pe care vrei sa o modifici: ";

    int i;

    std::cin >> i;
    std::cin.get();

    i--; // Pentru ca locuintele sunt afisate cu index incepand de la 1, dar in vector incep de la 0.

    std::cout << '\n';

    try
    {
        this->locuinte.at(i); 
        // Pentru a arunca exceptia de tip out_of_range in caz ca indicele citit nu este ok.

        if (dynamic_cast<Apartament*>(this->locuinte[i]))
        {
            std::cout << "Modifici apartamentul de pe pozitia " << i + 1 << ".\n\n";

            Apartament A;
            std::cin >> A;

            Apartament* aux = dynamic_cast<Apartament*>(this->locuinte[i]);

            *aux = A;
        }
        else if (dynamic_cast<Casa*>(this->locuinte[i]))
        {
            std::cout << "Modifici casa de pe pozitia " << i + 1 << ".\n\n";

            Casa C;
            std::cin >> C;

            Casa* aux = dynamic_cast<Casa*>(this->locuinte[i]);

            *aux = C;
        }

        std::cout << '\n';

        std::cout << "Locuinta a fost modificata.\n";
    }
    catch(const std::out_of_range& err)
    { 
        std::cout << "Locuinta aleasa nu exista. Incearca din nou!\n";
    }
}

void AgentieImobiliara::StergereLocuinta()
{
    std::cout << *this;
    std::cout << "Alege locuinta pe care vrei sa o stergi: ";

    int i;
    std::cin >> i;
    std::cin.get();

    i--;
    
    std::cout << '\n';

    try
    {
        this->locuinte.at(i);
        this->locuinte.erase(this->locuinte.begin() + i);

        std::cout << "Locuinta a fost stearsa.\n";
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Locuinta aleasa nu exista. Incearca din nou!\n";
    }
}

void AgentieImobiliara::CalculChirie()
{
    std::cout << *this;
    std::cout << "Alege locuinta pentru care vrei sa calculezi chiria: ";

    int i, aplicareDiscount;

    std::cin >> i;
    std::cin.get();

    i--;

    std::cout << '\n';

    try
    {
        this->locuinte.at(i);
    }
    catch(const std::out_of_range& err)
    {
        std::cout << "Locuinta aleasa nu exista. Incearca din nou!\n";
        return;
    }

    CitireDiscount:
    std::cout << "Doresti sa aplici discountul? (DA / NU)\n";

    std::string raspuns;

    std::getline(std::cin, raspuns);

    std::transform(raspuns.begin(), raspuns.end(), raspuns.begin(), ::tolower);

    std::cout << '\n';

    if (raspuns == "da" || raspuns == "d")
    {
        aplicareDiscount = 1;
    }
    else if (raspuns == "nu" || raspuns == "n")
    {
        aplicareDiscount = 0;
    }
    else
    {
        std::cout << "Raspuns invalid.\n";
        goto CitireDiscount;
    }

    if (dynamic_cast<Apartament*>(this->locuinte[i]))
    {
        Apartament* A = dynamic_cast<Apartament*>(this->locuinte[i]);

        std::cout << "Chiria pentru apartamentul de pe pozitia " << i + 1 << ": " << A->CalculChirie(aplicareDiscount) << '\n';
    }
    else if (dynamic_cast<Casa*>(this->locuinte[i]))
    {
        Casa* C = dynamic_cast<Casa*>(this->locuinte[i]);

        std::cout << "Chiria pentru casa de pe pozitia " << i + 1 << ": " << C->CalculChirie(aplicareDiscount) << '\n';
    }
}
