class Soldier {
public:
	Soldier();
	~Soldier();

	void Attack();

	bool Die();

	int ModifyEnemyLifes(int lifesToModify, bool minus);

	int GetLifes();

	int GetEnemyLifes();

	void SetEnemyLifes(int lif);

	void SetLifes(int lif);

//	int ModifyLifes(int lifesToModify, bool minus);
	
	

private:
	int lifeEnemy;

};