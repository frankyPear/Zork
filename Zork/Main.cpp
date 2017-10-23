#include "stdio.h"
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
using namespace std;
/*Inicio Zork*/
/*Inicio listas luego tiene que pasar a Item*/

struct item
{
	int zone;
	string itemName;
	string actionItem;
	int uses;
	item *next;
};
struct zone {
	int number;
	string type;
	zone *next;
};


void createZone(zone *&, int,string);
void createItem(item *&, int, string, string,int);
int main() {
	zone *list = NULL;
	item *mapinventory;
	createZone(list, 1,"FIELD1");
	createZone(list, 2,"FIELD2");
	createZone(list, 3,"FIELD3");
	createItem(mapinventory, 1, "Apple","Health",1);
	createItem(mapinventory, 2, "Sword","Attack",3);
	createItem(mapinventory, 2, "Key", "Open",1);
	createItem(mapinventory, 3, "Heavy Sword", "Attack", 3);//Falta assignar puntos de vida
	createItem(mapinventory, 3, "Melon","Health",1); //Falta assignar puntos de vida

	
	//nodos
	system("pause>>null");
	string input_command;
	
	vector<string> args;
	cout << "Hi ZorkWorld! Please say something....\n";
	
	while (true) {
		if (!kbhit() != 0) {

			getline(cin, input_command);
			
		}
			//system("pause");
			//break;
			//std::cout << "00:00" << "Time you waste";
		if (/*args.size() > 0 &&*/ input_command == "quit") {
			std::cout << "Bye";
			return 0;
		}
		
	}
	return 0;
}
void createZone(zone *&list,int n,string z) {
	zone *new_node = new zone();
	new_node->number = n;
	new_node->type = z;
	zone *aux1 = list;
	zone *aux2;
	while ((aux1 != NULL) && (aux1->number < n)){
		aux2 = aux1;
		aux1 = aux1->next;
	}
	if (list == aux1) {
		list = new_node;
	}
	else {
		aux2->next = aux1;
	}
}

void createItem(item *&list, int n, string itemName,string actionItem,int uses) {
	item *new_item = new item();
	new_item-> zone= n;
	new_item->itemName = itemName;
	new_item->actionItem = actionItem;
	new_item->uses = uses;

	item *aux1 = list;
	item *aux2;
	while ((aux1 != NULL) /*&& (aux1->zone < n)*/) {
		aux2 = aux1;
		aux1 = aux1->next;
	}
	if (list == aux1) {
		list = new_item;
	}
	else {
		aux2->next = aux1;
	}
}
/*Mostrar Inventario*/
void showInventoryZone(item *itemList) {
	item *current = new item();
	current = itemList;
	while (current != NULL) {
		cout << "Your inventory is: Zone" << current->zone << " Object: " << current->itemName << " Action: " << current->actionItem << " Uses: " << current->uses;
	}

}

string readString() {
	return "OK";
}