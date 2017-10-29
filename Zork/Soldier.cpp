#include <iostream>
#include <stdlib.h>
#include "Item.h"
#include "Soldier.h"

using namespace std;
Soldier s;
Soldier::Soldier()
{
	lifeEnemy = 15;
}
Soldier::~Soldier()
{
}
void Soldier::Attack()
{
	cout << "Enemy attack" << endl;
	ModifyEnemyLifes(15, true);
}
bool Soldier::Die()
{
	if (GetEnemyLifes() <= 0) {
		return true;
	}
	return false;
}
int Soldier::ModifyEnemyLifes(int lifesToModify, bool minus)
{
	int lif = lifeEnemy;
	if (minus) {
		lif -= lifesToModify;
		cout << "Enemy loose " << lifesToModify << " life points.\n " << "Enemy life is about " << lif << "points." << endl;
	}
	else {
		lif += lifesToModify;
		cout << "Enemy earn " << lifesToModify << " life points.\n " << "Enemy life is about " << lif << "points." << endl;
	}

	SetEnemyLifes(lif);
	if (Die()) {
		cout << "The soldier is dead." << endl;
	}
	return lif;
}

/*gGets & Setters*/
int Soldier::GetEnemyLifes()
{
	return lifeEnemy;
}
void Soldier::SetEnemyLifes(int lif)
{
	lifeEnemy = lif;
}