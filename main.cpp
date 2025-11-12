#include <iostream>
#include <limits>
using namespace std;

// funkce co čte volby
int ctiVolbu(int minimum, int maximum) {
    int cislo;

    while (true) {
        cout << "> ";
        cin >> cislo;

        // pokud nekdo napíše písmeno nebo blbost napr a nebo 10
        if (!cin) {
            cout << "Zadej cislo!" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        // kontroluje rozsahu
        if (cislo >= minimum and cislo <= maximum) {
            return cislo;
        }

        cout << "Zadej cislo " << minimum << "-" << maximum << endl;
    }
}

void scena1() {
    cout << endl;
    cout << "SCENA 1 - Jednani s agentem" << endl;
    cout << "Vaclav: \"Dusan, mam tu nabidku z FC Drakonia.\"\n";
    cout << "Trileta smlouva, 85 tisic mesicne a premie za goly." << endl;
    cout << "Co myslis?" << endl;
    cout << "1) Podepis to, chci hrat!" << endl;
    cout << "2) Zkus vyjednat vic." << endl;
    cout << "3) Neni to malo?" << endl;

    int volba = ctiVolbu(1, 3);

    if (volba == 1) {
        cout << "Vaclav: \"Beru to. Zitra tiskovka.\"";
    }
    else if (volba == 2) {
        cout << "Vaclav: \"Ok, zkusim zatlacit. Zitra to potvrdime.\"";
    }
    else {
        cout << "Vaclav: \"Hele, Drakonia je dobra sance. Promysli to.\"";
    }

    cout << endl << endl << "[Konec sceny 1]" << endl;
}

int main() {
    cout << "KONTRAKT - textova hra" << endl;
    cout << "(Volby zadavej cislem 1/2/3)" << endl;

    scena1();  

    cout << endl << "Diky za hrani " << endl;
    return 0;
}
