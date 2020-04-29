#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct zakupy
{
int id;
float cena;
string nazwa;
};
struct owoce:public zakupy
{
int jakosc;
string jakiowoc,kolor;

};
struct warzywa:public zakupy

{
string kolor;
};

class sklep
{
	     vector <struct owoce> ile_owoc;

	      vector <struct warzywa> ile_warzyw;


	ifstream owoce;
	ifstream warzywa;
	ofstream zakupy;

public:
	sklep();
	~sklep();


void z_pliku();
void do_pliku();

};

sklep::sklep()
{

zakupy.open("plik1.txt");
owoce.open("plik2.txt");
warzywa.open("plik3.txt");
}

void sklep::z_pliku()
{
	struct owoce ilosc;
	struct warzywa rodzaj;
	while(!owoce.eof())
        {
		owoce>>ilosc.id>>ilosc.cena>>ilosc.nazwa>>ilosc.jakosc>>ilosc.jakiowoc>>ilosc.kolor;

		ile_owoc.push_back(ilosc);
		}
	while(!warzywa.eof())
    {
		warzywa>>rodzaj.id>>rodzaj.cena>>rodzaj.nazwa>>rodzaj.kolor;

		ile_warzyw.push_back(rodzaj);
	}
}

void sklep::do_pliku()
{
	zakupy<<"["<<endl;

	for(vector <struct owoce>::iterator it = ile_owoc.begin(); it != ile_owoc.end(); ++it)

    {

    zakupy<<"{\"rodzaj_zakupow"":\"\ilosc\", \"id\":\""<<it->id<<"\", \"cena\":\""<<it->cena<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"jakosc\":\""<<it->jakosc<<"\", \"jakiowoc\":\""<<it->jakiowoc<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;

    }

	for(vector <struct warzywa>::iterator it = ile_warzyw.begin(); it != ile_warzyw.end(); ++it)


	{

    zakupy<<"{\"rodzaj_zakupow"":\"\rodzaj\", \"id\":\""<<it->id<<"\", \"cena\":\""<<it->cena<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;

	}

	zakupy<<"]";
}
	sklep::~sklep()
{
owoce.close();
warzywa.close();
zakupy.close();
}

int main(int argc, char** argv)
{

sklep t1;
t1.z_pliku();
t1.do_pliku();

	return 0;
}
