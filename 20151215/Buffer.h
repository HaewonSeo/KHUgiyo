#pragma once

#include "Order.h"
#include <iostream>

#define max 50

using namespace std;

class Buffer {
private:
	Buffer() { cursize = 0; };
	static bool instanceFlag;
	static Buffer* instance;
	int cursize;
public:
	static Buffer* getInstance();
	virtual ~Buffer() {
		instanceFlag = false;
	}
	bool IsFull();
	bool IsEmpty();
	Order buffer[max];
	int add(Order NewOrder);
	int retrieve(Order& dummy);
};

