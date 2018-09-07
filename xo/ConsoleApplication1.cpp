// ConsoleApplication1.cpp: главный файл проекта.

#include "stdafx.h"
#include "lib_yanchuk.h"
#include <iostream>

int main() {
	int n,k;
	cout << "Enter the size of the field: ";
	cin >> n;

	tick_tack game(n);
	game.play();

}