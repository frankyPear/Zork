
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
	void GroundC2();
	void GroundD();
	void GroundE();
	void GroundF();
	void GroundG();
	void GroundH();
	int GetmGround() const;
	void SetmGround(int);
	bool GetOpen();
	void SetOpen(bool);
private:
	int mGround;
	bool open;
}; 
