#include "Client.h"
using namespace std;


Client::Client(string id) {
	cId = id;
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
	cout << "\t--ID -- Command -----" << endl;
	cout << "\t   1 : Set an order" << endl;
	cout << "\t   2 : Display recent orders" << endl;
	cout << "\t   3 : Print receipt" << endl;
	cout << "\t   0 : Log out" << endl;

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
	treeptr->PrintRecord();
	cout << "고르세요.";
	cin >> command;
	YourMenu = treeptr->GetShop(command, ShopName);

	cout << "메뉴 고르세요." << endl;
	YourMenu->PrintMenuList();
	cout << endl;
	cin >> incommand;
	if (incommand == 0) {
		cout << "cancelled." << endl;
		return;
	}
	while (incommand != 0) {
		New.OrderEnlist(YourMenu->returnmenu(incommand - 1));
		New.PrintOrder();
		cin >> incommand;
	}
	New.SetShopName(ShopName);
	RecentOrder.EnStack(New);
	bufferptr->add(New);
}

void Client::ShowAllRecent() {
	RecentOrder.PrintAll();
}

void Client::PrintBill() {
	ofstream fout;
	Order order;
	SortedMenuList* ptr = NULL;
	int orderlen;
	RecentOrder.GetOne(order);
	orderlen = order.GetOrderArray(ptr);
	fout.open("receipt.txt");
	fout << "______  _  _  _" << endl;
	fout << "| ___ \\(_)| || |" << endl;
	fout << "| |_/ / _ | || |" << endl;
	fout << "| ___ \\| || || |" << endl;
	fout << "| |_/ /| || || |" << endl;
	fout << "\\____/ |_||_||_|" << endl;
	fout << "—————————" << endl;
	fout << "결제 일자 : " << order.ReturnOrderTime() << endl;
	for (int i = 0; i < orderlen; i++) {
		fout << "품목 : " << ptr->returnmenu(i).GetName() << "\t가격 : " << ptr->returnmenu(i).GetPrice() << endl;
	}
	fout << "합계 : " << order.GetOrderTotalPrice();

	fout.close();
}