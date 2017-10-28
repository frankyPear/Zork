#include <string>
#include <vector>
using namespace std;

class Player;

class World
{
public:
	World();
	~World();

	void convertToVector(const string& sentence, vector<string>& vectArgs);

};