#include "CircularStack.h"
#include "pch.h"
using namespace std;

CircularStackType::CircularStackType() {
	m_pItems = new Order[maxStack];
	m_iBottom = maxStack - 1;
	m_iTop = maxStack - 1;
	m_nMaxStack = maxStack;
}

CircularStackType::CircularStackType(const CircularStackType& src) {
	m_pItems = src.m_pItems;
	m_iBottom = src.m_iBottom;
	m_iTop = src.m_iTop;
	m_nMaxStack = src.m_nMaxStack;
}

CircularStackType::~CircularStackType() {
	delete[] m_pItems;
}

bool CircularStackType::IsFull() {
	if ((m_iTop + 1) % m_nMaxStack == m_iBottom)
		return 1;
	return 0;
}

bool CircularStackType::IsEmpty() {
	if (m_iTop == m_iBottom)
		return 1;
	return 0;
}

void CircularStackType::MakeEmpty() {
	m_iTop = m_nMaxStack;
	m_iBottom = m_nMaxStack;
}

int CircularStackType::EnStack(Order item) {
	int ind = m_iTop;
	if (DeStack(item)) { //delete if the same one exists
		cout << "\n\t최근 주문 목록에 같은 주문이 존재합니다." << endl;
	}
	else {
		cout << "\n\t주문이 완료되었습니다." << endl;
	}

	if (IsFull()) {
		m_iBottom = (m_iBottom + 1) % m_nMaxStack;
	}
	m_iTop = (m_iTop + 1) % m_nMaxStack;
	m_pItems[m_iTop] = item;
	return 1;
}

int CircularStackType::DeStack(Order item) {
	int ind = m_iTop;
	for (int i = (m_iTop - m_iBottom + m_nMaxStack) % m_nMaxStack; i > 0; i--) {
		if (m_pItems[ind].GetShopId() == item.GetShopId()) { // if hit
			while (ind > m_iBottom) { // tighten up
				m_pItems[ind] = m_pItems[ind - 1];
				ind = (ind - 1 + m_nMaxStack) % m_nMaxStack;
			}
			m_iBottom = (m_iBottom + 1) % m_nMaxStack;
			return 1;
		}
		ind = (ind - 1 + m_nMaxStack) % m_nMaxStack;
	}
	return 0;
}

void CircularStackType::PrintAll() {
	int index = m_iTop;
	for (int i = (m_iTop - m_iBottom + m_nMaxStack) % m_nMaxStack; i > 0; i--) {
		cout << "주문 시간 : ";
		m_pItems[index].PrintOrderTime();
		m_pItems[index].PrintOrder();
		index = (index - 1 + m_nMaxStack) % m_nMaxStack;
	}
}

void CircularStackType::GetOne(Order& item) {
	item = m_pItems[m_iTop];
}