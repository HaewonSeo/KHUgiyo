
#pragma once
#include <string>
#include "OrderQueue.h"
#include "SortedMenuList.h"
#include "Buffer.h"
using namespace std;

class shop {
private:

	string ShopName; // 가게 이름
	int TotalIncome; // 총 매출
	OrderQueue ShopOrder; // 주문 들어온 큐
	SortedMenuList ShopMenu; // 상점의 메뉴 리스트
	Buffer* bufferptr; // 버퍼에 접근하는 포인터
	
	int curCommand; // run 함수의 커맨드를 입력받는 메서드
	shop* sibling;
	shop* child;




public:
	// 생성자
	shop(int flag = 1) {
		ShopName = "";
		TotalIncome = 0;
		bufferptr = Buffer::getInstance();

		sibling = NULL;
		child = NULL;
	};

	//소멸자
	~shop() {};


	void run() {
		while (1) {
			curCommand = GetCommand();

			switch (curCommand) {
			case 1:
				GetOrder();
				DisplayOrder();
				break;
			case 2:
				Setorder();
				break;
			case 3:
				ShowTotalIncome();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection" << endl;
				break;
			}
		}
	}

	int GetCommand() {
		//내용 바꾸기
		int command;
		cout << endl << endl;
		cout << "\t--ID -- Command -----" << endl;
		cout << "\t   1 : 주문 확인" << endl;
		cout << "\t   2 : 주문 처리" << endl;
		cout << "\t   3 : 총매출 확인" << endl;
		cout << "\t   0 : 로그아웃" << endl;

		cout << endl << "\t Choose a command : ";
		cin >> command;
		cout << endl;

		return command;

	}

	SortedMenuList* returnList() {
		return &ShopMenu;
	}

	/**
	  *    @brief   업장의 이름을 설정하는 함수입니다.
	  *    @pre none
	  *    @post 업장 객체의 이름을 설정해줍니다
	  *    @return    none
	  */

	void SetShopName(string name) {
		ShopName = name;
	}

	/**
	  *    @brief   업장의 메뉴 설정하는 함수입니다. 입력으로 새로운 메뉴객체를 입력 받습니다.
	  *    @pre none
	  *    @post 업장 객체의 메뉴 설정해줍니다
	  *    @return    none
	  */
	void SetShopMenu(Menu new_menu) {
		ShopMenu.Add(new_menu);
	}


	/**
	  *    @brief   업장의 이름을 리턴합니다
	  *    @pre 업장 이름이 세팅되있어야 합니다
	  *    @post 업장 이름을 반환합니다
	  *    @return    ShopName
	  */
	string GetName() {
		return ShopName;
	}


	/**
	  *    @brief   현재 주문 상태를 출력해주는 함수입니다.
	  *    @pre none
	  *    @post Order의 내용을 출력해줍니다.
	  *    @return    none
	  */
	void DisplayOrder() {
		ShopOrder.PrintOrderQueue();
	}

	void ShowMenu() {
		ShopMenu.PrintMenuList();
	}


	/**
	  *    @brief   업장의 메뉴 리스트를 수정하는 함수입니다..
	  *    @pre 메뉴리스트가 설정되어 있어야 합니다.
	  *    @post 메뉴 리스트의 내용을 수정합니다.
	  *    @return    none
	  */
	  //void ChangeMenueList();

	  //void ShowEachMenuIncome(){}

	  /**
		*    @brief   매장 총매출을 출력하는 함수 입니다.
		*    @pre 총매출액이 설정되어 있어야합니다
		*    @post 총매출액을 출력합니다.
		*    @return    none
		*/

	void ShowTotalIncome() {
		cout << "총 매출액은 : " << TotalIncome << "원 입니다." << endl;
		cout << "##메뉴별 매출 현황##" << endl;
		ShopMenu.PrintMenuListCount();
	}

	// 버퍼클래스에서 가게 이름을 키값으로 리니어 서치를 해서 오더를 인큐시키는 함수 구현 Buffer.h의 메서드 함수 사용
	void GetOrder() {
		cout << "들어온 주문을 확인합니다." << endl;
		Order* new_order = new Order("dummy", ShopName);
		if (bufferptr->retrieve(*new_order))
			ShopOrder.Enqueue(*new_order);
		else
			cout << "들어온 주문이 없습니다" << endl;


	}


	// 오더큐에서 주문을 디큐, 주문 내역 출력 함수
	void Setorder() {
		cout << "주문을 처리합니다." << endl;
		Order setorder;
		SortedMenuList* ordermenu = new SortedMenuList; // 오더의 메뉴리스트를 복사하는 더미.

		if (ShopOrder.IsEmpty()) {
			cout << "현재 주문이 없습니다." << endl;
			return;
		}
		ShopOrder.Dequeue(setorder);// 일단 디큐시킨다.
		TotalIncome += setorder.GetOrderTotalPrice(); // 총매출 계산.
		setorder.GetOrderArray(ordermenu); // 오더의 메뉴 리스트 복사


		// 오더의 메뉴와 매장의 매뉴들을 모두 돌아서 일치하는 메뉴가 있다면 카운팅 해준다.
		for (int i = 0; i < ShopMenu.GetLength(); i++) {
			for (int j = 0; j < ordermenu->GetLength(); j++) {
				if ((ShopMenu.returnmenu(i)->GetName()) == (ordermenu->returnmenu(j)->GetName())) {
					ShopMenu.returnmenu(i)->Counting();
				}
			}
		}

		setorder.PrintOrder();// 주문 확인 내역 출력
		
	}

	shop* GetSibling()
	{
		return sibling;
	}

	shop* GetChild()
	{
		return child;
	}



	void SetSibling(shop* inSibling)
	{
		sibling = inSibling;
	}

	void SetChild(shop* inChild)
	{
		child = inChild;
	}

	void Display()
	{
		cout << "<" << GetName() << ">" << endl;

	}
	void DisplayChild()
	{
		if (this->GetChild() == NULL)
		{
			cout << "가게가 없습니다." << endl;
		}
		else
		{
			shop* temp = this->GetChild();
			while (1)
			{
				temp->Display();
				if (temp->GetSibling() == NULL) break;
				temp = temp->GetSibling();
			}
		}
	}

};