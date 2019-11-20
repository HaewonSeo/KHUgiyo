#pragma once
#include "ItemType.h"
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
template <typename T>
class CircularStackType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxStack.
	*	@pre	The maxStack is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularStackType();

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
	*	@post	m_iFront와 m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the Stack.
	*	@pre	Stack has been initialized.
	*	@post	If (Stack is full), FullStack exception is thrown; otherwise, newItem is at the last.
	*/
	void EnStack(T item);

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
	void GetOne(T& item);

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxStack;	//max size of the Stack.
	T* m_pItems;	//pointer for dynamic allocation.
};

template <typename T>
CircularStackType<T>::CircularStackType() {
	m_pItems = new T[maxStack];
	m_iFront = maxStack - 1;
	m_iRear = maxStack - 1;
	m_nMaxStack = maxStack;
}

template <typename T>
CircularStackType<T>::~CircularStackType() {
	delete m_pItems;
}

template <typename T>
bool CircularStackType<T>::IsFull() {
	if ((m_iRear + 1) % m_nMaxStack == m_iFront)
		return 1;
	return 0;
}

template <typename T>
bool CircularStackType<T>::IsEmpty() {
	if (m_iRear == m_iFront)
		return 1;
	return 0;
}

template <typename T>
void CircularStackType<T>::MakeEmpty() {
	m_iRear = m_nMaxStack;
	m_iFront = m_nMaxStack;
}

template <typename T>
void CircularStackType<T>::EnStack(T item) {
	if (IsFull()) {
		m_iFront = (m_iFront + 1) % m_nMaxStack;
	}
	m_iRear = (m_iRear + 1) % m_nMaxStack;
	m_pItems[m_iRear] = item;
}

template <typename T>
void CircularStackType<T>::PrintAll() {
	int index = m_iRear;
	while (ind > m_iFront) {
		cout << m_pItems[index] << endl;
		index = (index - 1 + m_nMaxStack) % m_nMaxStack;
	}
}

template <typename T>
void CircularStackType<T>::GetOne(T& item) {
	item = m_pItems[m_iRear];
}
