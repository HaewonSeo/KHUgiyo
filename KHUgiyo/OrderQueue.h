
#ifndef _ORDERQUEUE_H
#define _ORDERQUEUE_H

#include "Order.h"

struct NodeType
{
	Order data;
	NodeType* next;
};

class OrderQueue
{
public:
	OrderQueue()
	{
		qFront = NULL;
		qRear = NULL;
	}


	~OrderQueue()
	{
		Order tmp;
		while (!IsEmpty()) {
			Dequeue(tmp);
		}
	}

	bool IsEmpty() const {
		return (qFront == NULL);
	}

	// Adds newItem to the rear of the queue.
	// Pre: Queue has been initialized.
	// Post: newItem is at rear of queue.
	void Enqueue(Order neworder) {
		NodeType* ptr;
		ptr = new NodeType;
		ptr->data = neworder;
		ptr->next = NULL;
		if (qRear == NULL)
			qFront = ptr;
		else
			qRear->next = ptr;
		qRear = ptr;
	}

	/**
	*   @brief   Order Queue의 front에 위치하는 메뉴를 삭제 및 입력파라미터인 menu로 리턴
	*   @pre   Queue has been initialized. 큐가 비어있지 않아야 함
	*   @post   기존 front의 메뉴가 삭제 및 front의 메뉴가 변화
	*/
	void Dequeue(Order& neworder) {
		NodeType* tempPtr;
		tempPtr = qFront;
		neworder = qFront->data;

		qFront = qFront->next;
		if (qFront == NULL)
			qRear = NULL;
		delete tempPtr;
	}

	/**
	*   @brief   Order Queue내의 메뉴들을 print
	*   @pre   Queue has been initialized.
	*   @post   none.
	*/
	void PrintOrderQueue() {
		cout << endl;
		cout << "[Order Oueue]" << endl;
		NodeType* tempPtr;
		tempPtr = qFront;
		while (tempPtr !=NULL) {
			tempPtr->data.PrintOrder(); // order 객체 print 함수
			tempPtr = tempPtr->next;
		}
		cout << endl;
	}

private:
	NodeType* qFront;
	NodeType* qRear;
};


#endif