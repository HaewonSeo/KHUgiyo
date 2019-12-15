#pragma once

#include "Order.h"
#include <iostream>

#define max 50

using namespace std;

class Buffer {
private:
	Order buffer[max];
	static bool instanceFlag;
	static Buffer* instance;
	int cursize;

public:

	Buffer() { cursize = 0; };

	virtual ~Buffer() {
		instanceFlag = false;
	}

	static Buffer* getInstance();

	bool IsFull();

	bool IsEmpty();

	

	int add(Order NewOrder);

	int retrieve(Order& dummy);

};
