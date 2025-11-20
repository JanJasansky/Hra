#include <iostream>
#include <limits>
#include <string>
#include "game.h"

using namespace std;

int discipline = 5;
int reputation = 5;
int performance = 5;
int currentQuestion = 0;
const int totalQuestions = 35;

void introduction()
{
    cout << "\n";
    cout << "Vitej ve hre Dusanova kariera — psychologickem unikovem dobrodruzstvi.\n\n";
    cout << "V teto hre se stanes Dusanem, clovekem stojicim na krizovatce sveho zivota.\n";
    cout << "Kazde tve rozhodnuti ovlivni jeho cestu — jeho motivaci, uspech i cestu na vrchol.\n\n";
    cout << "Na kazdem kroku te cekaji tri moznosti.\n";
    cout << "Rozhoduj se s rozvahou... protoze tve ciny urci, zda Dusan dosahne velikosti — nebo vse ztrati.\n\n";
    cout << "\033[31mStiskni 2x ENTER pro zahajeni sve cesty.\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vycisteni bufferu pro jistotu
    cin.get();
}

void line()
{
    cout << "===================================================\n";
}

void showStats()
{
    cout << "\033[36m\n--- STATY HRÁČE ---\n";
    cout << "Disciplína: " << discipline << endl;
    cout << "Reputace:   " << reputation << endl;
    cout << "Výkon:      " << performance << endl;
    cout << "--------------------\n\n";
}

void showProgress()
{
    // Use a bar width equal to the total number of questions
    const int barWidth = totalQuestions;
    int filled = currentQuestion;

    if (barWidth <= 0)
        filled = 0;

    if (filled < 0)
        filled = 0;
    if (filled > barWidth)
        filled = barWidth;

    cout << "\033[32m===================================================\n";
    cout << "Celkovy postup: [";
    for (int i = 0; i < filled; ++i)
        cout << '=';
    for (int i = filled; i < barWidth; ++i)
        cout << '-';
    cout << "] " << currentQuestion << "/" << totalQuestions << "\n";
}

void pauseMenu()
{
    cout << "\033[31m\n(Stiskni 'ENTER' pro pokracovani nebo 'S' pro statistiky)\n";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    getline(cin, input);

    if (input == "s" || input == "S")
    {
        showStats();
        cout << "\033[31mStiskni 'ENTER' pro navrat...\n";
        cin.get();
    }
}

