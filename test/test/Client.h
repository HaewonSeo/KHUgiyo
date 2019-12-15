#include <iostream>
#include <string>
#include <fstream>

#include "CircularStack.h"
#include "Sort.h"
#include "Buffer.h"
using namespace std;

class Client {
private:
	CircularStackType<Order> RecentOrder;
	string cId;
	Buffer* bufferptr;
	int m_nCurCommand;
public:
	/**
	*	default constructor
	*/
	Client(int id, Buffer* mainbuffer);

	/**
	*	destructor
	*/
	~Client();

	void Run();

	int GetCommand();

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

Client::Client(int id, Buffer *mainbuffer) {
	cId = id;
	bufferptr = mainbuffer;
	m_nCurCommand = 0;
}

Client::~Client() {
	delete bufferptr;
}

void Client::Run() {
	while (1) {
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand) {
		case 1:
			OrderNew();
			break;
		case 2:
			ShowAllRecent();
			break;
		case 3:
			PrintBill();
			break;
		case 0:
			Exit();
		default:
			cout << "\tIllegal selection" << endl;
			break;
		}
	}
}

int Client::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t--ID -- Command -----" << endl;
	cout << "\t   1 : Set an order" << endl;
	cout << "\t   2 : Display recent orders" << endl;
	cout << "\t   3 : Print receipt" << endl;
	cout << "\t   0 : Log out" << endl;

	cout << end << "\t Choose a command : ";
	cin >> command;
	cout << endl;

	return command;
}

void Client::OrderNew() {
	Order New(cId);
	bufferptr->add(New);
	RecentOrder.EnStack(New);
	bufferptr.add(New);
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