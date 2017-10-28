#include <iostream>
#include <stdlib.h>
#include "Item.h"
#include "Soldier.h"
#include "Player.h"
#include "MilitarGround.h"
#include <time.h>
using namespace std;
Player player_public;
MilitaryGround::MilitaryGround()
{
}
MilitaryGround::~MilitaryGround()
{
}
/*First Ground*/
void MilitaryGround::GroundA() {
	player_public.SetLifes(35);
}
/*Second Ground - Intersection*/
void MilitaryGround::GroundB() {}
/*Second-1A Ground - Coast*/
void MilitaryGround::GroundC() {
	/*Combat*/
	player_public.ModifyLifes(25, true);
}
/*Second-1B Ground - Bunker*/
void MilitaryGround::GroundD() {
	/*Combat*/
	player_public.ModifyLifes(25, true);
}
/*Second-2 Ground - Mountains*/
void MilitaryGround::GroundE() {}
/*Second-3 Ground - Entrance Base*/
void MilitaryGround::GroundF() {}
/*Second-4 Ground - Gas Camera*/
void MilitaryGround::GroundG() {
	int number, numberPlayer, tries = 0;
	srand(time(NULL));
	numberPlayer = 1 + rand() % (100);
	do {
		cout << "Tell me the number between 1 to 100: "; cin >> number;
		if (number > numberPlayer) {
			cout << "\nError: The number is lower...\n";
			player_public.ModifyLifes(1, true);
		}
		if (number < numberPlayer) {
			cout << "Error: The number is upper...\n";
			player_public.ModifyLifes(1, true);
		}
	} while ((number != numberPlayer) && (tries <20));
	cout << "Congratulations you can access to the laboratory!";
}
/*Second-4 Ground - Last*/
void MilitaryGround::GroundH() {
	/*Combat*/
	player_public.ModifyLifes(25, true);
}

void MilitaryGround::SetmGround(int ground)
{

}

int MilitaryGround::GetmGround()
{
	return groundType();
}