// funkce co cte volby
int ctiVolbu(int minimum, int maximum)
{
    int cislo;

    while (true)
    {
        cout << "> ";
        cin >> cislo;

        // pokud nekdo napise pismeno nebo blbost
        if (!cin)
        {
            cout << "Zadej cislo!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // kontrola rozsahu
        if (cislo >= minimum && cislo <= maximum)
        {
            // zvýšíme progress (pokud ještě nejsme nad celkovým počtem)
            if (currentQuestion < totalQuestions)
                ++currentQuestion;
            return cislo;
        }

        cout << "Zadej cislo!!" << minimum << "-" << maximum << endl;
    }
}

// SCENA 1  JEDNANI S AGENTEM
void scena1()
{
    int volba;

    cout << endl;
    cout << "\033[33mSCENA 1 - Jednani s agentem" << endl;

    // 1
    line();
    cout << "\033[34mVaclav: \"Dusane, mam tu nabidku z FC Drakonia.\"\n";
    cout << "Trileta smlouva, 85 tisic mesicne a premie za goly. Co myslis?\n";
    cout << "\033[0m1) \"Podepis to, chci hrat!\"\n";
    cout << "2) \"Zkus vyjednat vic.\"\n";
    cout << "3) \"Neni to malo?\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Beru to. Zitra tiskovka.\"\n";
        discipline += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Ok, zkusim zatlacit. Zitra to potvrdime.\"\n";
        reputation += 1;
    }
    else
    {
        cout << "\033[34mVaclav: \"Hele, Drakonia je dobra sance. Promysli to.\"\n";
        performance -= 1;
    }
    showProgress();

    // 2
    line();
    cout << "\033[34mVaclav: \"Dobre, ale vis, ze tlak bude obrovsky. Jsi pripraven?\"\n";
    cout << "\033[0m1) \"Narodil jsem se pro tlak.\"\n";
    cout << "2) \"Snad to zvladnu.\"\n";
    cout << "3) \"Nevim, nikdy jsem to nezazil.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Tak to chci slyset.\"\n";
        discipline += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Strach je normalni, hlavne ho prekonej.\"\n";
        performance += 1;
    }
    else
    {
        cout << "\033[34mVaclav: \"Tak to bude tvoje prvni velka zkouska.\"\n";
        discipline -= 1;
    }
    showProgress();

    // 3
    line();
    cout << "\033[34mVaclav: \"Jake cislo chces na dres?\"\n";
    cout << "\033[0m1) \"Desitku. Jako kapitan.\"\n";
    cout << "2) \"Cokoliv, jsem tu novy.\"\n";
    cout << "3) \"Sedmicku, ta mi prinasi stesti.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Desitka? Odvazny vyber.\"\n";
        reputation += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Skromnost se ceni.\"\n";
    }
    else
    {
        cout << "\033[34mVaclav: \"Sedmicka ti muze sednout.\"\n";
        performance += 1;
    }
    showProgress();

    // 4
    line();
    cout << "\033[34mVaclav: \"Mam ti tam pripsat i bonus za goly?\"\n";
    cout << "\033[0m1) \"Jasne, budu je potrebovat.\"\n";
    cout << "2) \"Hlavne at hraju.\"\n";
    cout << "3) \"Nech to byt, neresim prachy.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Tak jo, bonusy tam dam.\"\n";
        performance += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"To rad slysim, minuta je vic nez penize.\"\n";
        discipline += 1;
    }
    else
    {
        cout << "\033[34mVaclav: \"Takovy pristup dneska nema skoro nikdo.\"\n";
        reputation += 1;
    }
    showProgress();

    // 5
    line();
    cout << "\033[34mVaclav: \"Novinari uz o tobe pisou. Mam to komentovat?\"\n";
    cout << "\033[0m1) \"Jo, ukaz jim, ze prichazi hvezda.\"\n";
    cout << "2) \"Nech to byt, chci klid.\"\n";
    cout << "3) \"Rekni jim, ze jdu makat.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Dobře, udelam z tebe velke jmeno.\"\n";
        reputation += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Jasne, drzime se mimo svetla reflektoru.\"\n";
        discipline += 1;
    }
    else
    {
        cout << "\033[34mVaclav: \"Skromnost, ale ambice. To se libi.\"\n";
        performance += 1;
    }
    showProgress();

    // 6
    line();
    cout << "\033[34mVaclav: \"Zitra mas podpis v klubu. Trener Honza nesnasi opozdilce.\"\n";
    cout << "\033[0m1) \"Budu tam prvni.\"\n";
    cout << "2) \"V pohode, stihnu to.\"\n";
    cout << "3) \"A co, jeden den se nic nestane.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Vyborne, prvni dojem je klicovy.\"\n";
        discipline += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Hlavne to nezaspi.\"\n";
    }
    else
    {
        cout << "\033[34mVaclav: \"Takovy pristup se trenerovi libit nebude.\"\n";
        discipline -= 1;
    }
    showProgress();

    // 7
    line();
    cout << "\033[34mVaclav: \"Kazda volba muze zmenit tvuj zivot. Uvedomujes si to?\"\n";
    cout << "\033[0m1) \"Jasne, davam si pozor.\"\n";
    cout << "2) \"Uvidime, jak to dopadne.\"\n";
    cout << "3) \"Zivot je hra.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Rozumne.\"\n";
        discipline += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Tak doufej, ze mas stesti.\"\n";
    }
    else
    {
        cout << "\033[34mVaclav: \"Tak hraj chytre.\"\n";
        performance += 1;
    }
    showProgress();

    // 8
    line();
    cout << "😎 \033[34mVaclav: \"Takze... potvrzuju prestup?\"\n";
    cout << "\033[0m1) \"Ano, podepisuj.\"\n";
    cout << "2) \"Pockej, premyslim.\"\n";
    cout << "3) \"Podepis, ale pod podminkami.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        cout << "\033[34mVaclav: \"Hotovo. Od zitra jsi hrac Drakonie.\"\n";
        discipline += 1;
        performance += 1;
    }
    else if (volba == 2)
    {
        cout << "\033[34mVaclav: \"Ok, necham ti cas.\"\n";
    }
    else
    {
        cout << "\033[34mVaclav: \"Zkusim vyjednat co pujde.\"\n";
        reputation += 1;
    }
    showProgress();
    line();

    cout << endl
         << "\033[33m[Konec sceny 1]" << endl;
}

