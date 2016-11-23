#include <iostream>
#include "TopSpin.h"
#include "CircularDoubleLinkedList.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main() {
	cout << "Welcome to TopSpin!" << endl << endl;
	int play = 1;
	int size = 0;
	cout << "Please enter the size of the board: "; cin >> size;
	while (size < 1) {
		cout << "\nInvalid size.\n";
		cout << "Please enter the size of the board:"; cin >> size;
	}
	TopSpin board(size);
	int spsize = 0;
	cout << "\nPlease enter the size of the spinner: "; cin >> spsize;
	while (size<0 || spsize>size) {
		cout << "Invalid size.\n";
		cout << "\nPlease enter the size of the spinner: "; cin >> spsize;
	}
	board.set_spsize(spsize);
	unsigned int moves = 0;
	cout << "\nHow many random moves?\n";
	cin >> moves;
	for (; moves > 0; moves--) {
		srand(unsigned int(time(NULL)));
		for (int i(rand() % 19); i > 0; i--) {
			board.shiftLeft();
		}
		board.spin();
	}
	
	while (play) {
		cout << board << endl;
		if (board.isSolved()) {
			break;
		}
		int x=0;
		cout << "Please choose from the following options enter your choice by entering the "
			"corresponding number : " << endl
			<< "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cin >> x;
		while (x < 1 || x>3) {
			cout << endl << "Invalid choice." << endl;
			cout << "Please choose from the following options enter your choice by entering the "
				"corresponding number : " << endl
				<< "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
			cin >> x;
		}
		switch (x) {
		case 1: {
			int y = 0;
			cout << "Shift left or right?\n1.Left\n2.Right\n";
			cin >> y;
			while (y < 1 || y>2) {
				cout << endl << "Invalid choice.\n";
				cout << "Shift left or right?\n1.Left\n2.Right\n";
				cin >> y;
			}
			int n = 0;
			cout << "How many shifts: ";
			cin >> n;
			while(n<0){
				cout << "\nInvalid input.\n";
				cout << "How many shifts: ";
				cin >> n;
			}
			switch (y) {
			case 1: {
				for (; n > 0; n--) {
					board.shiftLeft();
				}
			}
			case 2: {
				for (; n > 0; n--) {
					board.shiftRight();
				}
			}
			}
			break;
		}
		case 2: {
			board.spin();
			break;
		}
		case 3: {
			play = 0;
			break;
		}
		}
		
	}
	if (play) {
		cout << "\n\nCongratulations! You win!\n\n";
		return 0;
	}
	cout << "\n\nThanks for playing\n\n";
	return 0;
}