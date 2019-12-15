#pragma once
#include "Order.h"
#include <iostream>
using namespace std;

#define maxStack 10


/**
*	@brief	Exception class thrown by DeStack when Stack is empty.
*/
class EmptyStack
{
public:
	/**
	*	@brief	Display a message for empty Stack on screen.
	*/
	void print()
	{
		cout << "EmtpyStack exception thrown." << endl;
	}
};

/**
*	@brief	Stack class.
*	@details	Circular Stack using front and rear to delete the oldest item automatically
*/

class CircularStackType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxStack.
	*	@pre	The maxStack is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularStackType();

	CircularStackType(const CircularStackType& src);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for Stack pointer.
	*	@post	none.
	*/
	~CircularStackType();


	/**
	*	@brief	Determines whether the Stack is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (Stack is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the Stack is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (Stack is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the Stack empty.
	*	@pre	Stack has been initialized.
	*	@post	m_iBottom¿Í m_iTop is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the Stack.
	*	@pre	Stack has been initialized.
	*	@post	If (Stack is full), FullStack exception is thrown; otherwise, newItem is at the last.
	*	@return	1 if successfully added
	*/
	int EnStack(Order item);

	/**
	*	@brief	Deletes an item in the middle of the stack and rearrange it
	*	@pre	Stack has been initialised.
	*	@post	If there was a hit, the searched item gets removed
	*	@return	1 if there was a hit, 0 if there wasn't
	*/
	int DeStack(Order item);

	/**
	*	@brief	Print all the items in the Stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void PrintAll();

	/**
	*	@brief	Print an item on top
	*	@pre	Stack has been initialised.
	*	@post	None
	*/
	void GetOne(Order& item);

private:
	int m_iBottom;	//index of one infront of the first element.
	int m_iTop;	//index of the last element.
	int m_nMaxStack;	//max size of the Stack.
	Order* m_pItems;	//pointer for dynamic allocation.
};

