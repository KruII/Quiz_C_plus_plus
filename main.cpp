#include "icludy.h" //Biblioteka includów.

using namespace std; //Uzupełnienie std.

int losowa,nr_line=1,punkty,ilosc_pytan,nr_pytania; // Zmienne liczbowe.
string line,odpowiedz,nic; // Zmienne napisów.
string tab[10],answer[10],user_answer[10]; // Zmienne tablicy napisów.

void wylosuj(int losowa[]){ //void losowania.
    for (int i = 0; i < ilosc_pytan; i++)  //pętla powtarzająca do ilości pytań.
    {
        losowa[i]=rand()%10; //Losowanie liczby od 0 do 9.
        for (int j = 0; j<i; j++)  //Losowanie ponowne dla fukcji jeżeli.
        {
            if (losowa[j] == losowa[i]) //Jeżeli wyraz "j" równa się wyraz "i" powtórz losownie.
            {
                losowa[i] = rand() % 10; //Losowanie liczby od 0 do 9.
                j = -1; //Zerowanie wyrazu "j" gdyby była powtórzona nowo wylosowana liczba.
            }
    	}
	}
}

int main(){
    srand( time( NULL ) );
    setlocale(LC_CTYPE, "Polish"); //Ustawienie polskich znakĂłw w konsoli.
    ifstream plik3 ("quiz"); //Otwiera plik "pytania".
    if (!plik3.is_open()) //Sprawdzenie czy plik "pytania" istnieje.
    {
        ofstream plik ("quiz"); //Jeżeli nie, tworzy go.
        plik.close(); //Zamyka uprzednio stworzony plik.
        cout<<"Brak pliku 'quiz'"<<endl;  //Informuję o braku pliku.
        exit(0); //Zakańcza program natychmiastowo.
    }
    cout << "Podaj ilość pytań(Max 10): "; //Zapytanie o ilość pytań w quizie.
    cin >> ilosc_pytan; //Wprowadzenie danych do ilości pytań w quizie.
    int wylosowana[ilosc_pytan]; //Stworzenie tabeli o wielkości "ilość pytań".
	wylosuj(wylosowana); //Uruchomienie void'a.
    while (getline(plik3,line)) //Pętla powtarzająca póki istnieje linijka.
    {
        switch (nr_line) //Wyciąganie z tabeli pytań.
        {
            case 1:
                tab[nr_pytania]=line; //Pobranie do pytania linijki. 
                break; //Zakończenie case 1;
            case 2:
                answer[nr_pytania]=line; //Pobranie do odpowiedzi linijki. 
                break; //Zakończenie case 2;
        }
        if (nr_line==2) //Sprawdzanie czy numer lini równa się 2 jeżeli tak:
            {
                nr_line=0; //Ustawia numer lini na 0,
                nr_pytania++; //Zwieksza numer pytania o 1.
            }
            nr_line++; //Zwieksza numer lini o 1.
    }
    for (int i = 0; i < ilosc_pytan; i++) //Powtarza przez ilość pytań.
    {
        cout<<endl<<tab[wylosowana[i]]<<endl; //Zadaję pytanie z tabeli.
        cin>>odpowiedz; //Wprowadza odpowiedź.
        transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(), ::toupper); //Zamienia odpowiedź na duże litery.
        user_answer[i]=odpowiedz;
        if (odpowiedz==answer[wylosowana[i]]) // Jeżeli odpowiedź udzielona zgadza się z rozwiązaniem:
        {
            cout<<endl<<"Odpowiedź jest poprawna"<<endl; //Wypisuję że odpowiedź jest poprawna,
            punkty++; // Zwiększa liczbe punktów o 1.
        }
        else{cout<<endl<<"Odpowiedź jest nie jest poprawna"<<endl;} //W przeciwnym wypadku wypisuję że odpowiedź jest błędna.
    }
    cout<<"Udało Ci się zdobyć "<<punkty<<" punktów gratulację"<<endl;// Wypisuję ile punktów udało się zdobyć.
    ofstream plik5 ("Punkty.html"); //Utworzenie pliku "Punkty.html".
    plik5<<"<!DOCTYPE HTML>"<<endl<<"<html lang=\"pl\">"<<endl<<"<head>"<<endl<<"<title>Punkty</title><meta charset=\"utf-8\" /><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge,chrome=1\" /><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><meta name=\"author\" content=\"Kacper Dobrowolski\" /><link rel=\"stylesheet\" href=\"index.css\">"<<endl<<"</head>"<<endl<<"<body>"<<endl<<"<h1>Zdobyto "<<punkty<<" punktów</h1><ul>";//Początek html.
    for (int i = 0; i < ilosc_pytan; i++) //Pętla powtarzająca do ilości pytań.
    {
        plik5<<"Pytanie "<<i+1<<" : "<<tab[wylosowana[i]]<<"</br>"<<"Poprawna odpowiedź: "<<answer[wylosowana[i]]<<"</br>Udzielona odpowiedź: "<<user_answer[i]<<"</br></br>"; //Wypisanie danych.
    }
    plik5<<"</ul>"<<endl<<"</body>"; //zakończenie html
    plik5.close(); //Zamyka plik z punktami.
    ofstream css ("index.css"); //Tworzy plik css.
    css<<"body {background-color: #303030;color: #dcdcdc;margin: auto;}h1{font-size: 34px;font-family:Gill Sans, sans-serif;text-align: center;}ul{text-align: center;font-size: 20px;}";//Uzupełnia plik css.
    css.close(); //Zamyka plik css.
    Sleep(1000); //Usypia program na 1 sekunde.
    return 0;
} 