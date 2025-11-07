#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktura pro jedno místo
struct Lokace {
    string jmeno;
    string popis;

// Ukazatele na jiné lokace
Lokace* nahoru;
Lokace* dolu;
Lokace* doleva;
Lokace* doprava;

    bool maPredmet;
    string predmet;
};

// Inventář hráče
struct Hrac {
    bool bomba = false;
    bool stipacky = false;
    bool munice = false;
    bool bren = false;
};

// Struktura zatím jen s názvem
struct Area {
    string name;
};

// Seznam oblastí
vector<Area> mapa = {
    {"Okraj lesa (únik)"},
    {"Rádiová věž"},
    {"Minové pole"},
    {"Zřícená silnice"},
    {"Protitankové dělo"},
    {"Lesní stezka"},
    {"Vojenské skladiště"},
    {"Zničený most"},
    {"Spawn"},
    {"Tábor nepřátel"},
    {"Okraj lesa (fake)"}
};