// SCENA 2 – PODPIS V KLUBU
void scena2()
{
    int volba;

    cout << "\033[33mSCENA 2 - Podpis v klubu" << endl;

    // 9
    line();
    cout << "\033[34mHonza: \"Vitej v Drakonii. U me plati dve veci: makat a byt vcas.\"\n";
    cout << "\033[0m1) \"Rozumim, trenere.\"\n";
    cout << "2) \"Jasne, jen zadny stres.\"\n";
    cout << "3) \"Tak to mame spolecne.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        performance -= 1; // P -1
    }
    else
    {
        reputation += 1; // R +1
    }
    showProgress();

    // 10
    line();
    cout << "\033[34mHonza: \"Zitra trenink v 7:00. Prijdes?\"\n";
    cout << "\033[0m1) \"Budu tam driv.\"\n";
    cout << "2) \"Zkusim to stihnout.\"\n";
    cout << "3) \"Sedm? To je vrazda.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        // 0
    }
    else if (volba == 3)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    showProgress();

    // 11
    line();
    cout << "\033[34mHonza: \"Jak se citis po podpisu?\"\n";
    cout << "\033[0m1) \"Motivovane.\"\n";
    cout << "2) \"Jsem nervozni.\"\n";
    cout << "3) \"V klidu, mam to pod kontrolou.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        performance += 1; // P +1
    }
    else if (volba == 2)
    {
        discipline -= 1; // D -1
    }
    else
    {
        reputation += 1; // R +1
    }
    showProgress();

    // 12
    line();
    cout << "\033[34mHonza: \"Mas velky potencial, ale i ego. Co prevazi?\"\n";
    cout << "\033[0m1) \"Pokora.\"\n";
    cout << "2) \"Ego me zene kupredu.\"\n";
    cout << "3) \"Zalezi na dni.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        reputation += 1; // R +1
    }
    else if (volba == 2)
    {
        performance += 1; // P +1
    }
    else
    {
        // 0
    }
    showProgress();

    // 13
    line();
    cout << "\033[34mLukas: \"Hele kamo, vecer hospoda. Zapijem to, ne?\"\n";
    cout << "\033[0m1) \"Jasne!\"\n";
    cout << "2) \"Ne, chci byt fit.\"\n";
    cout << "3) \"Jedno pivo a domu.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        reputation += 1;
        performance -= 2; // R +1, P -2
    }
    else if (volba == 2)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else
    {
        reputation += 1; // D 0, R +1
    }
    showProgress();

    // 14
    line();
    cout << "\033[34mHonza (k Dusanovi): \"Takhle to zacina. Jeden drink, a pak to jde z kopce.\"\n";
    cout << "\033[0m1) \"Nebojte, vim, co delam.\"\n";
    cout << "2) \"Mate pravdu.\"\n";
    cout << "3) \"Jednou se to prece musi oslavit.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        // D 0
    }
    else
    {
        reputation += 1;
        performance -= 1; // R +1, P -1
    }
    showProgress();

    // 15
    line();
    cout << "\033[34mVaclav (vola): \"Pamatuj, Honza te sleduje. Nepokaz to prvni den.\"\n";
    cout << "\033[0m1) \"Neboj, dam si pozor.\"\n";
    cout << "2) \"Zvladnu to i s pivem.\"\n";
    cout << "3) \"Je to jen trenink, ne valka.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        performance -= 1;
        discipline -= 1; // P -1, D -1
    }
    else
    {
        // 0
    }
    showProgress();
    line();

    cout << endl
         << "\033[33m[Konec sceny 2]" << endl;
}

