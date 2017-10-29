#include <iostream>
#include <ostream>
#include <stdlib.h>
#include "Item.h"
#include <string>
#include <conio.h>
#include "Player.h"
#include "MilitarGround.h"
using namespace std;
/*Inicio listas*/
item* listZone;
item* listInventory;
Player p;
//MilitaryGround* ground;
//void createZone(zone *&, int, string);
void createItem(item *&, int, string, string, int);
Item::Item()
{
}
Item::~Item()
{
}


void Item::initZones()
{
	item *initialList = new item();
	insertList(initialList, 0, "MEDICALKIT", "HEALTH", 1, 5);
	insertList(initialList, 1, "KNIFE", "ATTACK", 1, 10);
	insertList(initialList, 2, "GUN", "ATTACK", 3, 15);
	insertList(initialList, 3, "SPRAY", "HEALTH", 1, 15);
	insertList(initialList, 5, "UZI", "ATTACK", 1, 25);
	insertList(initialList, 5, "KEY", "USE", 1, 1);
}

void Item::insertList(item *& list, int n, string itemN, string actionItem, int uses, int life)
{
	item *newItem = new item();
	newItem->zone = n;
	newItem->itemName = itemN;
	newItem->actionItem = actionItem;
	newItem->uses = uses;
	newItem->life = life;
	item *aux1 = list;
	item *aux2;
	while ((aux1 != NULL) && (aux1->zone < n)) {
		aux2 = aux1;
		aux1 = aux1->next;
	}
	if (list == aux1) {
		list = newItem;
	}
	else {
		aux2->next = newItem;
	}
	newItem->next = aux1;
	listZone = list;
}

void Item::deleteList(item *list, int zone, string obj) {

	if (list != NULL) {
		item *aux_delete;
		item *lastItem = NULL;

		aux_delete = list;
		while ((aux_delete != NULL) && (aux_delete->zone != zone)){
			lastItem = aux_delete;
			aux_delete = aux_delete->next;
		}
		if (aux_delete == NULL) {
			cout << "Not Found!" << endl;
		}else if (lastItem == NULL){
			list->zone = -1;
			list = list->next;
			//delete aux_delete;
		}
		else {
			lastItem->zone = -1;
			//lastItem->next = aux_delete->next;
			//delete aux_delete;
		}
	}
}

void Item::deleteListInventory(item *list, int zone, string obj) {

	if (list != NULL) {
		item *aux_delete;
		item *lastItem = NULL;

		aux_delete = list;
		while ((aux_delete != NULL) && (aux_delete->zone != -1/*zone*/)) {
			lastItem = aux_delete;
			aux_delete = aux_delete->next;
		}
		if (aux_delete == NULL) {
			cout << "Not Found!" << endl;
		}
		else if (lastItem == NULL) {
			list->zone = zone;
			list = list->next;
			//delete aux_delete;
		}
		else {
			lastItem->zone = -1;
			//lastItem->next = aux_delete->next;
			//delete aux_delete;
		}
	}
}

void Item::SetList(item * newList)
{
	list = newList;
}

item Item::GetItems() const
{
	return* list;
}

void Item::SetItems(item *&list)
{
	list = list;
}

void Item::Pick(int zone,string obj)
{
	if (searchToPick(listZone,listInventory,zone, obj)) {
		cout << "You pick a " << obj << endl;
	}
	else {
		cout << "Nothing to pick a " <<obj<<" at this zone..." << endl;
	}
}

