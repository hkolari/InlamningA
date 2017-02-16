#include "Timberlist.h"
#include "TimberRegister.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

void showCurrentStock(TimberList *list);

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Testing and stuff
	////1. Skapa ett objekt av typen TimberRegister(l�t startkapaciteten vara 2).
	cout << "-----------------------------------------" << endl;
	TimberList list(2);

	//2. L�gg in 2 virken.
	cout << "-----------------------------------------" << endl;
	list.addTimber("2x2", 2, 2.22);
	list.addTimber("3x3", 3, 3.33);
	showCurrentStock(&list);
	
	
	//3. L�gg till ytterligare ett virke(vilket ska medf�ra att arrayen i TimberRegister - objektet expanderar).
	cout << "-----------------------------------------" << endl;
	list.addTimber("4x4", 4, 4.44);
	showCurrentStock(&list);
	
	
	//4. F�rs�k ta bort ett virke som inte finns inlagt och kontrollera att ingen borttagning gjordes samt generera en utskrift av detta.
	cout << "-----------------------------------------" << endl;
	list.removeTimber("5x5");
	showCurrentStock(&list);
	
	//5. Ta bort ett virke som finns inlagt och kontrollera att borttagningen genomf�rts.
	cout << "-----------------------------------------" << endl;
	list.removeTimber("2x2");
	showCurrentStock(&list);
	
	//6. Tag bort de resterande 2 virkena fr�n TimberRegister - objektet och kontrollera att det d�refter inte inneh�ller n�gra virken.
	cout << "-----------------------------------------" << endl;
	list.removeTimber("4x4");
	list.removeTimber("3x3");
	showCurrentStock(&list);
	
	//7. L�gg till 2 nya virken till TimberRegister - objektet och kontrollera att dessa finns inlagda.
	cout << "-----------------------------------------" << endl;
	list.addTimber("8x8", 8, 8.88);
	list.addTimber("9x9", 9, 9.99);
	showCurrentStock(&list);
	
	//8. Testa p� l�mpligt s�tt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator. 
	//Avsluta programmet och kontrollera slutligen att inga minnesl�ckor uppt�ckts!
	cout << "-----------------------------------------" << endl;

	
	TimberList timb6 = list;
	timb6.addTimber("15x15", 15, 15.15);
	timb6 = list;

	getchar();
	return 0;
}

void showCurrentStock(TimberList *list)
{

	int stringArrLength = 0;
	if (list->getNr() == 0) {
		stringArrLength = 1;
	}
	else {
		stringArrLength = list->getNr();
	}
	string *arr = new string[stringArrLength];
	cout << "Current stock:" << endl;
	list->getTimberAsString(arr, list->getNr());
	for (int i = 0; i < stringArrLength; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;

}