// SCENA 3 - HOSPODA NEBO DOMOW
void scena3()
{
    int volba;

    cout << "\033[33mSCENA 3 - Hospoda nebo domov" << endl;

    // 16
    line();
    cout << "\033[34mLukas: \"Na Dusana! Novy hrac Drakonie!\"\n";
    cout << "\033[0m1) \"Na zdravi!\"\n";
    cout << "2) \"Diky, ale jen jedno.\"\n";
    cout << "3) \"Nepiju, kamo.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline -= 1;
        reputation += 1; // D -1, R +1
    }
    else if (volba == 2)
    {
        // D 0
    }
    else
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    showProgress();

    // 17
    line();
    cout << "\033[34mLukas: \"Tak povidej, jake to je podepsat profik?\"\n";
    cout << "\033[0m1) \"Uzasny pocit.\"\n";
    cout << "2) \"Uprimne? Citim tlak.\"\n";
    cout << "3) \"Je to jen smlouva, klid.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        performance += 1; // P +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        // R 0
    }
    showProgress();

    // 18
    line();
    cout << "\033[34mLukas: \"Dej si jeste jedno, nekaz partu.\"\n";
    cout << "\033[0m1) \"Dobre, ale posledni.\"\n";
    cout << "2) \"Ani nahodou.\"\n";
    cout << "3) \"At zije Drakonia!\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else
    {
        reputation += 1;
        discipline -= 1; // R +1, D -1
    }
    showProgress();

    // 19
    line();
    cout << "\033[34mLukas: \"Vis, ze trener tohle nesnasi?\"\n";
    cout << "\033[0m1) \"Nevi, neboli.\"\n";
    cout << "2) \"Tak radsi pujdu.\"\n";
    cout << "3) \"Jedno pivo jeste nikoho nezabilo.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline -= 1; // D -1
    }
    else if (volba == 2)
    {
        discipline += 1; // D +1 (P +0)
    }
    else
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    showProgress();

    // 20
    line();
    cout << "\033[34mVaclav (vola): \"Jsi v hospode? Trener to zjisti.\"\n";
    cout << "\033[0m1) \"Ne, jen voda!\"\n";
    cout << "2) \"Jen chvilku, slibuju.\"\n";
    cout << "3) \"Klid, Venco, mam to pod kontrolou.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1; // D +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        reputation += 3; // R +1
    }
    showProgress();

    // 21
    line();
    cout << "\033[34mRano - trenink: \"Dusane, proc mas kruhy pod ocima?\"\n";
    cout << "\033[0m1) \"Spatne jsem spal.\"\n";
    cout << "2) \"Byl jsem venku.\"\n";
    cout << "3) \"Zena me mlati.\"\n";
    volba = ctiVolbu(1, 3);

    // Info příběhu
    // line();
    // cout << "(Trenér tě odhalil): \"(Dušan si pomyslí)\"\n";
    // cout << "1) \"Jak to zjistil.\"\n";
    // cout << "2) \"Tak to su v prdeli.\"\n";
    // cout << "3) \"Tak to je debil.\"\n";
    // volba = ctiVolbu(1, 3);

    showProgress();

    // 22
    line();
    cout << "\033[34mHonza: \"Takhle to zacina. Mas talent, ale zadnou vuli.\"\n";
    cout << "\033[0m1) \"Omlouvam se.\"\n";
    cout << "2) \"To se uz nestane.\"\n";
    cout << "3) \"To prehanite.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        // D 0
    }
    else if (volba == 2)
    {
        reputation += 1; // R +1,
    }
    else
    {
        reputation -= 2; // R -2,
    }
    showProgress();

    // 23
    line();
    cout << "\033[34mLukas: \"Neber si to osobne, trener ma vzdycky kecy.\"\n";
    cout << "\033[0m1) \"Ma pravdu.\"\n";
    cout << "2) \"Nekdy jo.\"\n";
    cout << "3) \"Kaslu na nej.\"\n";
    volba = ctiVolbu(1, 3);
    showProgress();
    line();

    cout << endl
         << "\033[33m[Konec sceny 3]" << endl;
}

// SCENA 4 - PRVNI ZAPAS
void scena4()
{
    int volba;

    cout << "\033[33mSCENA 4 - Prvni zapas" << endl;

    // 24
    line();
    cout << "\033[34mHonza: \"Jdes na hriste. Mas 15 minut. Co udelas?\"\n";
    cout << "\033[0m1) \"Makam naplno.\"\n";
    cout << "2) \"To je malo casu.\"\n";
    cout << "3) \"Dam gol.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 2; // D +1, P +2
    }
    else if (volba == 2)
    {
        // D 0
    }
    else
    {
        performance += 2;
        reputation += 1; // P +2, R +1
    }
    showProgress();

    // 25
    line();
    cout << "\033[34mNa hristi: \"Balon mas u nohy.\"\n";
    cout << "\033[0m1) \"Prihravam spoluhraci.\"\n";
    cout << "2) \"Strilim!\"\n";
    cout << "3) \"Zpanikarim.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        performance += 1; // P +1
    }
    else if (volba == 2)
    {
        performance += 2; // P +2
    }
    else
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    showProgress();

    // 26
    line();
    cout << "\033[34mFanousci buci:\n";
    cout << "\033[0m1) \"Soustredim se dal.\"\n";
    cout << "2) \"Rozciluje me to.\"\n";
    cout << "3) \"Mavnu na ne.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        reputation -= 1; // R -1
    }
    showProgress();

    // 27
    line();
    cout << "\033[34mPo zapase Honza: \"Nebyl to spatny debut.\"\n";
    cout << "\033[0m1) \"Diky, trenere.\"\n";
    cout << "2) \"Chtel jsem dat vic.\"\n";
    cout << "3) \"Bylo to v pohode.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        reputation += 1; // R +1
    }
    else if (volba == 2)
    {
        performance += 1; // P +1
    }
    else
    {
        // 0
    }
    showProgress();

    // 28
    line();
    cout << "\033[34mVaclav: \"Dobra prace, mam nove nabidky.\"\n";
    cout << "\033[0m1) \"Jeste jsem nic nedokazal.\"\n";
    cout << "2) \"To zni skvele!\"\n";
    cout << "3) \"Kolik za to?\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        // D 0
    }
    else if (volba == 2)
    {
        reputation += 1; // R +1
    }
    else
    {
        performance += 1; // P +1
    }

    // 29
    line();
    cout << "\033[34mLukas: \"Slavime, jsi hvezda!\"\n";
    cout << "\033[0m1) \"Ne, jdu regenerovat.\"\n";
    cout << "2) \"Jedno pivo.\"\n";
    cout << "3) \"Celou noc!\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        discipline -= 2;
        performance -= 2; // D -2, P -2
    }
    showProgress();

    // 30
    line();
    cout << "\033[34mRano: \"Zaspal jsi trenink.\"\n";
    cout << "\033[0m1) \"Promin.\"\n";
    cout << "2) \"Nestalo se nic.\"\n";
    cout << "3) \"Byl jsem hvezda, ne?\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        reputation -= 1; // R -1
    }
    else if (volba == 2)
    {
        // 0
    }
    else
    {
        reputation += 1;
        performance += 1; // R +1, P +1
    }
    showProgress();
    line();
    cout << endl
         << "\033[33m[Konec sceny 4]" << endl;
}

