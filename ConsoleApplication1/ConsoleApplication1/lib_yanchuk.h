#pragma once
#include <vector>
using namespace std;
class tick_tack {

public:
	tick_tack(int number);
	~tick_tack(void);
	void print(void);
	int check(void);
	bool strok_check(int i, int j);
	int next_player(int number);
	void stroke(int i, int j, int player);
private:
	int check(int i, int j, int x, int y);
	vector < vector <int> > matr;
};