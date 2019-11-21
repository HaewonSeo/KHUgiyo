#include "pch.h"
#include "Order.h"


//Constructor
Order::Order(string clientid = "null")
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
string Order::GetOrderId() const {
	return oId;
}

/**
*	@brief	Order의 총합을 설정 (MenuList내의 메뉴의 총합을 반환하여)
*	@pre	MenuList가 초기화
*	@post	none
*	@param	none
*	@return Order의 총합을 설정
*/
void Order::SetOrderTotalPrice() {
	oTotalPrice = menuList.GetTotal();
}

/**
*	@brief	Order의 총합을 반환
*	@pre	MenuList가 초기화
*	@post	none
*	@param	none
*	@return Order의 총합을 반환
*/
int Order::GetOrderTotalPrice() const {
	return oTotalPrice;
}

/**
*	@brief	Order한 시간을 설정
*	@pre	order 객체의 생성
*	@post	none
*	@param	none
*	@return none
*/
void Order::SetOrderTime() {
	oTime = time(NULL);
}

/**
*	@brief	Order한 시간을 출력
*	@pre	order 객체의 생성
*	@post	none
*	@param	none
*	@return none
*/
void Order::PrintOrderTime() {
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
time_t Order::GetOrderTime() const {
	return oTime;
}

/**
*	@brief	Order의 정보를 출력
*	@pre	order내에 menulist가 초기화
*	@post	none
*	@param	none
*	@return Order의 정보를 출력
*/
void Order::PrintOrder() const {
	cout << endl;
	cout << "### Order ID : " << oId << endl;
	cout << "### Order Total Price : " << oTotalPrice << endl;
	menuList.PrintMenuList();
}