#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class CircularDoublyLinkedList {
private:
	void addHead(T item);//adds a value to the head
	class Node {
	public:
		Node(T val, Node* nx, Node* pr) {
			value = val;
			next = nx;
			previous = pr;
		}
		Node(T val) {
			value = val;
		}
		T value;
		Node* next;
		Node* previous;
	};
public:
	//function declarations:
	CircularDoublyLinkedList();//default constructor
	CircularDoublyLinkedList(unsigned int);//size constructor
	~CircularDoublyLinkedList();//destructor
	unsigned int size() const;//returns size of list
	bool isEmpty();//returns true if list is empty
	
	T removeHead();//removes the head value and returns it
	void addTail(T, unsigned int);//add a value to the tail
	T removeTail();//removes the tail and returns it
	void add(unsigned int, T);//adds a value to a location
	T replace(unsigned int, T);//replaces a value at a loca	tion
	T remove(unsigned int);//removes a value at a location
	T retrieve(unsigned int);//returns a value at a location
	T retrievePrev(unsigned int) const;//retrieves the previous element
	void print(unsigned int);
	void shiftL();
	void shiftR();
	void spin(const unsigned int);
	bool solved();
private:
	Node *_head;
	Node *_tail;
	unsigned int _size;
};

//function definitions:

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
	_head = NULL;
	_tail = NULL;
	_size = 0;
}//default constructor

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(unsigned int a) {
	_head = new Node(1);
	_tail = _head;
	for (unsigned short int i(2); i < a+1; i++) {
		addTail(i,a);
	}
	_head->previous = _tail;
	//Node* temp = new Node(_head->value, NULL, _head);
	_tail->next = _head;
}//size constructor

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
	Node *here = _head, *nextNode;
	for(;_size>0;_size--) {
		nextNode = here->next;
		delete here;
		here = nextNode;
	}
	
}//destructor

template<class T>
unsigned int CircularDoublyLinkedList<T>::size() const {
	return _size;
}//returns size of list

template<class T>
bool CircularDoublyLinkedList<T>::isEmpty() {
	return (_size == 0);
}//returns true if list is empty

template <class T>
void CircularDoublyLinkedList<T>::addHead(T item) {
	_head = new Node(item, _head, _tail);
	if (_tail == nullptr) _tail = _head;
	_head->next->previous = _head;
	//_tail->next = _head;
	_size++;
}

template<class T>
T CircularDoublyLinkedList<T>::removeHead() {
	return 0;
}//removes the head value and returns it

template<class T>
void CircularDoublyLinkedList<T>::addTail(T x, unsigned int a) {
	if (a != x) {
		_tail = _tail->next = new Node(x, NULL, _tail);
	}
	else {
		//_tail = _tail->next = new Node(x, _head, _tail);
		_tail = _tail->next = new Node(x, NULL, _tail);
	}
	_size++;
}//add a value to the tail

template<class T>
T CircularDoublyLinkedList<T>::removeTail() {
	T returnVal = _tail->value;
	_tail = _tail->previous;
	//_tail->next = _head;
	_size--;
	return returnVal;

}//removes the tail and returns it

template<class T>
void CircularDoublyLinkedList<T>::add(unsigned int, T) {

}//adds a value to a location

template<class T>
T CircularDoublyLinkedList<T>::replace(unsigned int, T) {
	return 0;
}//replaces a value at a location

template<class T>
T CircularDoublyLinkedList<T>::remove(unsigned int) {
	return 0;
}//removes a value at a location

template<class T>
T CircularDoublyLinkedList<T>::retrieve(unsigned int a) {
	if (a<0 || a>_size) {
		return NULL;
	}
	Node* here = _head;
	for (unsigned short int i(1); i < a; i++) {
		here = here->next;
	}
	return here->value;
}//returns a value at a location

template<class T>
T CircularDoublyLinkedList<T>::retrievePrev(unsigned int) const {
	return 0;
}//retrieves the previous element

template<class T>
void CircularDoublyLinkedList<T>::print(unsigned int spsz) {
	int length = 0;
	Node* here = _head;
	for (unsigned short int i(0); i < spsz; i++) {
		if (here->value > 9) {
			length += 3;
		}
		else {
			length += 2;
		}
		here = here->next;
	}
	here = _head;
	cout << "|";
	for (unsigned short int i(0); i < length; i++) {
		cout << "-";
	}
	cout << "|\n|";
	for (unsigned short int i(0); i < spsz; i++) {
		cout << here->value << " ";
		here = here->next;
	}
	cout << "| ";
	for (unsigned short int i(spsz); i < _size+1; i++) {
		cout <<" "<< here->value;
		here = here->next;
	}
	cout << "\n|";
	for (unsigned short int i(0); i < length; i++) {
		cout << "-";
	}
	cout << "|";
	cout << endl << endl;
}

template<class T>
void CircularDoublyLinkedList<T>::shiftL() {
	_tail = _head;
	_head = _head->next;
}

template<class T>
void CircularDoublyLinkedList<T>::shiftR() {
	_head = _tail;
	_tail = _tail->previous;
}

template<class T>
void CircularDoublyLinkedList<T>::spin(const unsigned int spsz) {
	vector<T>val;
	Node* here = _head;
	for (unsigned short int i(0); i < spsz; i++) {
		here = here->next;
	}
	for (unsigned short int i(0); i < spsz; i++) {
		val.push_back(here->previous->value);
		here = here->previous;
	}
	for (unsigned short int i(0); i < spsz; i++) {
		here->value = val.at(i);
		here = here->next;
	}
	
}

template<class T>
bool CircularDoublyLinkedList<T>::solved() {
	Node* here = _head;
	for (unsigned short int i(1); i < _size; i++) {
		if (here->value != i) {
			return 0;
		}
		here = here->next;
	}
	return 1;
}



