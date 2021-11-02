#include <iostream>
#include "windows.h" 

using namespace std;


string imie1;//przechowywanie imion
string imie2;

int gracz1[10][10];//tablica na statki
int gracz2[10][10];

int strzal1[10][10];//tablica na strzały
int strzal2[10][10];

int wynik1 = 11;//ile statków zostało (części)
int wynik2 = 11;

int ilejednopolowych = 5;
int iledwupolowych = 3;

int iloscstatkow = ilejednopolowych + (iledwupolowych*2);//liczenie ilości częsci do zestrzelenia

int progres = 1;


void Mapa(int gracz) {//wczytywanie mapki
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
    if(gracz == 2)
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


    if (gracz == 3)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int y = 0; y < 10; y++) {
                cout << " " << strzal1[i][y];
            }
            cout << endl;
        }
        cout << endl;
    }

    if (gracz == 4)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int y = 0; y < 10; y++) {
                cout << " " << strzal2[i][y];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Rozstawienie1()//funkcja wywołująca rozstawianie statków gracza 1
{
    progres = 1;//funkcja techniczna aby wiedzieć ile jeszcze zostało wykonań pętli do rozstawiania statków

    int kord1 = 10;
    int kord2 = 10;

    while (progres < ilejednopolowych + 1)//pętla do rozstawiania statków
    {
        system("cls");
        Mapa(1);//wywołanie funkcji pokazującej mape

        cout << "Niech gracz " << imie1 << " wpisze koordynaty gdzie chce miec statek Nr: " << progres << " jednopolowy. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;
        if (gracz1[kord1 - 1][kord2 - 1] == 0)//sprawdzenie czy nie ma tutaj statku już
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)//sprawdzenie czy nie próbujesz ustawić statku poza mapą
            {
                gracz1[kord1 - 1][kord2 - 1] = 1;//ustawienie statku na mapie
                progres++;//wywołanie kolejnej iteracji(jeden cykl pętli)
            }
            else
            {
                cout << "Nie mozna umiescic statku poza mapa!" << endl;
                Sleep(2500);
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
            Sleep(2500);
        }
    }



    progres = 1;
    int kierunek;//zmienna w którą stronę stateczek podwójny
    int kord1v2;
    int kord2v2;

    bool statekv2gut = false;//zmienna czy zapisać już koordynaty na mapkę

    while (progres < iledwupolowych + 1)//pętla do ustawienia podwójnych statków na mapkę
    {
        system("cls");
        Mapa(1);

        cout << "Niech gracz " << imie1 << " wpisze koordynaty statku Nr: " << progres << " dwupolowego. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;

        if (gracz1[kord1 - 1][kord2 - 1] == 0)//sprawdzenie czy jest już statek na tym miejscu
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)//sprawdzenie czy jest poza mapą 
            {
                cout << endl << endl << "w jakim kierunku ma byc skierowany? (wpisz liczbe)" << endl << "w gore - 1" << endl << "w dol - 2" << endl << "w lewo - 3" << endl << "w prawo - 4" << endl;
                cin >> kierunek;

                cout << endl;

                kord1v2 = kord1;
                kord2v2 = kord2;

                switch (kierunek)//wywołanie odpowiedniej funkcji zależnie od tego w jakim kierunku ma być statek
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
                                Sleep(2500);
                            }
                        }
                        else
                        {
                            cout << "Tam juz jest statek!" << endl;
                            Sleep(2500);
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
                                Sleep(2500);
                            }
                        }
                        else
                        {
                            cout << "Tam juz jest statek!" << endl;
                            Sleep(2500);
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
                                Sleep(2500);
                            }
                        }
                        else
                        {
                            cout << "Tam juz jest statek!" << endl;
                            Sleep(2500);
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
                                Sleep(2500);
                            }
                        }
                        else
                        {
                            cout << "Tam juz jest statek!" << endl;
                            Sleep(2500);
                        }
                        break;
                    default:
                        break;
                }
            }
            else
            {
                cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                Sleep(2500);
            }

            if (statekv2gut)//jeżeli wszystko jest ok, to tutaj zapisujemy na mapce statek podwójny
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
            Sleep(2500);
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
                Sleep(2500);
            }
        }
        else
        {
            cout << "Tam juz jest statek!" << endl;
            Sleep(2500);
        }
    }



    progres = 1;
    int kierunek;
    int kord1v2;
    int kord2v2;

    bool statekv2gut = false;

    while (progres < iledwupolowych + 1)
    {
        system("cls");
        Mapa(2);

        cout << "Niech gracz " << imie2 << " wpisze koordynaty statku Nr: " << progres << " dwupolowego. Odzielone spacja." << endl;
        cin >> kord1 >> kord2;

        if (gracz2[kord1 - 1][kord2 - 1] == 0)
        {
            if (11 > kord1 - 1 >= 0 && 11 > kord2 - 1 >= 0)
            {
                cout <<endl<< "w jakim kierunku ma byc skierowany? (wpisz liczbe)" << endl << "w gore - 1" << endl << "w dol - 2" << endl << "w lewo - 3" << endl << "w prawo - 4" << endl;
                cin >> kierunek;

                cout << endl;

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
                            Sleep(2500);
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                        Sleep(2500);
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
                            Sleep(2500);
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                        Sleep(2500);
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
                            Sleep(2500);
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                        Sleep(2500);
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
                            Sleep(2500);
                        }
                    }
                    else
                    {
                        cout << "Tam juz jest statek!" << endl;
                        Sleep(2500);
                    }
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "Nie mozesz umiejscic statku poza mapa" << endl;
                Sleep(2500);
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
            Sleep(2500);
        }
    }
}

