// ConsoleApplication1.cpp: главный файл проекта.

#include "stdafx.h"
#include "lib_yanchuk.h"
#include <iostream>

int main() {/*
	int n,k;
	cout << "Enter the size of the field: ";
	cin >> n;

	tick_tack game(n);
	game.play();
*/
	while (true){
		int n,k;
		cout << "Enter the size of the field: ";
		cin >> n;

		tick_tack game(n);
		game.play();
		int t;
		cout << "1 - play again" << endl;
		cout << "0 - end" << endl;
		cout << "Your choise: ";
		cin >> t;
		if (t == 1) continue;
		if (t == 0) break;
		if (t != 1 || t != 0){
			cout << "1 - play again" << endl;
			cout << "0 - end" << endl;
			cout << "Your choise: ";
			cin >> t;
		}
	}

}