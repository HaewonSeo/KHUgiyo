#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:
	Order(string clientid="null")
	{
		oId = clientid;
		SetOrderTotalPrice();
		SetOrderTime();
	}

	
	/**
	*	@brief	Order한 Client의 Id를 반환
	*	@pre	order한 client가 존재
	*	@post	none
	*	@param	none
	*	@return order한 client의 id를 반환
	*/
	string GetOrderId() const {
		return oId;
	}

	/**
	*	@brief	Order의 총합을 설정 (MenuList내의 메뉴의 총합을 반환하여)
	*	@pre	MenuList가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 총합을 설정
	*/
	void SetOrderTotalPrice() {
		oTotalPrice = menuList.GetTotal();
	}

	/**
	*	@brief	Order의 총합을 반환
	*	@pre	MenuList가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 총합을 반환
	*/
	int GetOrderTotalPrice() const {
		return oTotalPrice;
	}

	/**
	*	@brief	Order한 시간을 설정
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void SetOrderTime() {
		oTime = time(NULL);	
	}

	/**
	*	@brief	Order한 시간을 출력
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void PrintOrderTime() {
		struct tm *date;
		date = localtime(&oTime);
		//년/월/일 시:분:초 형식으로 출력
		printf("%d/%d/%d %d:%d:%d\n", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
	}

	/**
	*	@brief	Order한 시간을 time_t 형식으로 반환
	*	@pre	order 객체의 생성
	*	@post	none
	*	@param	none
	*	@return Order한 시간을 반환
	*/
	time_t GetOrderTime() const {
		return oTime;
	}

	/**
	*	@brief	Order의 정보를 출력
	*	@pre	order내에 menulist가 초기화
	*	@post	none
	*	@param	none
	*	@return Order의 정보를 출력
	*/
	void PrintOrder() {
		cout << endl;
		cout << "### Order ID : " << oId << endl;
		cout << "### Order Total Price : " << oTotalPrice << endl;
		menuList.PrintMenuList();
	}

	

private:
	SortedMenuList menuList;
	string oId; // client id 
	int oTotalPrice;// total price of order
	time_t oTime; // client가 order한 시간 
};