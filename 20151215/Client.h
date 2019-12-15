#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "CircularStack.h"
#include "Buffer.h"
#include "Tree.h"

using namespace std;

class Client {
private:
	CircularStackType RecentOrder;
	string cId;
	Buffer* bufferptr;
	Tree* treeptr;
	int m_nCurCommand;
public:
	/**
	*	default constructor
	*/
	Client(string id = "");

	/**
	*	destructor
	*/
	~Client();

	void Run();

	int GetCommand();

	string GetId();

	/**
	*	@brief	Makes new order and push into the RecentOrder stack.
	*	@pre	None
	*	@post	New order objective is pushed into RecentOrder stack.
	*/
	void OrderNew();

	/**
	*	@brief	Shows first item of RecentOrder stack.
	*	@pre	The stack should be initialised.
	*	@post	Information of most recent order is shown.
	*/
	void ShowAllRecent();

	/**
	*	@brief	Prints receipt of the last order.
	*	@pre	The stack should be initialised and not empty.
	*	@post	The receipt is printed as file output.
	*/
	void PrintBill();

	/**
	*	@brief	Exits client mode.
	*	@pre	None
	*	@post	None
	*/
	int Exit();
};
