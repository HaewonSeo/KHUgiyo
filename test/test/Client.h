#include <iostream>
#include <string>
#include <fstream>

#include "CircularStack.h"
#include "Sort.h"
using namespace std;

template <typename T>
class Client {
private:
	CircularStackType<T> RecentOrder;
	int cId;

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

template <typename T>
Client<T>::Client(int id) {
	cId = id;
	//look for linked list by id to find existing recent list
}

template <typename T>
Client<T>::~Client() {}

template <typename T>
void Client<T>::OrderNew() {
	T New;
	//Set New Order;
	//if(New is already in Stack)
		//DeStack;
		//Push;
	//else
		RecentOrder.EnStack(New);
	//send New to Store;
}

template <typename T>
void Client<T>::ShowAllRecent() {
	RecentOrder.PrintAll();
}

template <typename T>
void Client<T>::PrintBill() {
	ofstream fout;
	T order;
	RecentOrder.GetOne(order);
	fout.open("receipt.txt");

	fout << order;

	fout.close();
}

template <typename T>
int Client<T>::Exit() {
	return 0;
}