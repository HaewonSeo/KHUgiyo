#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:

	//Constructor
	Order(string clientid = "null");

	
	/**
	*	@brief	Order한 Client의 Id를 반환
	*	@pre	order한 client가 존재
	*	@post	none
	*	@param	none
	*	@return order한 client의 id를 반환
	*/
	string GetOrderId() const;

	/**
	*	@brief	Order의 총합을 설정 (MenuList내의 메뉴의 총합을 반환하여)
	*	@pre	MenuList가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 총합을 설정
	*/
	void SetOrderTotalPrice();

	/**
	*	@brief	Order의 총합을 반환
	*	@pre	MenuList가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 총합을 반환
	*/
	int GetOrderTotalPrice() const;
	/**
	*	@brief	Order한 시간을 설정
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void SetOrderTime();

	/**
	*	@brief	Order한 시간을 출력
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void PrintOrderTime();
	/**
	*	@brief	Order한 시간을 time_t 형식으로 반환
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return Order한 시간을 반환
	*/
	time_t GetOrderTime() const;
	

	/**
	*	@brief	Order의 정보를 출력
	*	@pre	order내에 menulist가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 정보를 출력
	*/
	void PrintOrder() const;

	

private:
	SortedMenuList menuList;
	string oId; // client id 
	int oTotalPrice;// total price of order
	time_t oTime; // client가 order한 시간 
};