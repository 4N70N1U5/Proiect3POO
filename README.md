# Proiect3POO

Proiectul 3 se bazeaza pe proiectul 2.

Acest program permite memorarea, afisarea, modificarea si stergerea unor locuinte dintr-o agentie imobiliara, cat si calculul chiriei lunare pentru acestea. Acest lucru este implementat cu ajutorul a patru clase, ```Locuinta```, ```Apartament```, ```Casa``` si ```AgentieImobiliara```.

Clasa ```Locuinta``` este clasa de baza din care sunt derivate clasele ```Apartament``` si ```Casa```. Contine datele comune pentru cele doua tipuri de locuinte, precum numele clientului, suprafata utila si discountul aplicat, cat si valoarea standard a chiriei / metru patrat, care este o data statica, citita la inceputul programului cu ajutorul unei metode statice. Clasele derivate din aceasta o extind cu atribute specifice — etaj pentru apartamente si suprafata curtii pentru case — si redefinesc metodele clasei de baza pentru a se potrivi tipului specific de locuinta. Clasa ```Locuinta``` este de asemenea abstracta, deoarece contine o metoda virtuala pura, definita in clasele derivate.

Clasa ```AgentieImobiliara``` permite memorarea acestor locuinte intr-un vector de pointeri catre clasa de baza. Aceasta contine metode pentru a adauga noi locuinte (cu operatorul ```>>```), pentru a afisa toate locuintele (cu operatorul ```<<```) sau doar pe cele de un anume tip, pentru a modifica locuintele din agentie, pentru a le sterge si pentru a calcula chiria in functie de valoarea standard a chiriei, suprafata si daca se aplica sau nu discountul.

Toate aceste optiuni pot fi accesate cu ajutorul unui meniu interactiv.

Fisiere sursa ```.cpp```, inclusiv ```main.cpp```, se gasesc in folderul ```src```, in timp ce fisierele header ```.h``` se afla in folderul ```include```.

## !! NOU

In plus, proiectul 3 contine doua *design pattern-uri* si un *template*.

Clasa ```Repository``` reprezinta primul design pattern implementat, si este implementata folosind template. Clasa ```AgentieImobiliara``` nu mai contine acum vectorul de pointeri ca atribut, ci mosteneste clasa ```Repository``` care contine vectorul de pointeri, al caror tip depinde de ce template primeste.

Clasa ```LocuintaFactory``` reprezinta al doilea design pattern implementat, si are o functie membra statica supraincarcata de 2 ori care returneaza un pointer catre unul dintre tipurile de locuinte. Folosesc aceasta functie in cadrul metodelor clasei ```AgentieImobiliara```, acolo unde adaug locuinte in vector, in loc sa ma folosesc direct de *new*, ca pana acum.

Schimbarile fata de proiectul 2 se gasesc in fisierele header si sursa ale celor doua clase noi, si in cele ale clasei ```AgentieImobiliara```.