void Rozpocznij() //funkcja rozpoczynająca rozgrywkę
{
    bool rozgrywka=true;//zmienna czy rozgrywka jeszcze trwa
    bool ktorygracz = true;//zmienna czy pierwszy gracz ma kolejke, jesli nie to drugi

    wynik1 = iloscstatkow;//ile statkow zostalo do zestrzelenia graczowi
    wynik2 = iloscstatkow;

    int kord1;
    int kord2;

    while (rozgrywka)//petla do kolejek graczy
    {
        Sleep(4000);
        system("cls");

        if (ktorygracz) // sprawdzenie kto teraz ma kolejke i wywolanie jego tury
        {
            cout << "Mapa strzalow:" << endl;
            Mapa(3);
            cout << "Niech gracz " << imie1<< " wpisze koordynaty w ktore chce strzelic" << endl;
            cin >> kord1 >> kord2;

            if (gracz2[kord1-1][kord2-1]>0) //sprawdzenie czy jest tam statek
            {
                strzal1[kord1 - 1][kord2 - 1] = 2;

                wynik1--;

                Sleep(1500);
                system("cls");
                cout << endl << "Trafiony! Zostalo " << wynik1 << " czesci statkow" << endl;
            }
            else
            {
                strzal1[kord1 - 1][kord2 - 1] = 1;
                
                Sleep(1500);
                system("cls");
                cout << endl << "Pudlo! Zostalo " << wynik1 << " czesci statkow" << endl;
            }
            Mapa(3);

            ktorygracz = false;//przekazanie kolejki kolejnemu graczowi
        }
        else
        {
            cout << "Mapa strzalow:" << endl;
            Mapa(4);
            cout << "Niech gracz " << imie2 << " wpisze koordynaty w ktore chce strzelic" << endl;
            cin >> kord1 >> kord2;

            if (gracz1[kord1 - 1][kord2 - 1] > 0)
            {
                strzal2[kord1 - 1][kord2 - 1] = 2;

                wynik2--;

                Sleep(1500);
                system("cls");
                cout << endl << "Trafiony! Zostalo " << wynik2 << " czesci statkow" << endl;
            }
            else
            {
                strzal2[kord1 - 1][kord2 - 1] = 1;

                Sleep(1500);
                system("cls");
                cout << endl << "Pudlo! Zostalo " << wynik2 << " czesci statkow" << endl;
            }
            Mapa(4);

            ktorygracz = true;
        }

        if (wynik1 == 0 || wynik2 == 0) //sprawdzenie po każdej turze czy już ktoś wygrał jeśli tak to koniec gry
        {
            rozgrywka = false;
        }
    }
    system("cls");
    if (wynik1 == 0) //pokazanie imienia gracza ktory wygrał
    {
        cout << "Gracz "<< imie1 << " wygral" << endl;
    }
    if (wynik2 == 0)
    {
        cout << "Gracz " << imie2 << " wygral" << endl;
    }
}

int main()
{
    cout << "Wpisz nazwe pierwszego gracza" << endl;
    cin >> imie1;

    cout << endl;

    cout << "Wpisz nazwe drugiego gracza" << endl;
    cin >> imie2;

    Rozstawienie1();

    system("cls");
    cout << "Tak wyglada ostatecznie flota gracza "<< imie1 << endl;
    Mapa(1);

    Sleep(5000);

    Rozstawienie2();

    system("cls");
    cout << "Tak wyglada ostatecznie flota gracza " << imie2 << endl;
    Mapa(2);

    Sleep(5000);

    Rozpocznij();
}