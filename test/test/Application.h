#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Client.h"
#include "Shop.h"

class Application {
public:
	Application() {
		m_nCurCommand = 0;
	}

	~Application() {}

	void Run();

	int GetCommand();

	void Client();

	void Store();

private:
	//linkedlist* Clients;
	//tree* Stores;
};