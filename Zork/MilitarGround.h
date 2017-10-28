
enum groundType
{
	GROUNDA,
	GROUNDB,
	GROUNDC,
	GROUNDD,
	GROUNDE,
	GROUNDF,
	GROUNDG,
	GROUNDH
};

class MilitaryGround {
public:
	MilitaryGround();
	~MilitaryGround();
	void GroundA();
	void GroundB();
	void GroundC();
	void GroundD();
	void GroundE();
	void GroundF();
	void GroundG();
	void GroundH();
	void SetmGround(int);
	int GetmGround();
private:
	int mGround;
}; 
