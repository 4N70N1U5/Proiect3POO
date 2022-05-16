#ifndef AgentieImobiliara_H
#define AgentieImobiliara_H

#include "Repository.h"
#include "Locuinta.h"

#include <iostream>
#include <vector>

class AgentieImobiliara: public Repository<Locuinta>
{
public:
    AgentieImobiliara();
    AgentieImobiliara(std::vector<Locuinta*>);
    AgentieImobiliara(const AgentieImobiliara&);
    ~AgentieImobiliara();

    void operator=(const AgentieImobiliara&);

    friend std::istream& operator>>(std::istream&, AgentieImobiliara&);
    friend std::ostream& operator<<(std::ostream&, const AgentieImobiliara&);

    void AfisareApartamente();
    void AfisareCase();
    void ModificareLocuinta();
    void StergereLocuinta();
    void CalculChirie();
private:
    // std::vector<Locuinta*> locuinte;
};

std::istream& operator>>(std::istream&, AgentieImobiliara&);
std::ostream& operator<<(std::ostream&, const AgentieImobiliara&);

#endif
