#pragma once

#include "Order.h"
#include <iostream>

#define max 50;

using namespace std;

class Buffer {
private:
	Buffer() {}
	static bool instanceFlag;
	static Buffer* instance;
	Order buffer[maxsize];
	int cursize;
public:
	static Buffer* getInstance();
	virtual ~Buffer() {
		instanceFlag = false;
	}
	bool IsFull();
	bool IsEmpty();
	int add(Order NewOrder);
	int retrieve(Order& dummy);
};

