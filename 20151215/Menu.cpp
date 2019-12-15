#include "Menu.h"

Menu::Menu()
{
	mName = "";
	mPrice = 0;
	mCount = 0;
}

Menu::~Menu() {}

string Menu::GetName()
{
	return mName;
}

int Menu::GetPrice()
{
	return mPrice;
}

int Menu::GetCount()
{
	return mCount;
}

void Menu::PrintMenu()
{
	cout << "\t메뉴의 이름 : ";
	cout << mName;
	cout << "\t메뉴의 가격 : ";
	cout << mPrice << endl;
}

void Menu::SetName(string inName)
{
	mName = inName;
}

void Menu::SetPrice(int inPrice)
{
	mPrice = inPrice;
}

void Menu::SetCount(int inCount)
{
	mCount = inCount;
}

void Menu::SetMenu(string inName, int inPrice, int inCount)
{
	SetName(inName);
	SetPrice(inPrice);
	SetCount(inCount);
}

void Menu::SetNameFromKB()
{
	cout << "\t메뉴의 이름 : ";
	cin >> mName;
}

void Menu::SetPriceFromKB()
{
	cout << "\t메뉴의 가격 : ";
	cin >> mPrice;
}

void Menu::EditMenuFromKB()
{
	SetNameFromKB();
	SetPriceFromKB();
}

void Menu::Counting()
{
	mCount++;
}

void Menu::InitializeCount()
{
	mCount = 0;
}

int Menu::ReadDataFromFile(ifstream& fin)
{
	fin >> mName;
	fin >> mPrice;
	fin >> mCount;

	return 1;
}

Menu& Menu::operator=(Menu& otherMenu) {
	this->mCount = otherMenu.mCount;
	this->mName = otherMenu.mName;
	this->mPrice = otherMenu.mPrice;
	return *this;
}

bool Menu::operator>(Menu& otherMenu)
{
	if (this->mName > otherMenu.mName) return true;
	else return false;
}

bool Menu::operator<(Menu& otherMenu)
{
	if (this->mName < otherMenu.mName) return true;
	else return false;
}

bool Menu::operator==(Menu& otherMenu)
{
	if (this->mName == otherMenu.mName) return true;
	else return false;
}

bool Menu::operator!=(Menu& otherMenu)
{
	if (this->mName != otherMenu.mName) return true;
	else return false;
}