#include "../include/AgentieImobiliara.h"
// #include "../include/Locuinta.h"
// #include "../include/Apartament.h"
// #include "../include/Casa.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void Clear()
{
    #if defined _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} // Multumim, Stack Overflow

// void Exemplificari()
// {
//     // Aici voi exemplifica functionalitatea tuturor constructorilor si operatorilor pe care nu i am folosit in programul efectiv.
//     // Mai exact, constructorul de copiere pentru Apartament si Casa si constructorii parametrizat si de copiere si
//     // operatorul = pentru AgentieImobiliara.

//     std::cout << "Exemplificari pentru:\n";
//     std::cout << "- Constructorii de copiere ai claselor\n";
//     std::cout << "  Apartament si Casa\n";
//     std::cout << "- Constructorul parametrizat al clasei AgentieImobiliara\n";
//     std::cout << "- Constructorul de copiere al clasei AgentieImobiliara\n";
//     std::cout << "- Operatorul = pentru AgentieImobiliara\n";

//     std::cout << '\n';

//     Apartament A1("Carmen", 90, 10, 1);
//     Apartament A2(A1);

//     std::cout << "Apartamentul A1:\n" << A1 << "\nApartamentul A2, copiat din A1:\n" << A2 << '\n';

//     Casa C1("Sebi", 300, 10, 150);
//     Casa C2(C1);

//     std::cout << "Casa C1:\n" << C1 << "\nCasa C2, copiata din C1:\n" << C2 << '\n';

//     std::vector<Locuinta*> listaLocuinte;
//     listaLocuinte.push_back(new Apartament("Daniel", 70, 5, 3));
//     listaLocuinte.push_back(new Casa("Lidia", 350, 15, 200));

//     AgentieImobiliara AI1(listaLocuinte);
//     AgentieImobiliara AI2(AI1);
//     AgentieImobiliara AI3 = AI1;

//     std::cout << "Agentia AI1, construita folosind constructorul parametrizat:\n" << AI1;
//     std::cout << "Agentia AI2, copiata din AI1 folosind constructorul de copiere:\n" << AI2;
//     std::cout << "Agentia AI3, copiata din AI1 folosind operatorul =:\n" << AI3;

//     std::cout << "Apasa enter pentru a continua.\n";
//     std::cin.get();
// }

void AfisareOptiuni()
{
    std::cout << "Te rog alege o optiune:\n";
    
    std::cout << "Optiunea 1: Adauga o locuinta.\n";
    std::cout << "Optiunea 2: Afiseaza locuintele.\n";
    std::cout << "Optiunea 3: Afiseaza apartamentele.\n";
    std::cout << "Optiunea 4: Afiseaza casele.\n";
    std::cout << "Optiunea 5: Modifica o locuinta.\n";
    std::cout << "Optiunea 6: Sterge o locuinta.\n";
    std::cout << "Optiunea 7: Calculeaza si afiseaza chiria pentru o locuinta.\n";
    std::cout << "Optiunea 0: Inchide programul.\n";
    
    std::cout << "Optiunea aleasa: ";
}

void Meniu()
{
    bool exitProgram = false;
    std::string input;
    AgentieImobiliara AI;

    while (exitProgram == false)
    {
        SkipSleep:
        Clear();
        AfisareOptiuni();

        try
        {
            std::cin >> input;
            std::cin.get();

            if (input == "1")
            {
                Clear();
                std::cout << "Ai ales 1: Adauga o locuinta.\n\n";
                
                std::cin >> AI;
            }
            else if (input == "2")
            {
                Clear();
                std::cout << "Ai ales 2: Afiseaza locuintele.\n\n";
                
                std::cout << AI;
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "3")
            {
                Clear();
                std::cout << "Ai ales 3: Afiseaza apartamentele.\n\n";
                
                AI.AfisareApartamente();
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "4")
            {
                Clear();
                std::cout << "Ai ales 4: Afiseaza casele.\n\n";
                
                AI.AfisareCase();
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "5")
            {
                Clear();
                std::cout << "Ai ales 5: Modifica o locuinta.\n\n";
                
                AI.ModificareLocuinta();
            }
            else if (input == "6")
            {
                Clear();
                std::cout << "Ai ales 6: Sterge o locuinta.\n\n";

                AI.StergereLocuinta();
            }
            else if (input == "7")
            {
                Clear();
                std::cout << "Ai ales 7: Calculeaza si afiseaza chiria pentru o locuinta.\n\n";
                
                AI.CalculChirie();
            }
            else if (input == "0")
            {
                Clear();
                std::cout << "Ai ales 0: Inchide programul.\n\n";
                std::cout << "Programul se va inchide.\n";
                
                exitProgram = true;
            }
            else
            {
                throw "Optiune invalida. Te rog incearca din nou!\n";
            }
        }
        catch (const char* err)
        {
            std::cout << err;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(2048));
    }
}

int main()
{
    Clear();
    
    // Exemplificari();
    // Clear();
    
    Locuinta::setValStandard();
    Clear();
    
    Meniu();
    Clear();

    return 0;
}

// Repository de locuinte - AgentieImobiliara mosteneste repository-ul.
// => template + primul design pattern
// DONE
// 
// Factory de locuinte - Imi returneaza ori new Apartament() ori new Casa()
// => al doilea design pattern
// DONE
