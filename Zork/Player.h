#include <iostream>

using namespace std;

class Player {
public:
	Player();
	~Player();
	void Use();
	void Go();
	void Pick();
	void Drop();
	void Look(int mGround);
	void Init();

	void Show();

	int GetLifes() const;

	void SetLifes(int lif);

	int ModifyLifes(int lifesToModify, bool minus);

private:
	int lifes = 0;
};