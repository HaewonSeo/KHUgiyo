#include "Order.h"
#include "pch.h"

//Constructor
Order::Order(string clientid, string shopid_)
{
	oId = clientid;
	shopid = shopid_;
	SetOrderTotalPrice();
	SetOrderTime();
}

/**
*   @brief   Order한 Client의 Id를 반환
*   @pre   order한 client가 존재
*   @post   none
*   @param   none
*   @return order한 client의 id를 반환
*/
string Order::GetClientId() const {
	return oId;
}

/**
*   @brief   Order할 Shop의 Id를 반환
*   @pre   order할 Shop이 존재
*   @post   none
*   @param   none
*   @return order할 shop의 id를 반환
*/
string Order::GetShopId() const {
	return shopid;
}

/**
*   @brief   Order의 총합을 설정 (MenuList내의 메뉴의 총합을 반환하여)
*   @pre   MenuList가 초기화
*   @post   none
*   @param   none
*   @return Order의 총합을 설정
*/
void Order::SetOrderTotalPrice() {
	oTotalPrice = menuList.GetTotal();
}

/**
*   @brief   Order의 총합을 반환
*   @pre   MenuList가 초기화
*   @post   none
*   @param   none
*   @return Order의 총합을 반환
*/
int Order::GetOrderTotalPrice() const {
	return oTotalPrice;
}

/**
*   @brief   Order한 시간을 설정
*   @pre   order 객체의 생성
*   @post   none
*   @param   none
*   @return none
*/
void Order::SetOrderTime() {
	oTime = time(NULL);
}

/**
*   @brief   Order한 시간을 출력
*   @pre   order 객체의 생성
*   @post   none
*   @param   none
*   @return none
*/
void Order::PrintOrderTime() {
	struct tm* date;
	date = localtime(&oTime);
	//년/월/일 시:분:초 형식으로 출력
	printf("%d/%d/%d %d:%d:%d\n", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
}

string Order::ReturnOrderTime() {
	struct tm* date;
	date = localtime(&oTime);
	string t, y, m, d, h, min, s;
	y = to_string(date->tm_year + 1900);
	m = to_string(date->tm_mon + 1);
	d = to_string(date->tm_mday);
	h = to_string(date->tm_hour);
	min = to_string(date->tm_min);
	s = to_string(date->tm_sec);
	t = y + "년 " + m + "월 " + d + "일 " + h + "시 " + min + "분 " + s + "초";
	return  t;
}

/**
*   @brief   Order한 시간을 time_t 형식으로 반환
*   @pre   order 객체의 생성
*   @post   none
*   @param   none
*   @return Order한 시간을 반환
*/
time_t Order::GetOrderTime() const {
	return oTime;
}

/**
*   @brief   Order의 정보를 출력
*   @pre   order내에 menulist가 초기화
*   @post   none
*   @param   none
*   @return Order의 정보를 출력
*/
void Order::PrintOrder() {
	this->SetOrderTotalPrice();

	cout << "------ [주문내역] ------ " << endl;
	cout << "### 고객 ID : " << oId << endl;
	cout << "### 합계 : " << oTotalPrice;
	menuList.PrintMenuList();
}

void Order::SetShopName(string _name) {
	shopid = _name;
}

void Order::OrderEnlist(Menu _Menu) {
	menuList.Add(_Menu);
}

/**
*	@brief	Order 객체 내의 menulist에 접근
*	@param	menulist를 가리킬 pointer
*	@return	menulist의 길이
*/
int Order::GetOrderArray(SortedMenuList*& pointer) {
	pointer = &menuList;
	return menuList.GetLength();
}