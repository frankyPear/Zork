#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Item.h"
#include "Soldier.h"
#include "Player.h"
#include "MilitarGround.h"
#include <time.h>
using namespace std;
Player player_public;
Soldier *s_public2 = new Soldier();
MilitaryGround gr;
MilitaryGround::MilitaryGround()
{
	//s_public->lifeEnemy = 25;
	//s_public->SetLifes(25);// .SetLifes(25);
}
MilitaryGround::~MilitaryGround()
{
}
/*First Ground*/
void MilitaryGround::GroundA() {	
}
/*Second Ground - Intersection*/
void MilitaryGround::GroundB() {}
/*Second-1A Ground - Coast*/
void MilitaryGround::GroundC() {
	/*Combat*/
	player_public.ModifyLifes(12, true);
}
void MilitaryGround::GroundC2() {
	//s_public->SetLifes(25);// .SetLifes(25);
	s_public2->ModifyEnemyLifes(10, true);
}
/*Second-1B Ground - Bunker*/
void MilitaryGround::GroundD() {
	/*Combat*/
	if (gr.GetOpen()) {
		cout << "The door is open! Now you are accessing to the military place! Good Luck!" << endl;
	}
	else {
		cout << "It's seems closed. You need the key to access in the military base." << endl;
	}
}
/*Second-2 Ground - Mountains*/
void MilitaryGround::GroundE() {
	player_public.ModifyLifes(5, true);
}
/*Second-3 Ground - Entrance Base*/
void MilitaryGround::GroundF() {}
/*Second-4 Ground - Gas Camera*/
void MilitaryGround::GroundG() {
	int number, numberPlayer, tries = 0;
	srand(time(NULL));
	char key;
	numberPlayer = 1 + rand() % (100);
	do {
		cout << "Tell me the number between 1 to 100: "; 
		if (!(std::cin >> number)) {
			std::cout << "The panel don't understand you!" << endl;
			cout << "I think that only accept numbers!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			player_public.ModifyLifes(1, true);
		}
		else{
			if (number > numberPlayer) {
				cout << "\nError: The number is lower...\n";
				player_public.ModifyLifes(1, true);
			}
			if (number < numberPlayer) {
				cout << "Error: The number is upper...\n";
				player_public.ModifyLifes(1, true);
			}		
		}		
	} while ((number != numberPlayer));
	cout << "Congratulations you can access to the laboratory!";
	GroundH();
}
/*Second-4 Ground - Last*/
void MilitaryGround::GroundH() {
	/*Combat*/
	player_public.Look(7);
	//player_public.ModifyLifes(25, true);
}

/*gGets & Setters*/
int MilitaryGround::GetmGround() const
{
	return mGround;
}
void MilitaryGround::SetmGround(int ground)
{
	mGround = ground;
}

bool MilitaryGround::GetOpen()
{
	return open;
}

void MilitaryGround::SetOpen(bool op)
{
	open = op;
}
