#include <iostream>
#include <string>
#include <fstream>

#include "CircularStack.h"
#include "Sort.h"
using namespace std;

class Client {
private:
	CircularStackType<Order> RecentOrder;
	string cId;

public:
	/**
	*	default constructor
	*/
	Client(int id);

	/**
	*	destructor
	*/
	~Client();

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

Client<T>::Client(int id) {
	cId = id;
	//look for linked list by id to find existing recent list
}

Client<T>::~Client() {}

void Client::OrderNew() {
	Order New(cId);
	//Set New Order;
	RecentOrder.EnStack(New);
	//send New to Store;
}

void Client::ShowAllRecent() {
	RecentOrder.PrintAll();
}

void Client::PrintBill() {
	ofstream fout;
	Order order;
	RecentOrder.GetOne(order);
	fout.open("receipt.txt");

	fout << order;

	fout.close();
}

int Client::Exit() {
	return 0;
}