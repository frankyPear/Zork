#include <iostream>
#include <stdlib.h>
#include "Item.h"

using namespace std;
Item::Item()
{
}
Item::~Item()
{
}
void Item::Use()
{
	int uses=0;
	char Item[20];
	if (uses < 0) {
		cout << "You can't use this Item." << endl;
	}
	else {
		cout << "You use this Item." << endl;
	}
	delete[] Item;
}
void Item::Drop()
{
	cout << "You drop on the ground a small knife" << endl;
	cout << "You drop on the ground a Medical Kit" << endl;
	cout << "You drop on the ground a Gun" << endl;
	cout << "You drop on the ground a Uzi" << endl;
	cout << "You drop on the ground a charger for your Gun" << endl;
	cout << "You drop on the ground a charger for your Uzi" << endl;
}
void Item::Pick()
{
	cout << "You pick a small knife" << endl;
	cout << "You pick a Medical Kit" << endl;
	cout << "You pick a Gun with 2 chargers" << endl;
	cout << "You pick a Uzi with 2 chargers" << endl;
	cout << "You pick a charger for your Gun" << endl;
	cout << "You pick a charger for your Uzi" << endl;
}