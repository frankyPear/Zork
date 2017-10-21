#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
/*Inicio Zork*/
int main() {
	string input;
	int i = 0;
	vector<string> args;
	cout << "Hi ZorkWorld!\n";

	while (true) {
		while (!kbhit()) {
			cin >> i;
			system("pause");
			//break;
		}
	}
	return 0;
}
string readString() {
	return "OK";
}