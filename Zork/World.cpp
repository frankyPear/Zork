#include "World.h"
#include "Player.h"
#include "Item.h"
#include "MilitarGround.h"
#include <iostream>

enum command1
{
	USE,
	GO,
	PICK,
	DROP,
	LOOK
};
Player* p = nullptr;
Item i;
MilitaryGround ground;
World::World()
{
}

World::~World()
{
}
void World::worldInterpret(vector<string>& vectArgs) {
	int currentGround = ground.GetmGround();
		switch (vectArgs.size())
		{
			case 1:
				/*LOOK COMMAND*/
				if (vectArgs[0].compare("LOOK") == 0) {
					p->Look(ground.GetmGround());
				}
				break;
			case 2:
				/*SHOW COMMAND*/
				if (vectArgs[0].compare("SHOW") == 0 && vectArgs[1].compare("INVENTORY") == 0) 
				{
					p->Show();
				}

				/*GO DIRECTIONS*/
				if (vectArgs[0].compare("GO") == 0 && vectArgs[1].compare("NORTH") == 0) 
				{
					switch (currentGround)
					{
					case 1:
						ground.SetmGround(ground.GetmGround() - 1);
						p->Look(ground.GetmGround());
						break;
					case 2:
						ground.SetmGround(ground.GetmGround() - 1);
						p->Look(ground.GetmGround());
						break;
					case 3:
						ground.SetmGround(ground.GetmGround() + 1);
						p->Look(ground.GetmGround());
						break;
					default:
						cout << endl;
						cout << "You can't go at this direction...Try again";
						break;
					}
				}
				if (vectArgs[0].compare("GO") == 0 && vectArgs[1].compare("EAST") == 0) 
				{
					switch (currentGround)
					{
					case 1:
						ground.SetmGround(ground.GetmGround() + 2);
						p->Look(ground.GetmGround());
						break;
					case 2:
						ground.SetmGround(ground.GetmGround() + 3);
						p->Look(ground.GetmGround());
						break;
					case 3:
						ground.SetmGround(ground.GetmGround() + 3);
						p->Look(ground.GetmGround());
						break;
					default:
						cout << endl;
						cout << "You can't go at this direction...Try again";
						break;
					}
				}
				if (vectArgs[0].compare("GO") == 0 && vectArgs[1].compare("SOUTH") == 0) 
				{
					switch(currentGround)
					{
					case 0:
						ground.SetmGround(ground.GetmGround() + 1);
						p->Look(ground.GetmGround());
					break;
					case 1:
						ground.SetmGround(ground.GetmGround() + 1);
						p->Look(ground.GetmGround());
					break;
					case 4:
						ground.SetmGround(ground.GetmGround() - 1);
						p->Look(ground.GetmGround());
					break;
						default:
							cout << endl;
							cout << "You can't go at this direction...Try again";
							break;
					}
				}
				if (vectArgs[0].compare("GO") == 0 && vectArgs[1].compare("WEST") == 0) 
				{
					switch (currentGround)
					{
					case 3:
						ground.SetmGround(ground.GetmGround() - 2);
						p->Look(ground.GetmGround());
						break;
					case 5:
						ground.SetmGround(ground.GetmGround() - 3);
						p->Look(ground.GetmGround());
						break;
					default:
						cout << endl;
						cout << "You can't go at this direction...Try again";
						break;
					}
				}

				/*USE COMMAND*/

				if (vectArgs[0].compare("USE") == 0 && vectArgs[1].compare("MEDICALKIT") == 0) 
				{
					i.Use(vectArgs[1]);
				}
				if (vectArgs[0].compare("USE") == 0 && vectArgs[1].compare("KNIFE") == 0) 
				{
					
				}
				if (vectArgs[0].compare("USE") == 0 && vectArgs[1].compare("GUN") == 0) 
				{
					
				}
				if (vectArgs[0].compare("USE") == 0 && vectArgs[1].compare("SPRAY") == 0) {
					i.Use(vectArgs[1]);
				}
				
				/*PICK COMMAND*/
				if (vectArgs[0].compare("PICK") == 0 && vectArgs[1].compare("MEDICALKIT") == 0) {
					i.Pick(ground.GetmGround(), "MEDICALKIT");
				}
				if (vectArgs[0].compare("PICK") == 0 && vectArgs[1].compare("KNIFE") == 0) {
					i.Pick(ground.GetmGround(), "KNIFE");
				}
				if (vectArgs[0].compare("PICK") == 0 && vectArgs[1].compare("GUN") == 0) {
					i.Pick(ground.GetmGround(), "GUN");
				}
				if (vectArgs[0].compare("PICK") == 0 && vectArgs[1].compare("SPRAY") == 0) {
					i.Pick(ground.GetmGround(), "SPRAY");
				}
				if (vectArgs[0].compare("PICK") == 0 && vectArgs[1].compare("UZI") == 0) {
					i.Pick(ground.GetmGround(), "UZI");
				}
				
				/*DROP COMMAND*/
				if (vectArgs[0].compare("DROP") == 0 && vectArgs[1].compare("MEDICALKIT") == 0) {
					i.Drop(ground.GetmGround(),vectArgs[1]);
				}
				if (vectArgs[0].compare("DROP") == 0 && vectArgs[1].compare("APPLE") == 0) {
					i.Drop(ground.GetmGround(), vectArgs[1]);
				}
				if (vectArgs[0].compare("DROP") == 0 && vectArgs[1].compare("GUN") == 0) {
					i.Drop(ground.GetmGround(), vectArgs[1]);
				}
				if (vectArgs[0].compare("DROP") == 0 && vectArgs[1].compare("SPRAY") == 0) {
					i.Drop(ground.GetmGround(), vectArgs[1]);
				}
				if (vectArgs[0].compare("DROP") == 0 && vectArgs[1].compare("UZI") == 0) {
					i.Drop(ground.GetmGround(), vectArgs[1]);
				}

				break;
		default:
			cout << "Sorry i don't understand you..." << endl;
			break;
		}
}


void World::convertToVector(const string& sentence, vector<string>& vectArgs)
{
	char space = ' ';
	string line;
	for (int i = 0; i < sentence.length(); i++)
	{
		//if (sentence.substr(i, i + 1).compare('\r')) {}
		if (sentence[i]==' ') {
			vectArgs.push_back(line);
			line.clear();
		}
		else {
			line.append(sentence.substr(i, 1));
		}
	}
	vectArgs.push_back(line);
}



