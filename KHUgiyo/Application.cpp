#include "Application.h"
#include "pch.h"
void Application::Run() {


	cout << "      :::    :::       :::    :::      :::    :::       ::::::::       :::::::::::    :::   :::       ::::::::" << endl;
	cout << "     :+:   :+:        :+:    :+:      :+:    :+:      :+:    :+:          :+:        :+:   :+:      :+:    :+:" << endl;
	cout << "    +:+  +:+         +:+    +:+      +:+    +:+      +:+                 +:+         +:+ +:+       +:+    +:+" << endl;
	cout << "   +#++:++          +#++:++#++      +#+    +:+      :#:                 +#+          +#++:        +#+    +:+" << endl;
	cout << "  +#+  +#+         +#+    +#+      +#+    +#+      +#+   +#+#          +#+           +#+         +#+    +#+" << endl;
	cout << " #+#   #+#        #+#    #+#      #+#    #+#      #+#    #+#          #+#           #+#         #+#    #+#" << endl;
	cout << "###    ###       ###    ###       ########        ########       ###########       ###          ########" << endl;
	cout << "\n\n" << endl;
	cout << "Copyright  자료구조 3팀. All rights reserved." << endl;
	




	shop cat1(0);
	while (1) {
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand) {
		case 1:
			ClientMode();
			break;
		case 2:
			StoreMode();
			break;
		case 0:
			return;
		default:
			cout << "Illegal selection" << endl;
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t------ Command ------" << endl;
	cout << "\t   1 : Client Mode" << endl;
	cout << "\t   2 : Store Mode" << endl;
	cout << "\t   0 : Shut down" << endl;

	cout << endl << "\t Choose a command : ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::ClientMode() {
	string cId;
	cout << "Enter Client ID : ";
	cin >> cId;
	Client* entry = new Client(cId);
	
	if (Clients->GetLength() == 0) {
		cout << "Account created." << endl;
		Clients->Add(*entry);
		cout << "\t\t\t'##:::::'##:'########:'##::::::::'######:::'#######::'##::::'##:'########:'####:" << endl;
		cout << "\t\t\t ##:'##: ##: ##…..::  ##:::::::'##… ##:' ##….  ##: ###::'###: ##…..::  ####:" << endl;
		cout << "\t\t\t ##: ##: ##: ##::::::: ##::::::: ##:::..:: ##:::: ##: ####'####: ##::::::: ####:" << endl;
		cout << "\t\t\t ##: ##: ##: ######::: ##::::::: ##::::::: ##:::: ##: ## ### ##: ######:::: ##::" << endl;
		cout << "\t\t\t ##: ##: ##: ##…::::  ##::::::: ##::::::: ##:::: ##: ##. #: ##: ##…:::::..:::" << endl;
		cout << "\t\t\t ##: ##: ##: ##::::::: ##::::::: ##::: ##: ##:::: ##: ##:.:: ##: ##:::::::'####:" << endl;
		cout << "\t\t\t. ###. ###:: ########: ########:. ######::. #######:: ##:::: ##: ########: ####:" << endl;
		cout << "\t\t\t:…::…:::……..::……..:::……::::…….:::..:::::..::……..::….::" << endl;

		entry->Run();
	}
	else {
		if (Clients->Get(*entry)) {
			cout << "로그인되었습니다" << endl;
		}
		else {
			cout << "계정이 생성되었습니다." << endl;
			Clients->Add(*entry);
		}
		cout << "\t\t\t'##:::::'##:'########:'##::::::::'######:::'#######::'##::::'##:'########:'####:" << endl;
		cout << "\t\t\t ##:'##: ##: ##…..::  ##:::::::'##… ##:' ##….  ##: ###::'###: ##…..::  ####:" << endl;
		cout << "\t\t\t ##: ##: ##: ##::::::: ##::::::: ##:::..:: ##:::: ##: ####'####: ##::::::: ####:" << endl;
		cout << "\t\t\t ##: ##: ##: ######::: ##::::::: ##::::::: ##:::: ##: ## ### ##: ######:::: ##::" << endl;
		cout << "\t\t\t ##: ##: ##: ##…::::  ##::::::: ##::::::: ##:::: ##: ##. #: ##: ##…:::::..:::" << endl;
		cout << "\t\t\t ##: ##: ##: ##::::::: ##::::::: ##::: ##: ##:::: ##: ##:.:: ##: ##:::::::'####:" << endl;
		cout << "\t\t\t. ###. ###:: ########: ########:. ######::. #######:: ##:::: ##: ########: ####:" << endl;
		cout << "\t\t\t:…::…:::……..::……..:::……::::…….:::..:::::..::……..::….::" << endl;
		entry->Run();
	}
}

void Application::StoreMode() {
	string sId;
	bool found = false;
	cout << "매장명 : ";
	cin >> sId;
	shop entry;
	entry.SetShopName(sId);
	Stores->RetrieveItem(entry, found);
	if (found)
		entry.run();
	else {
		cout << "해당 매장이 없습니다." << endl;
	}
}