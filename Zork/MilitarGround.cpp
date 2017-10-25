#include <iostream>
#include <stdlib.h>
#include "Item.h"
#include "Soldier.h"
#include "MilitarGround.h"
#include <time.h>
using namespace std;

MilitaryGround::MilitaryGround()
{
}
MilitaryGround::~MilitaryGround()
{
}
/*First Ground*/
void MilitaryGround::GroundA() {}
/*Second Ground - Intersection*/
void MilitaryGround::GroundB() {}
/*Second-1A Ground - Coast*/
void MilitaryGround::GroundC() {}
/*Second-1B Ground - Bunker*/
void MilitaryGround::GroundD() {}
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
		}
		if (number < numberPlayer) {
			cout << "Error: The number is upper...\n";
		}
	} while ((number != numberPlayer) && (tries <20));
	cout << "Congratulations you can access to the laboratory!";
}
/*Second-4 Ground - Last*/
void MilitaryGround::GroundH() {}