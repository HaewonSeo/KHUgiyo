#pragma once
#include "shop.h"
#include <string>
#include <iostream>

using namespace std;

void Retrieve(shop* root, shop& item, bool& found);

class Tree
{
private:
	Tree() {};
	static bool TinstanceFlag;
	static Tree* instance;
	shop* root;
public:
	static Tree* getInstance();
	virtual ~Tree() {
		TinstanceFlag = false;
	}

	void MakeEmpty();

	void InsertCate(string inName);

	void InsertShop(int c_num, shop* node);

	SortedMenuList* GetShop(int c_num, string& Name);

	void PrintRecord();

	void RetrieveItem(shop& item, bool& found) const;

	shop* ReturnRoot();
};
