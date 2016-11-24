#pragma once
#include "CircularDoubleLinkedList.h"
#include <iostream>
class TopSpinADT {
public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1 - 20
	virtual bool isSolved() = 0;
};class TopSpin: public TopSpinADT{private:	CircularDoublyLinkedList<int>*board;	unsigned short int sz;	unsigned int spinsz;public:	TopSpin();	TopSpin(unsigned int);	void shiftLeft();	void shiftRight();	void spin();	bool isSolved();	void print();	unsigned short int get_size() { return sz; }	void set_size(unsigned short int a) { sz = a; }	void set_spsize(unsigned int a) { spinsz = a; }};inline std::ostream& operator<< (std::ostream& os, TopSpin& ts) {	ts.print();	return (os << "");}