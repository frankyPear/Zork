#include <iostream>

using namespace std;

struct item
{
	int zone;
	string itemName;
	string actionItem;
	int uses;
	int life;
	item *next;
};
class Item {
public:
	Item();
	~Item();
	item GetItems() const;
	void SetItems(item *& list);
	void Pick(int zone, string obj);
	bool searchToPick(item *& listZone, item *& listInventory, int zone, string obj);
	bool searchToDrop(item *& listZone, item *& listInventory, int zone, string obj);
	void insertItemZone(item * list, int zone, string obj, int use, int lif);
	void insertInventory(item *& list, int n, string itemName, string actionItem, int uses, int life);
	void initZones();
	void insertList(item *&list, int n, string itemN,
		string actionItem, int uses, int life);
	void showInventory();
	void Drop(int zone, string invent);
	bool searchKey();
	bool searchList(item * listInventory, string itemInv);
	void Use(string item);
	void searchZone(int zone);
	void deleteList(item * list, int zone, string obj);

	void deleteListInventory(item * list, int zone, string obj);
	
private:
	void SetList(item *list);
	item* list;
};