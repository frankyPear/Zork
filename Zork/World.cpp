#include "World.h"

//void convert(const string& line, vector<string>& args) {
//	const char* str = line.c_str();
//}

World::World()
{
}

World::~World()
{
}

void World::convertToVector(const string& sentence, vector<string>& vectArgs)
{
	//	const char* str = sentence.c_str();
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
