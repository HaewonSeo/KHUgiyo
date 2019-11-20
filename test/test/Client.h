#include <iostream>
#include <string>
#include "Order.h"
#include "Sort.h"
using namespace std;

class Client {
private:
	Stack<Order> RecentOrder;
	int cId;

public:
	/**
	*	default constructor
	*/
	Client();

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
	void ShowRecent();

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
	void Exit();
};