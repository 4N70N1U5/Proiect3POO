#include "../include/LocuintaFactory.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <string>

Locuinta* LocuintaFactory::ConstruiesteLocuinta(std::string tip)
{
    transform(tip.begin(), tip.end(), tip.begin(), ::tolower);

    if (tip == "apartament" || tip == "a")
        return new Apartament();
    else if (tip == "casa" || tip == "c")
        return new Casa();
    return NULL;
}

Locuinta* LocuintaFactory::ConstruiesteLocuinta(std::string tip, std::string numeClient, int suprafataUtila, double discount, int wildcard)
{
    transform(tip.begin(), tip.end(), tip.begin(), ::tolower);

    if (tip == "apartament" || tip == "a")
        return new Apartament(numeClient, suprafataUtila, discount, wildcard);
    else if (tip == "casa" || tip == "c")
        return new Casa(numeClient, suprafataUtila, discount, wildcard);
    return NULL;

    // Wildcard-ul va reprezenta etajul pentru apartamente, respectiv suprafata curtii pentru case.
}