// SCENA 5 – FINALE
void scena5()
{
    int volba;

    cout << "\033[33mSCENA 5 - Finale" << endl;

    // 31
    line();
    cout << "\033[34mHonza: \"Tak, konci sezona. Jsem na tebe pysny - nebo zklamany?\"\n";
    cout << "\033[0m1) \"Dekuji za duveru.\"\n";
    cout << "2) \"Delal jsem, co slo.\"\n";
    cout << "3) \"Muze za to alkohol.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        reputation += 1; // D +1, R +1
    }
    else if (volba == 2)
    {
        performance += 1; // P +1
    }
    else
    {
        discipline -= 2;
        performance -= 1; // D -2, P -1
    }
    showProgress();

    // 32
    line();
    cout << "\033[34mVaclav: \"Z Italie prisla nabidka. Chces prestoupit?\"\n";
    cout << "\033[0m1) \"Ano, jsem pripraven.\"\n";
    cout << "2) \"Nevim, jsem unaveny.\"\n";
    cout << "3) \"Kolik plati?\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        reputation += 1; // R +1
    }
    showProgress();

    // 33
    line();
    cout << "\033[34mLukas: \"Jdem to zapit, bracho.\"\n";
    cout << "\033[0m1) \"Ne, musim letet na trenink.\"\n";
    cout << "2) \"Jedno na rozloucenou.\"\n";
    cout << "3) \"Nalej mi dvakrat.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else if (volba == 2)
    {
        performance -= 1; // D 0, P -1
    }
    else
    {
        discipline -= 1;
        performance -= 2; // D -1, P -2
    }
    showProgress();

    // 34
    line();
    cout << "\033[34mHonza: \"Mas posledni slovo. Kdo jsi, Dusane?\"\n";
    cout << "\033[0m1) \"Profesional.\"\n";
    cout << "2) \"Ztraceny talent.\"\n";
    cout << "3) \"Clovek, co zil naplno.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        discipline += 1;
        performance += 1; // D +1, P +1
    }
    else if (volba == 2)
    {
        discipline -= 1;
        performance -= 1; // D -1, P -1
    }
    else
    {
        reputation += 1; // R +1
    }
    showProgress();

    // 35
    line();
    cout << "\033[34mVaclav: \"Dobre, synku. Tak tohle je tvuj pribeh.\"\n";
    cout << "\033[0m1) \"Hvezda sezony.\"\n";
    cout << "2) \"Alkoholik.\"\n";
    cout << "3) \"Nekde mezi.\"\n";
    volba = ctiVolbu(1, 3);
    // staty odpovědí
    if (volba == 1)
    {
        reputation += 2;
        performance += 1; // R +2, P +1
    }
    else if (volba == 2)
    {
        discipline -= 2;
        performance -= 2; // D -2, P -2
    }
    else
    {
        // bez změny
    }

    showProgress();
    line();

    cout << endl
         << "\033[33m[Konec sceny 5]" << endl;
}