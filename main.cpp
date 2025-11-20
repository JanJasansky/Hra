#include <iostream>
#include "game.h"

using namespace std;

int main()
{

    line();
    cout << "  Vitejte v pribehove hre - Dusanova kariera.\n";
    line();

    introduction();

    scena1();
    pauseMenu();

    scena2();
    pauseMenu();

    scena3();
    pauseMenu();

    scena4();
    pauseMenu();

    scena5();
    pauseMenu();

    cout << "\n=== KONEC HRY ===\n";
    cout << "Tvoje finalni statistiky:\n";
    showStats();
    // determine ending

    if (performance <= 0 || discipline <= 0 || reputation <= 0)
    {
        cout << "KONEC: Dušan je břídil.\n";
    }
    else if (discipline >= reputation && discipline >= performance)
    {
        cout << "KONEC: Dušan se stal profesionalem s obrovskou disciplinou.\n";
    }
    else if (reputation >= discipline && reputation >= performance)
    {
        cout << "KONEC: Dušan je milacek fanousku a hvezda medii.\n";
    }
    else if (performance >= discipline && performance >= reputation)
    {
        cout << "KONEC: Dušan dominoval na hristi jako stroj.\n";
    }
    else
    {
        cout << "KONEC: Dušan skoncil nekde mezi slibem a realitou.\n";
    }

    cout << endl
         << "Diky za hrani" << endl;
    return 0;
}