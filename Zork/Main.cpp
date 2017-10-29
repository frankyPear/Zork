#include "stdio.h"
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "MilitarGround.h"
#include "World.h"
#include "Item.h"
using namespace std;
/*Inicio Zork*/

Player* player = nullptr;
Item* it = nullptr;
MilitaryGround* ground2 = nullptr;
//Afegim World
World world;

int main() {

	string input_command;
	char key;
	int ending = 0;
	vector<string> args;
	it->initZones();
	player->Init();	
	cout << endl;
	cout << "-->";
	while (true) {
		if (!kbhit() != 0) {
			key = _getch();
			if (key == '\b')
			{
				if(input_command.length()>0){
					input_command.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r')
			{
				input_command += key;
				cout << key;
			}
			else {
				//convert.
				cout << endl;
				/*Instructions*/
				world.convertToVector(input_command, args);
				world.worldInterpret(args);
				cout << endl;
			}		
		}
		if (args.size() > 0 && input_command == "quit") {
			cout << "Bye! See you next time";
			return 0;
		}
		/*Reset Params*/
		if (args.size()>0) { 
			args.clear(); 
			input_command = "";
			cout << "-->";
		}

	}
	return 0;
}