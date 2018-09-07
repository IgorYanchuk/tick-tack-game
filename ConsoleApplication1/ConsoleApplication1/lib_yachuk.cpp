#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "lib_yanchuk.h"

tick_tack::tick_tack(int number) {
	matr.resize(number + 2);
	for (int i = 0; i <= number + 1; i++) {
		matr[i].resize(number+2);
	}

	for (int i = 0; i < matr.size(); i++) {
		for (int j = 0; j < matr[i].size(); j++) {
			matr[i][j] = 0;
		}
	}

	for (int i = 0; i < matr.size(); i++) {
		matr[0][i] = -1;
		matr[matr.size() - 1][i] = -1;
		matr[i][0] = -1;
		matr[i][matr.size() - 1] = -1;
	}
}
tick_tack::~tick_tack(void) {
	for (int i = 0; i < matr.size(); i++) {
		matr[i].clear();
	}
	matr.clear();
}
int tick_tack::check(int i, int j, int x, int y) {
	int flag = matr[i][j];
	while (matr[i][j] != -1) {
		if (matr[i][j] != flag) {
			flag = 0;
			break;
		}
		i += x;
		j += y;	}
	return flag;
}
int tick_tack::check(void) {
	int ans;
	for (int i = 1; i < matr.size() - 1; i++) {
		ans = check(1, i, 1, 0);
		if (ans != 0) return ans;
	}

	for (int i = 1; i < matr.size() - 1; i++) {
		ans = check(i, 1, 0, 1);
		if (ans != 0) return ans;
	}

	ans = check(1, 1, 1, 1);
	if (ans != 0) return ans;

	ans = check(1, matr.size()-2, 1, -1);
	if (ans != 0) return ans;

	ans = 3;
	for (int i = 1; i < matr.size()-1; i++) {
		for (int j = 1; j < matr[i].size() - 1; j++) {
			if (matr[i][j] == 0) return 0;
		}
	}
	return ans;
}
bool tick_tack::strok_check(int i, int j) {
	if (i > 0 && i < matr.size() - 1 && j>0 && j < matr.size() - 1);
	else return false;
	if (matr[i][j] == 0) return true;
	else return false;
}
int tick_tack::next_player(int number) {
	if (number == 1) return 2;
	else return 1;
}
void tick_tack::print(void) {

	for (int i = 1; i < (matr.size() - 1)*2; i++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 1; i < matr.size() - 1; i++) {
		cout << "|";
		for (int j = 1; j < matr[i].size() - 1; j++) {
			if (matr[i][j] == 1) cout << "x|";
			if (matr[i][j] == 2) cout << "o|";
			if (matr[i][j] == 0) cout << " |";
		}
		cout << endl;
		for (int i = 1; i < (matr.size() - 1)*2; i++) {
			cout << "-";
		}
		cout << endl;
	}
	cout << endl;
}
void tick_tack::stroke(int i, int j, int player) {
	matr[i][j] = player;
}
void tick_tack::play(void) {
	int player;
	do {
		cout << "who goes first (only 1 or 2): ";
		cin >> player;
	} 
	while (player != 1 && player != 2);
	first = player;
	int inf = 0;
	while (inf == 0) {
		cout << "Player " << player << endl;
		print();
		int x, y;
		while (1 == 1) {
			cout << "Coordinates: ";
			cin >> x >> y;
			if (strok_check(x, y) == true) break;
			else cout << "Error! Repeat your choise!" << endl;
		}
		stroke(x, y, player);
		player = next_player(player);
		inf = check();
		system("pause");
		system("cls");
	}

	print();

	if (inf == 1) cout << "1 player is win!";
	if (inf == 2) cout << "2 player is win!";
	if (inf == 3) cout << "Draw!";
	cout << endl;

}