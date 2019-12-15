#pragma once
#include "Menu.h"

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class SortedMenuList
{
public:
	/**
	*	default constructor.
	*/
	SortedMenuList()
	{
		m_Length = 0;
		ResetList();
	}

	SortedMenuList(SortedMenuList& src) {
		m_Length = src.m_Length;
		for (int i = 0; i < MAXSIZE; i++) {
			m_Array[i] = src.m_Array[i];
		}
		m_CurPointer = src.m_CurPointer;
	}

	/**
	*	destructor	.
	*/
	~SortedMenuList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(Menu data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(Menu& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(Menu& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(Menu data);

	/**
	*	@brief	id가 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(Menu data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetBinarySearch(Menu& data);


	/**
	*	@brief	메뉴 리스트 내의 메뉴 가격의 총합을 반환
	*	@pre	메뉴리스트가 초기화
	*	@post	none
	*	@param	none
	*	@return	메뉴 리스트 내의 메뉴의 총합을 리턴
	*/
	int GetTotal();

	/**
	*	@brief	메뉴 리스트 내의 메뉴를 출력
	*	@pre	메뉴리스트가 초기화
	*	@post	none
	*	@param	none
	*	@return	메뉴 리스트 내의 메뉴를 출력
	*/
	void PrintMenuList();

	Menu returnmenu(int index);

private:
	Menu m_Array[MAXSIZE];		///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};