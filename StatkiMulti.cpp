#include <iostream>
#include "windows.h" 

using namespace std;


string imie1;
string imie2;

int gracz1[10][10];
int gracz2[10][10];

int wynik1 = 10;
int wynik2 = 10;

int ilejednopolowych = 2;
int iledwupolowych = 1;

int progres = 1;


void Mapa(int gracz) {
    string wizualne;

    if (gracz == 1) {
        for (int i = 0; i < 10; i++)
        {
            for (int y = 0; y < 10; y++) {
                cout << " " << gracz1[i][y];
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int y = 0; y < 10; y++) {
                cout << " " << gracz2[i][y];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Rozstawienie1()
{
    progres = 1;

    int kord1 = 10;
    int kord2 = 10;

    while (progres < ilejednopolowych + 1)
    {
        Sleep(3000);
        system("cls");
        Mapa(1);

        cout << "Niech gracz " << imie1 << " wpisze koordynaty gdzie chce miec statek Nr: " << progres << " jednopolowy. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;
        if (gracz1[kord1 - 1][kord2 - 1] == 0)
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)
            {
                gracz1[kord1 - 1][kord2 - 1] = 1;
                progres++;
            }
            else
            {
                cout << "Nie mozna umiescic statku poza mapa!" << endl;
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
        }
    }



    progres = 1;
    int kierunek;
    int kord1v2;
    int kord2v2;

    bool statekv2gut = false;

    while (progres < iledwupolowych + 1)
    {
        Sleep(3000);
        system("cls");
        Mapa(1);

        cout << "Niech gracz " << imie1 << " wpisze koordynaty statku Nr: " << progres << " dwupolowego. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;

        if (gracz1[kord1 - 1][kord2 - 1] == 0)
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)
            {
                cout << "w jakim kierunku ma byc skierowany? (wpisz liczbe)" << endl << "w gore - 1" << endl << "w dol - 2" << endl << "w lewo - 3" << endl << "w prawo - 4" << endl;
                cin >> kierunek;

                kord1v2 = kord1;
                kord2v2 = kord2;

                switch (kierunek)
                {
                case 1:
                    if (gracz1[kord1v2 - 2][kord2v2 - 1] == 0)
                    {
                        if (kord1v2 - 2 >= 0)
                        {
                            kord1v2 -= 2;
                            kord2v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 2:
                    if (gracz1[kord1v2][kord2v2 - 1] == 0)
                    {
                        if (kord1v2 >= 0)
                        {
                            kord2v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 3:
                    if (gracz1[kord1v2 - 1][kord2v2 - 2] == 0)
                    {
                        if (kord2v2 - 2 >= 0)
                        {
                            kord1v2 -= 1;
                            kord2v2 -= 2;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 4:
                    if (gracz1[kord1v2 - 1][kord2v2] == 0)
                    {
                        if (kord2v2 >= 0)
                        {
                            kord1v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "Nie mozesz umiejscic statku poza mapa" << endl;
            }

            if (statekv2gut)
            {
                gracz1[kord1 - 1][kord2 - 1] = 2;
                gracz1[kord1v2][kord2v2] = 2;

                statekv2gut = false;

                progres++;
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
        }

    }
}


void Rozstawienie2()
{
    progres = 1;

    int kord1 = 10;
    int kord2 = 10;

    while (progres < ilejednopolowych + 1)
    {
        Sleep(3000);
        system("cls");
        Mapa(2);

        cout << "Niech gracz " << imie2 << " wpisze koordynaty gdzie chce miec statek Nr: " << progres << " jednopolowy. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;
        if (gracz2[kord1 - 1][kord2 - 1] == 0)
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)
            {
                gracz2[kord1 - 1][kord2 - 1] = 1;
                progres++;
            }
            else
            {
                cout << "Nie mozna umiescic statku poza mapa!" << endl;
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
        }
    }



    progres = 1;
    int kierunek;
    int kord1v2;
    int kord2v2;

    bool statekv2gut = false;

    while (progres < iledwupolowych + 1)
    {
        Sleep(3000);
        system("cls");
        Mapa(2);

        cout << "Niech gracz " << imie2 << " wpisze koordynaty statku Nr: " << progres << " dwupolowego. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;

        if (gracz2[kord1 - 1][kord2 - 1] == 0)
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)
            {
                cout << "w jakim kierunku ma byc skierowany? (wpisz liczbe)" << endl << "w gore - 1" << endl << "w dol - 2" << endl << "w lewo - 3" << endl << "w prawo - 4" << endl;
                cin >> kierunek;

                kord1v2 = kord1;
                kord2v2 = kord2;

                switch (kierunek)
                {
                case 1:
                    if (gracz2[kord1v2 - 2][kord2v2 - 1] == 0)
                    {
                        if (kord1v2 - 2 >= 0)
                        {
                            kord1v2 -= 2;
                            kord2v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 2:
                    if (gracz2[kord1v2][kord2v2 - 1] == 0)
                    {
                        if (kord1v2 >= 0)
                        {
                            kord2v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 3:
                    if (gracz2[kord1v2 - 1][kord2v2 - 2] == 0)
                    {
                        if (kord2v2 - 2 >= 0)
                        {
                            kord1v2 -= 1;
                            kord2v2 -= 2;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                case 4:
                    if (gracz2[kord1v2 - 1][kord2v2] == 0)
                    {
                        if (kord2v2 >= 0)
                        {
                            kord1v2 -= 1;

                            statekv2gut = true;
                        }
                        else
                        {
                            cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                    }
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "Nie mozesz umiejscic statku poza mapa" << endl;
            }

            if (statekv2gut)
            {
                gracz2[kord1 - 1][kord2 - 1] = 2;
                gracz2[kord1v2][kord2v2] = 2;

                statekv2gut = false;

                progres++;
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
        }

    }


}


int main()
{
    cout << "Wpisz nazwe pierwszego gracza" << endl;
    cin >> imie1;

    cout << "Wpisz nazwe drugiego gracza" << endl;
    cin >> imie2;

    Rozstawienie1();
    Rozstawienie2();

    Sleep(2000);
    system("cls");
    cout << "Tak ostatecznie wygladaja mapki" << endl;
    Mapa(1);
    Mapa(2);
}
