#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct uczen
{
        string imie, nazwisko,pesel,adres;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
        		void wczytajZPliku(const char *);  
                void wypisz();
                void zapiszDoPliku(const char *);
                              
};

void klasa::wczytajZPliku(const char *nazwa)
{
        struct uczen dane;
ifstream plik1;
plik1.open(nazwa);  

   if(plik1.good())  
            while(!plik1.eof())  
                 {
                 plik1  >> dane.numer;
                  plik1  >> dane.imie;
                   plik1  >> dane.nazwisko;
		    plik1  >> dane.pesel;
                     plik1  >> dane.adres;  
                         spis.push_back(dane); 
                 }
                   plik1.close();  

}



void klasa::wypisz()
{
		string napis;
		ifstream plik;
		    plik.open("a.txt");
		    if(plik.good())
		     while(!plik.eof())
		
		    {
		        plik>>napis;
		        cout<<napis;
		        cout<<endl; 
		    }
		    plik.close();
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                  plik <<"["<<"{"<<it->numer<<":"<<it->imie<<":"<<it->nazwisko<<":"<<it->pesel<<":"<<it->adres<<"}"<<"]"<< "\n";
              	  cout <<"["<<"{"<<it->numer<<":"<<it->imie<<":"<<it->nazwisko<<":"<<it->pesel<<":"<<it->adres<<"}"<<"]"<< "\n";
        }
        plik.close();  
}




int main(int argc, char** argv) {
        klasa TI;
        TI.wczytajZPliku("b.txt");
        TI.wypisz();
        TI.zapiszDoPliku("a.txt");
        return 0;
}
