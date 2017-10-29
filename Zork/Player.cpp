#include <iostream>
#include "Player.h"
#include "MilitarGround.h"
#include "World.h"
#include "Item.h"
MilitaryGround* ground = nullptr;
World wrld;
Item* it2 = nullptr;
Player::Player()
{
	lifes = 25;
}

Player::~Player()
{
}
/*ACTIONS
1.-Use
2.-Go
3.-Pick
4.-Drop
5.-Look
6.-Show
*/
void Player::Use()
{
}
void Player::Go()
{
}
void Player::Pick()
{
}
void Player::Drop()
{
}
void Player::Look(int mGround)
{
	//item it = new item();
	switch(mGround) {
	case 0:
		cout << "You are near from the military base in north corea." << endl;
		cout << "There is one way in the south but you can't acces to other sites." << endl;
		it2->searchZone(mGround);
		ground->GroundA();
	break;
	case 1:
		//Intersection place
		cout << "In your position you have 2 diferent ways." << endl;
		cout << "The first way is to the south where you can see the sea." << endl;
		cout << "The second way is to the east where you can see the military base" << endl;
		cout << "but it's too far yet. " << endl;
		it2->searchZone(mGround);
		ground->GroundB();
	break;
	case 2:
		//Second-1 (Coast) place
		it2->searchZone(mGround);
		//ground->GroundC();
	break;
	case 3:
		//Death Point
		cout << "In your position there are to ways: One in the north around the lake." << endl;
		cout << "Or if you trespassing the door the huge door you can access to military base by east." << endl;
		it2->searchZone(mGround);
		ground->GroundD();
		break;
	case 4:
		//Second-3 (Mountains) place
		cout << "You are trying to access into the facility from the lake place but it's impossible from there." << endl;
		cout << "One sniper shoots you!." << endl;
		cout << "It's to far to use any weapon." << endl;
		cout << "If you stay here you will die there." << endl;
		it2->searchZone(mGround);
		ground->GroundE();
	break;
	case 5:
		//Second-2 (Búnker) place
		cout << "The bunker is so smaller." << endl;
		//cout << "Also you found a huge key. You can pick it." << endl;
		it2->searchZone(mGround);
		ground->GroundF();
		break;
	case 6:
		//Third (Facility) place
		cout << "You are in front to the base and also there are no soldiers." << endl;
		cout << "You look a giant door. You need a key to open it." << endl;
		cout << "There are no items in the ground. Only dead animals and humans." << endl;
		cout << "Once you go inside. The doors closed... It's a Trap." << endl;
		cout << "In this place you see a panel. There are no other things in there." << endl;
		cout << "In the panel show a message that you need to put a code Number." << endl;
		cout << "Your life grows down by a toxic gas..." << endl;
		cout << "You need to put the correct number to escape..." << endl;
		ground->GroundG();
	break;
	case 7:
		//Fourth-Last (Facility) place
		cout << "You safe....." << endl;
		cout << "You just arrive to the control zone. You see the biological weapon!!" << endl;
		cout << "You pick an experimental glass with extrange liquid." << endl;
		cout << "Congratulations!!!!Your mission is complete!" << endl;
		cout << "You exit to the military base and one chopper is waiting for you." << endl;
		cout << "Thanks for playing!!!!!" << endl;
		cout << "GAME OVER! See you next time" << endl;
		system("pause");	
		exit(0);
		break;
	}
}
void Player::Init()
{
	cout << "Hi Soldier. Your mission is the next one..." << endl;
	cout << "You need to infiltrate to the military base and obtain the biological weapon." << endl;
	cout << "Try to keep in safe ...There are a lot of soldiers around the facility." << endl;
	cout << "Now is your turn. Follow the instructions that i message on your phone." << endl;
	cout << "Good luck!. Let's begin..." << endl;
	Show();
	Look(0);
}
void Player::Show()
{
	it2->showInventory();
}

int Player::ModifyLifes(int lifesToModify, bool minus)
{
	int lif = lifes;
	if (minus) {
		lif -= lifesToModify;
		cout << "You loose " << lifesToModify << " life points.\n "<<"Your life is about " << lif << "points." << endl;
	}
	else {
		lif += lifesToModify;
		cout << "You earn " << lifesToModify << " life points.\n " << "Your life is about " << lif << "points." << endl;
	}
	if (lif <= 0) {
		cout << "GAME OVER! You are dead. Thanks for playing." << endl;
		system("pause");
		exit(0);
	}

	SetLifes(lif);
	return lif;
}

/*gGets & Setters*/
int Player::GetLifes() const
{
	return lifes;
}
void Player::SetLifes(int lif)
{
	lifes = lif;
}

