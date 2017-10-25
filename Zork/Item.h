#include <iostream>

using namespace std;

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