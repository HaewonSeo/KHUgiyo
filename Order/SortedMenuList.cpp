#include "pch.h"
#include "SortedMenuList.h"

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };


// Make list empty.
void SortedMenuList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int SortedMenuList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedMenuList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int SortedMenuList::Add(Menu inData)
{
	if (IsFull()) {
		return 0;
	}

	bool moreToSearch;
	int location = 0;
	moreToSearch = (location < m_Length);
	while (moreToSearch) {
		switch (inData.CompareByID(m_Array[location])) {
		case LESS:
			moreToSearch = false;
			break;
		case EQUAL:
		case GREATER:
			location++;
			moreToSearch = (location < m_Length);
			break;
		}
	}

	for (int i = m_Length; i > location; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[location] = inData;
	m_Length++;
	return 1;
}


// Initialize list iterator.
void SortedMenuList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int SortedMenuList::GetNextItem(Menu& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//item을 찾아서 해당 item을 반환한다.
int SortedMenuList::Get(Menu& data)
{
	Menu tmp;

	ResetList();
	GetNextItem(tmp);
	while (m_CurPointer < m_Length) {
		switch (tmp.CompareByID(data)) {
		case EQUAL:
			data = tmp;
			return 1;
		case GREATER:
			return 0;
		case LESS:
			GetNextItem(tmp);
			break;
		}
	}
	return 0;
}

//id가 일치하는 item을 찾아서 해당 item을 제거한다.
int SortedMenuList::Delete(Menu data)
{
	if (Get(data)) {
		for (int i = m_CurPointer; i < m_Length; i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_Length--;
		return 1;
	}
	else
		return 0;
}

//id가 일치하는 list내 item을 찾아서 변경한다.
int SortedMenuList::Replace(Menu data)
{
	Menu tmp = data;
	if (Get(tmp)) {
		m_Array[m_CurPointer] = data;
		return 1;
	}
	else
		return 0;
}

//이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
int SortedMenuList::GetBinarySearch(Menu& data) {
	int mid;
	int first = 0;
	int last = m_Length - 1;
	bool moreToSearch = (first <= last);
	bool found = false;

	while (moreToSearch && !found) {

		mid = (first + last) / 2;
		switch (data.CompareByID(m_Array[mid])) {
		case LESS:
			last = mid - 1;
			moreToSearch = (first <= last);
			break;
		case GREATER:
			first = mid + 1;
			moreToSearch = (first <= last);
			break;
		case EQUAL:
			found = true;
			data = m_Array[mid];
			return 1;
		}
	}
	return 0;
}

int SortedMenuList::GetTotal() {
	int total = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		total += m_Array[i].GetPrice();
	}

	return total;
}

void SortedMenuList::PrintMenuList() const
{
	cout << endl;
	cout << "### [Menu List] ###" << endl;
	for (int i = 0; i < MAXSIZE; i++) {
		m_Array[i].PrintMenu();
	}
	cout << endl;
}