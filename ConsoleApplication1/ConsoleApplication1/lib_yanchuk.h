#pragma once
#include <vector>
using namespace std;
class tick_tack {
	
public:
	tick_tack(int number);
	~tick_tack(void);
	void play(void);
private:
	int check(void);
	int check(int i, int j, int x, int y);
	bool strok_check(int i, int j);
	int next_player(int number);
	void print(void);
	void stroke(int i, int j, int player);
	int first;
	vector < vector <int> > matr;
};