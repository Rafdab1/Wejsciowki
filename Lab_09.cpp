#include <cstdio>
#include <cmath>

using namespace std;

class trapez {
	float wspolrzedne_wierzcholkow[4][2] = { 0 };
	float dl_podstawy_dolnej = 0;
	float dl_podstawy_gornej = 0;
	float dl_ramienia = 0;
	float wysokosc = 0;
public:
	void dane_trapezu(float x, float y, float podstawa_dolna, float podstawa_gorna, float wysokosc);
	void wypisanie_danych_trapezu(void);
	void przeksztalcenie_wzgledem_n(float n);
};

void info(void)
{
	printf("====TRAPEZY===\n");
	printf("Autor: Piotr Dabrowski\n\n");
}

void trapez::dane_trapezu(float x, float y, float podstawa_dolna, float podstawa_gorna, float h)
{
	//podane dlugosci
	dl_podstawy_dolnej = abs(podstawa_dolna);
	dl_podstawy_gornej = abs(podstawa_gorna);
	wysokosc = abs(h);
	//1.dlugosc ramienia
	float roznica_podstaw = (dl_podstawy_dolnej - dl_podstawy_gornej) / 2;
	dl_ramienia = sqrt(roznica_podstaw * roznica_podstaw + wysokosc * wysokosc);
	//2.wyliczanie wspolrzednych
	//lewa dolna wsp	(A)
	wspolrzedne_wierzcholkow[0][0] = x;
	wspolrzedne_wierzcholkow[0][1] = y;
	//prawa dolna wsp	(B)
	wspolrzedne_wierzcholkow[1][0] = wspolrzedne_wierzcholkow[0][0] + dl_podstawy_dolnej;
	wspolrzedne_wierzcholkow[1][1] = wspolrzedne_wierzcholkow[0][1];
	//prawa gorna wsp	(C)
	wspolrzedne_wierzcholkow[2][0] = wspolrzedne_wierzcholkow[1][0] - roznica_podstaw;
	wspolrzedne_wierzcholkow[2][1] = wspolrzedne_wierzcholkow[0][1] + wysokosc;
	//lewa gorna wsp	(D)
	wspolrzedne_wierzcholkow[3][0] = wspolrzedne_wierzcholkow[2][0] - dl_podstawy_gornej;
	wspolrzedne_wierzcholkow[3][1] = wspolrzedne_wierzcholkow[2][1];
}

void trapez::wypisanie_danych_trapezu(void)
{
	printf("==========================\n");
	printf("Rozmiary figury:\n");
	printf("Podstawa dolna = %f\n", dl_podstawy_dolnej);
	printf("Podstawa gorna = %f\n", dl_podstawy_gornej);
	printf("Wysokosc = %f\n",wysokosc);
	printf("Dlugosc ramiona = %f\n",dl_ramienia);
	for (int i = 0; i < 4; i++)
		printf("%c:(%f, %f)\n",'A'+i,wspolrzedne_wierzcholkow[i][0],wspolrzedne_wierzcholkow[i][1]);
	printf("==========================\n\n");
}

void trapez::przeksztalcenie_wzgledem_n(float n)
{
	wspolrzedne_wierzcholkow[0][0] = -1 * wspolrzedne_wierzcholkow[0][0] + n;
	wspolrzedne_wierzcholkow[1][0] = -1 * wspolrzedne_wierzcholkow[1][0] + n;
	wspolrzedne_wierzcholkow[2][0] = -1 * wspolrzedne_wierzcholkow[2][0] + n;
	wspolrzedne_wierzcholkow[3][0] = -1 * wspolrzedne_wierzcholkow[3][0] + n;
}

int main() {
	info();
	trapez trapez1;
	trapez1.dane_trapezu(0, 0, 8, 10, 2);
	printf("Przed przeksztalceniem:\n");
	trapez1.wypisanie_danych_trapezu();
	trapez1.przeksztalcenie_wzgledem_n(-1);
	printf("Po przeksztalceniu nr 1:\n");
	trapez1.wypisanie_danych_trapezu();
	trapez1.przeksztalcenie_wzgledem_n(-1);
	printf("Po przeksztalceniu nr 2:\n");
	trapez1.wypisanie_danych_trapezu();
	return 0;
}