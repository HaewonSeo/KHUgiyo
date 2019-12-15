#include "Client.h"
#include "pch.h"
using namespace std;


Client::Client(string id) {
	cId = id;
	RecentOrder = new CircularStackType;
	bufferptr = Buffer::getInstance();
	treeptr = Tree::getInstance();
	m_nCurCommand = 0;
	//look for linked list by id to find existing recent list
}

Client::~Client() { }

void Client::Run() {
	while (1) {
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand) {
		case 1:
			OrderNew();
			break;
		case 2:
			ShowAllRecent();
			break;
		case 3:
			PrintBill();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection" << endl;
			break;
		}
	}
}

int Client::GetCommand() {
	int command;



	cout << endl << endl;
	cout << "\t----- Command -----" << endl;
	cout << "\t   1 : 주문하기" << endl;
	cout << "\t   2 : 최근 주문 내역 출력" << endl;
	cout << "\t   3 : 최근 주문의 영수증 출력" << endl;
	cout << "\t   0 : 로그아웃" << endl;

	cout << endl << "\t Choose a command : ";
	cin >> command;
	cout << endl;

	return command;
}

string Client::GetId() {
	return cId;
}

void Client::OrderNew() {
	int command, incommand;
	string ShopName;
	SortedMenuList* YourMenu;
	Order New(cId);
	
	// 카테고리 선택
	treeptr->PrintRecord();
	cout << "\t		카테고리를 고르세요 >> ";
	cin >> command;
	
	// 매장 선택
	YourMenu = treeptr->GetShopMenuList(command, ShopName);
	
	// 메뉴 선택
	YourMenu->PrintMenuList();
	cout << "0. 메뉴 선택 완료 ";
	cout << "\n\t		메뉴를 고르세요 >> ";
	cin >> incommand;
	if (incommand == 0) {
		cout << "\n\t		메뉴 선택 완료 " << endl;
		return;
	}
	while (incommand != 0) {
		New.OrderEnlist(*(YourMenu->returnmenu(incommand - 1)));
		New.PrintOrder();
		cout << "\n\t		메뉴를 고르세요 >> ";
		cin >> incommand;
	}
	New.SetShopName(ShopName);
	RecentOrder->EnStack(New);
	bufferptr->add(New);
}

void Client::ShowAllRecent() {
	RecentOrder->PrintAll();
}

void Client::PrintBill() {
	ofstream fout;
	Order order;
	SortedMenuList* ptr = NULL;
	int orderlen;
	RecentOrder->GetOne(order);
	orderlen = order.GetOrderArray(ptr);
	fout.open("receipt.txt");

	fout << "______  _  _  _" << endl;
	fout << "| ___ \\(_)| || |" << endl;
	fout << "| |_/ / _ | || |" << endl;
	fout << "| ___ \\| || || |" << endl;
	fout << "| |_/ /| || || |" << endl;
	fout << "\\____/ |_||_||_|" << endl;
	

	fout << endl<<"매장명 : "<<order.GetShopId() << endl;
	fout << "결제 일자 : " << order.ReturnOrderTime() << endl;
	for (int i = 0; i < orderlen; i++) {
		fout << "메뉴 : " << ptr->returnmenu(i)->GetName() << "\t가격 : " << ptr->returnmenu(i)->GetPrice() << endl;
	}
	fout << "합계 : " << order.GetOrderTotalPrice();

	fout.close();
	cout << "\t영수증이 출력되었습니다." << endl;
}