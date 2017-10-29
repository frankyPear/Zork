#include "World.h"
#include "Player.h"
#include "Item.h"
#include "MilitarGround.h"
#include "Soldier.h"
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
//Soldier* s = nullptr;
Soldier *s_public = new Soldier();
Item i;
Item* item;
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
						if(s_public->Die()){
							ground.SetmGround(ground.GetmGround() + 3);
							p->Look(ground.GetmGround());
						}
						else {
							cout << "Another enemy detects you...He shoots you while you're trying to escape" << endl;
							ground.GroundC();//(10, true);//Attack();
							ground.SetmGround(ground.GetmGround() + 3);
							p->Look(ground.GetmGround());
						}
						break;
					case 3:						
						if(item->searchKey()){
							cout << "You use the key and you can access to the military base!"<<endl;
							ground.SetmGround(ground.GetmGround() + 3);
							p->Look(ground.GetmGround());
						}
						else {
							cout << "You need a key to acces..." << endl;
						}
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
						if (s_public->Die()) {
							cout << "The Soldier is dead. You can acces to the bunker to the east" << endl;
							cout << "Or go north to look if you can access to the base." << endl;
						}
						else {
							cout << "You see the sea and one soldier but he doesn't know your presence." << endl;
							cout << "The soldier is in the middle of bunker place." << endl;
						}
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

				if (vectArgs[0].compare("USE") == 0 && vectArgs[1].compare("KEY")==0)
				{
					if (item->searchKey()) {
						cout << "You use the key and you can access to the military base!" << endl;
						ground.SetmGround(ground.GetmGround() + 3);
						p->Look(ground.GetmGround());
					}
					else {
						cout << "You need a key to acces..." << endl;
					}
				}				
				if (vectArgs[0].compare("USE") == 0 && ((vectArgs[1].compare("GUN")) ==0 || (vectArgs[1].compare("KNIFE")) ==0 || (vectArgs[1].compare("UZI")) == 0))
				{
					if (item->searchWeapon(vectArgs[1])) {
						cout << "You use the "<<vectArgs[1]<< " Good Luck!" << endl;
						ground.GroundC2();
						//s->ModifyLifes(10,true);
					}
					else {
						cout << "You are attacked by the soldier..." << endl;
						ground.GroundC();
						//p->ModifyLifes(10, true);
					}
				}
				if (vectArgs[0].compare("USE") == 0 && (vectArgs[1].compare("MEDICALKIT") == 0 || vectArgs[1].compare("SPRAY") == 0))
				{
					item->Use(vectArgs[1]); 
				}

				/*PICK COMMAND*/
				if (vectArgs[0].compare("PICK") == 0)
				{
					i.Pick(ground.GetmGround(), vectArgs[1]);
				}
				
				/*DROP COMMAND*/
				if (vectArgs[0].compare("DROP") == 0)
				{
					i.Drop(ground.GetmGround(),vectArgs[1]);
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



