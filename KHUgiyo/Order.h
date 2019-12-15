#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:

	//Constructor
	Order(string clientid = "null", string shopid_ = "null");

	Order(Order& src) {
		menuList = src.menuList;
		oId = src.oId;
		oTime = src.oTime;
		oTotalPrice = src.oTotalPrice;
		shopid = src.shopid;
	}

	/**
	*   @brief   Order한 Client의 Id를 반환
	*   @pre   order한 client가 존재
	*   @post   none
	*   @param   none
	*   @return order한 client의 id를 반환
	*/
	string GetClientId() const;

	/**
	*   @brief   Order할 Shop의 Id를 반환
	*   @pre   order할 Shop이 존재
	*   @post   none
	*   @param   none
	*   @return order할 shop의 id를 반환
	*/
	string GetShopId() const;

	/**
	*   @brief   Order의 총합을 설정 (MenuList내의 메뉴의 총합을 반환하여)
	*   @pre   MenuList가 초기화
	*   @post   none
	*   @param   none
	*   @return Order의 총합을 설정
	*/
	void SetOrderTotalPrice();

	/**
	*   @brief   Order의 총합을 반환
	*   @pre   MenuList가 초기화
	*   @post   none
	*   @param   none
	*   @return Order의 총합을 반환
	*/
	int GetOrderTotalPrice() const;
	/**
	*   @brief   Order한 시간을 설정
	*   @pre   order 객체의 생성
	*   @post   none
	*   @param   none
	*   @return none
	*/
	void SetOrderTime();

	/**
	*   @brief   Order한 시간을 출력
	*   @pre   order 객체의 생성
	*   @post   none
	*   @param   none
	*   @return none
	*/
	void PrintOrderTime();

	string ReturnOrderTime();

	/**
	*   @brief   Order한 시간을 time_t 형식으로 반환
	*   @pre   order 객체의 생성
	*   @post   none
	*   @param   none
	*   @return Order한 시간을 반환
	*/
	time_t GetOrderTime() const;

	void SetShopName(string _name);

	void OrderEnlist(Menu _Menu);

	/**
	*   @brief   Order의 정보를 출력
	*   @pre   order내에 menulist가 초기화
	*   @post   none
	*   @param   none
	*   @return Order의 정보를 출력
	*/
	void PrintOrder();

	/**
	*	@brief	Order 객체 내의 menulist에 접근
	*	@param	menulist를 가리킬 pointer
	*	@return	menulist의 길이
	*/
	int GetOrderArray(SortedMenuList*& pointer);



private:
	SortedMenuList menuList;
	string oId; // client id 
	string shopid; // shop id 
	int oTotalPrice;// total price of order
	time_t oTime; // client가 order한 시간 
};