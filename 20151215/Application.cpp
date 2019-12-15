#include "Application.h"

void Application::Run() {
	cout << " \t_   __ _   _  _   _         _" << endl;
	cout << "\t| | / /| | | || | | |       (_)" << endl;
	cout << "\t| |/ / | |_| || | | |  __ _  _  _   _   ___" << endl;
	cout << "\t|    \\ |  _  || | | | / _` || || | | | / _ \"" << endl;
	cout << "\t| |\\  \\| | | || |_| || (_| || || |_| || (_) |" << endl;
	cout << "\t\\_| \\_/\\_| |_/ \\___/  \\__, ||_| \\__, | \\___/" << endl;
	cout << "\t                      __/ |     __/ |" << endl;
	cout << "\t                      |___/     |___/" << endl;
	//트리 생성
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
	cout << "\t---ID -- Command ----" << endl;
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
	Client entry(cId);
	if (Clients->GetLength() == 0) {
		cout << "Account created." << endl;
		Clients->Add(entry);
		entry.Run();
	}
	else {
		Clients->Get(entry);
		cout << "Logging in." << endl;
		entry.Run();
	}
}

void Application::StoreMode() {
	string sId;
	bool found = false;
	cout << "Enter Store ID : ";
	cin >> sId;
	shop entry;
	entry.SetShopName(sId);
	Stores->RetrieveItem(entry, found);
	if (found)
		entry.run();
	else {
		cout << "There is no such shop." << endl;
	}
}