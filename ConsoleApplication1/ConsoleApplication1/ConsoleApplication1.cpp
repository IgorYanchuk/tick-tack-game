// ConsoleApplication1.cpp: главный файл проекта.

#include "stdafx.h"
#include "lib_yanchuk.h"
#include <iostream>

int main() {
	while (true) {
		int n, k;
		cout << "Enter the size of the field: ";
		cin >> n;

		tick_tack game(n);

		int player;
		do {
			cout << "who goes first (only 1 or 2): ";
			cin >> player;
		} while (player != 1 && player != 2);
		int first = player;
		int inf = 0;
		while (inf == 0) {
			cout << "Player " << player << endl;
			game.print();
			int x, y;
			while (1 == 1) {
				cout << "Coordinates: ";
				cin >> x >> y;
				if (game.strok_check(x, y) == true) break;
				else cout << "Error! Repeat your choise!" << endl;
			}
			game.stroke(x, y, player);
			player = game.next_player(player);
			inf = game.check();
			system("pause");
			system("cls");
		}

		game.print();

		if (inf == 1) cout << "1 player is win!";
		if (inf == 2) cout << "2 player is win!";
		if (inf == 3) cout << "Draw!";
		cout << endl;


		int t;
		cout << "1 - play again" << endl;
		cout << "0 - end" << endl;
		cout << "Your choise: ";
		cin >> t;
		if (t == 1) continue;
		if (t == 0) break;
		if (t != 1 || t != 0) {
			cout << "1 - play again" << endl;
			cout << "0 - end" << endl;
			cout << "Your choise: ";
			cin >> t;
		}
	}

}