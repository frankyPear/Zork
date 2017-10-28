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
using namespace std;
/*Inicio Zork*/


Player* player = nullptr;
MilitaryGround* ground2 = nullptr;
//Afegim World
World world;



int main() {

	string input_command;
	char key;
//	ground.
	vector<string> args;
	cout << "Hi ZorkWorld!....\n";
	player->Init();
	//ground2->GroundA();
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
				//convert
				cout << input_command <<endl;
				world.convertToVector(input_command, args);
			}
			/**/

			//getline(cin, input_command);
			
		}
		if (args.size() > 0 && input_command == "quit") {
			std::cout << "Bye! See you next time";
			return 0;
		}
		//ground2->GroundG();
		//break;
	}
	return 0;
}

string readString() {
	return "OK";
}