#include <iostream>

using namespace std;

enum itemType
{
	APPLE,
	MEDICALKIT,
	GUN,
	UZI,
	KEY,
	BAG
};

class Item {
public:
	Item();
	~Item();
	void Use();
	void Pick();
	void Drop();

private:
	void Attack();
	void Die();
};