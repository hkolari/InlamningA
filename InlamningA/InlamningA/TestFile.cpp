#include "Timberlist.h"
#include "TimberRegister.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;


int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Testing and stuff
	////1. Skapa ett objekt av typen TimberRegister(låt startkapaciteten vara 2).
	TimberList list(2);

	//2. Lägg in 2 virken.
	Timber timb6 = Timber("15x15", 30, 69.99);

	/*
	//3. Lägg till ytterligare ett virke(vilket ska medföra att arrayen i TimberRegister - objektet expanderar).
	list.addTimber("4x4", 2, 7.99);

	//4. Försök ta bort ett virke som inte finns inlagt och kontrollera att ingen borttagning gjordes samt generera en utskrift av detta.
	list.removeTimber("5x5");
	cout << list.ShowAll() << endl;

	//5. Ta bort ett virke som finns inlagt och kontrollera att borttagningen genomförts.

	list.removeTimber("4x4");
	cout << "The list below should not contain '4x4'" << endl;
	cout << list.ShowAll() << endl;

	//6. Tag bort de resterande 2 virkena från TimberRegister - objektet och kontrollera att det därefter inte innehåller några virken.
	list.removeTimber("2x2");
	list.removeTimber("3x3");

	//7. Lägg till 2 nya virken till TimberRegister - objektet och kontrollera att dessa finns inlagda.
	list.addTimber("8x8", 12, 10.99);
	list.addTimber("9x9", 78, 12.99);
	cout << "The list below should not contain '2x2' or '3x3' anymore" << endl;

	//8. Testa på lämpligt sätt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator. 
	//Avsluta programmet och kontrollera slutligen att inga minnesläckor upptäckts!
	Timber timb6 = Timber("15x15", 30, 69.99);
	Timber timb7 = Timber("18x18", 20, 99.99);
	Timber timb8 = Timber(timb6);
	timb6 = timb7; // Vi använder tilldelningsoperatorn för att skriva över timb6 med timb7...
	
	*/

	getchar();
	return 0;
}