#include <iostream>
#include "Player.h"
#include "MilitarGround.h"
//Player::Player() {
//
//}
//
//~Player::Player() {
//
//}
Player::Player()
{
}

Player::~Player()
{
}
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
void Player::Look()
{
	//First place
	int mGround = 0;
	switch(mGround) {
	case 1:
		cout << "You are near from the military base in north corea." << endl;
		cout << "There is one way in front of you you can't acces to other sites." << endl;
		cout << "Remember that your life is about 20 points" << endl;
		cout << "There is a medical kit in the ground." << endl;
	break;
	case 2:
		//Second place
		cout << "In your position you have 3 diferent ways to go there." << endl;
		cout << "The first way is in front of you." << endl;
		cout << "If you go there you will access directly to the base." << endl;
		cout << "Remember that your life is about 20 points." << endl;
		cout << "The second way is going around the coast. It's seems more pacefull" << endl;
		cout << "The third way is trying to go at mountains." << endl;
		cout << "There is a small knife in the groud." << endl;
	break;
	case 3:
		//Second-1 (Coast) place
		cout << "You see the sea and one soldier but he doesn't know your presence." << endl;
		cout << "The soldier is in the middle of bunker place." << endl;
		cout << "Remember that your life is about 20 points." << endl;
		cout << "You look a bag near from a palmatree." << endl;
		cout << "Also there are a tent to the other site." << endl;
	break;
	case 4:
		//Second-2 (Búnker) place
		cout << "The bunker is so smaller." << endl;
		cout << "You look a uzi weapon with 2 chargers" << endl;
		cout << "Also you found a huge key." << endl;
	break;
	case 5:
		//Second-3 (Mountains) place
		cout << "You are trying to access into the facility but it's impossible frome here" << endl;
		cout << "One sniper shoot you and you loose 5 life points" << endl;
		cout << "If you stay here you will die there." << endl;
	break;
	case 6:
		//Second-4 (Facility) place
		cout << "You are in front to the base and also there are no soldiers." << endl;
		cout << "You look a giant door. You need a key to open it." << endl;
		cout << "There are no items in the ground. Only dead animals and humans." << endl;
	break;
	case 7:
		//Third (Facility) place
		cout << "Once you go inside. The ground falls down...It's a Trap." << endl;
		cout << "You loose 5 life points..." << endl;
		cout << "You get up from the ground and you see only a panel. There are no other things in there." << endl;
		cout << "In the panel show a message that you need to put a code Number." << endl;
		cout << "If you fail 20 times you will die by a toxic gas..." << endl;
		cout << "Put a number in the panel from 1 to 100." << endl;
		cout << "You need to put a lower number" << endl;
		cout << "You need to put a upper number" << endl;
	break;
	case 8:
		//Fourth-Last (Facility) place
		cout << "You safe....." << endl;
		cout << "You just arrive to the control zone. You see the biological weapon!!" << endl;
		cout << "You pick some photos with your phone and send to your superior." << endl;
		cout << "Congratulations!!!!Your mission is complete ....mmmm wait." << endl;
		cout << "One general shoots you and you loose 5 life points." << endl;
		cout << "You kill the general!!! You are safe!!!!!" << endl;
		cout << "You exit to the military base and one chopper is waiting for you." << endl;
		cout << "Thanks for playing!!!!!" << endl;
	break;
	}
}
