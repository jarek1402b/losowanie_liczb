#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <unistd.h>

int losowanieliczb()
{
	int liczba = (rand()%100)+1;

return liczba;
}

int losowaniepytania()
{
	int pytanie = (rand()%3)+1;

return pytanie;
}

std::string pytanie(int numer_pytania)
{
		std::string napis1 = "Dodaj do siebie podane liczby :-)";
		std::string napis2 = "Odejmij od siebie podane liczby :-)";		
		std::string napis3 = "Pomnoz ze soba podane liczby :-)";

		if (numer_pytania==1)
			return napis1;
			
		if (numer_pytania==2)
			return napis2;
			
		if (numer_pytania==3)
			return napis3;
}

int dodawanie(int p, int d)
{
	int wynik = 0;
	
	wynik = p + d;

return wynik;
}

int odejmowanie(int p, int d)
{
	int wynik = 0;
	
	wynik = p - d;

return wynik;
}

int mnozenie(int p, int d)
{
	int wynik = 0;
	
	wynik = p * d;

return wynik;
}

bool sprawdzenie(int odpowiedz, int liczbaP, int liczbaD, int numerpytania)
{
	if (numerpytania==1)
	{
		if (dodawanie(liczbaP,liczbaD)==odpowiedz)
			return true;
		else
			return false;
	}
	
	if (numerpytania==2)
	{
		if (odejmowanie(liczbaP,liczbaD)==odpowiedz)
			return true;
		else
			return false;
	}

	if (numerpytania==3)
	{
		if (mnozenie(liczbaP,liczbaD)==odpowiedz)
			return true;
		else
			return false;
	}

}

int main(){
	
	std::cout << "Gra na ulepszenie swoich zdolnosci matematycznych" << std::endl;
	std::cout << "Za kazda dobrze udzielona odpwiedz otrzymujesz" << std::endl; 
	std::cout << "jeden punkt zas za kazda zle udzielona odpowiedz" << std::endl;
	std::cout << "tracisz jeden punkt." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "No to zaczynamy!!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Naciśnij ENTER aby przejść do pytań." << std::endl;
   	std::cin.get();
	system("clear");

	srand( time( NULL ) );
	
	int liczba1 = 0;
	int liczba2 = 0;
	int losowepytanie = 0;
	int odpowiedz = 0;
	int liczba_punktowD = 0;
	int liczba_punktowZ = 0;
	std::string ask;
	
	for (int i=0;i<10;i++)
	{
		liczba1 = losowanieliczb();
		liczba2 = losowanieliczb();

	
		losowepytanie = losowaniepytania();	

		if (liczba1 > 10 && liczba2 > 10 && losowepytanie==3)
			losowepytanie = losowaniepytania();

		ask = pytanie(losowepytanie);

		
		std::cout << ask << std::endl;
		std::cout << liczba1 << " i " << liczba2 << std::endl;

		std::cout << "Odpowiedz: ";
		std::cin >> odpowiedz;

		

		if (sprawdzenie(odpowiedz, liczba1, liczba2, losowepytanie)==true)
			liczba_punktowD++;
		else
			liczba_punktowZ--;

		system("clear");
	}
	
	std::cout << "Ilosc poprawnych odpowiedzi: " << liczba_punktowD << std::endl;	
	std::cout << "Ilosc blednych odpowiedzi: " << abs(liczba_punktowZ) << std::endl;
	
return 0;
}