void createItem(item *&list, int n, string itemName, string actionItem, int uses) {
	item *new_item = new item();
	new_item->zone = n;
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

/*Search Type*/
bool Item::searchToPick(item *&listZone, item *&listInventory, int zone, string obj) {
	bool found = false;
	item *current = listZone;
	while ((current != NULL) && current->zone <= zone) {
		if (current->zone == zone) {
			found = true;
			insertInventory(listInventory, zone, obj, current->actionItem, current->uses, current->life);
			deleteList(current, zone, obj);
			break;
		}
		current = current->next;
		//if (current->zone < 0)break;
	}
	return found;
}

bool Item::searchToDrop(item *&listZone, item *&listInventory, int zone, string obj) {
	bool found = false;
	item *current = listInventory;
	while ((current != NULL)){// && current->zone <= zone) {
		if (current->zone == -1 && current->itemName==obj) {
			found = true;
			//listZone->next;
			listZone->zone = zone;
			listZone->itemName = obj;
			listZone->uses = listInventory->uses;
			listZone->life = listInventory->life;
			listZone->actionItem = listInventory->actionItem;
			//insertItemZone(listZone, zone, obj, current->uses, current->life);
			deleteListInventory(current, zone, obj);
			break;
		}
		current = current->next;
	}
	return found;
}

void Item::insertItemZone(item *list, int zone, string obj, int use, int lif) {

	if (list != NULL) {
		item *aux_modify;
		item *lastItem = NULL;

		aux_modify = list;
		while ((aux_modify != NULL) && (aux_modify->zone != /*zone*/-1)) {
			lastItem = aux_modify;
			aux_modify = aux_modify->next;
		}
		if (aux_modify == NULL) {
			cout << "Not Found in your inventory!" << endl;
		}
		else if (lastItem == NULL) {
			list->zone = zone;
			list->uses = use;
			list->life = lif;
			list = list->next;
			//delete aux_modify;
		}
		else {
			aux_modify->zone = zone;
			lastItem->zone = zone;
			list->zone = zone;
			list->uses = use;
			list->life = lif;
			//lastItem->next = aux_delete->next;
			//delete aux_modify;
		}
	}
}

void Item::searchZone(int zone) {
	bool found = false;
	item *current = listZone;
	while ((current != NULL) && current->zone <= zone) {
		if (current->zone == zone && current->uses>0) {
			found = true;
			cout << "You see a " << current->itemName << " -> " << "for " << current->uses << "use/s" << endl;
		}
		current = current->next;
	}
	if (!found) {
		cout << "There are no items in this zone!" << endl;
	}
}

/*Inventory - Player*/
void Item::insertInventory(item *&listInventory, int n, string itemName, string actionItem, int uses, int life) {
	item *newItem = new item();
	newItem->zone = -1;
	newItem->itemName = itemName;
	newItem->actionItem = actionItem;
	newItem->uses = uses;
	newItem->life = life;
	item *aux1 = listInventory;
	item *aux2;
	while ((aux1 != NULL) && (aux1->zone < n)) {
		aux2 = aux1;
		aux1 = aux1->next;
	}
	if (listInventory == aux1) {
		listInventory = newItem;
	}
	else {
		aux2->next = newItem;
	}
	newItem->next = aux1;
}

void Item::showInventory(/*item *list*/)
{
	item *invent = new item();
	bool found = false;
	invent = listInventory;
	while (invent != NULL) {
		//if (invent->zone /*!=*/< 0)
		if (invent->zone != -1) {}
		else
		{
			found = true;
			cout << "Inventory: " << invent->itemName << " -> Remaining uses: " << invent->uses << endl;
		}
		invent = invent->next;
	}
	if (found) {
		cout << "In your inventory you have..." << endl;
	}
	else {
		cout << "You don't have anything in your inventory..." << endl;
	}
	//searchList(list, 1);
}

void Item::Drop(int zone, string invent)
{
	if (searchToDrop(listZone, listInventory, zone, invent)) {
		cout << "You drop on the ground a " << invent << endl;
	}
	else {
		cout << "You can't drop an item that you don't have..." << endl;
	}
}
bool Item::searchKey() {
	return searchToDrop(listZone, listInventory, 0, "KEY");
}
bool Item::searchWeapon(string obj) {
	return searchToDrop(listZone, listInventory, 0, obj);
}
bool Item::searchList(item *listInventory, string itemInv) {
	bool found = false;

	item *current = new item();
	current = listInventory;
	while (current != NULL) {
		if (current->itemName == itemInv && current->uses>0) {
			found = true;
			current->uses = current->uses - 1;
			break;
		}
		current = current->next;
	}
	return found;
}
void Item::Use(string item)
{
	if (searchList(listInventory, item)) {
		if (item.compare("MEDICALKIT")==0) p.ModifyLifes(listInventory->life, false);
		if (item.compare("SPRAY") == 0) p.ModifyLifes(listInventory->life, false);
		if (item.compare("KEY") == 0) {
//			if(ground.mGround && searchToDrop(listZone, listInventory, 0, "KEY")){
//				mG.SetOpen(true);
//				//p.Look(3);
//			}
		}
	}
	else {
		cout << "You don't have this Item." << endl;
	}
}
