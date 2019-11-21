#include "Application.h"

void Application::Run() {
	while (1) {
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand) {
		case 1:
			Client();
			break;
		case 2:
			Store();
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

void Application::Client() {
	string cId;
	cout << "Enter Client ID : ";
	cin >> cId;
	Client entry(cId);
	//if(Clients.searchfor(entry))
		//enter node data
		//data.run
	//else
		//create new node
		//data.run
}

void Application::Store() {
	string sId;
	cout << "Enter Store ID : ";
	cin >> sId;
	Store entry(sId);
	//if......
}