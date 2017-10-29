#include <string>
#include <vector>
using namespace std;

class Player;

class World
{
public:
	World();
	~World();

	void worldInterpret(vector<string>& vectArgs);

	void convertToVector(const string& sentence, vector<string>& vectArgs);

private:
	int zone = 0;
};