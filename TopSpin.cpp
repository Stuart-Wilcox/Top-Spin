#include "TopSpin.h"

TopSpin::TopSpin() {
	board = new CircularDoublyLinkedList<int>(20);
	sz = 20;
	spinsz = 4;
}

TopSpin::TopSpin(unsigned int a) {
	board = new CircularDoublyLinkedList<int>(a);
	sz = a;
	spinsz = 0;
}

void TopSpin::shiftLeft() {
	board->shiftL();
}

void TopSpin::shiftRight() {
	board->shiftR();
	board->solved();
}

void TopSpin::spin() {
	board->spin(spinsz);
}

bool TopSpin::isSolved() {
	return board->solved();
}

void TopSpin::print() {
	board->print(spinsz);
}