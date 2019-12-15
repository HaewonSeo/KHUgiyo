#include "Tree.h"

bool Tree::TinstanceFlag = false;
Tree* Tree::instance = NULL;

Tree* Tree::getInstance() {
	if (!instance) {
		instance = new Tree();
		TinstanceFlag = true;
	}
	return instance;
}

void Tree::MakeEmpty() {

}

void Tree::InsertCate(string inName) {
	shop* node = new shop;
	node->SetShopName(inName);

	if (root == NULL)
	{
		root = node;
	}
	else
	{
		shop* temp = root;
		while (1)
		{
			if (temp->GetSibling() == NULL)
			{
				temp->SetSibling(node);
				break;
			}
			temp = temp->GetSibling();
		}
	}
}

void Tree::InsertShop(int c_num, shop* node) {
	shop* temp = root;

	for (int i = 0; i < c_num - 1; i++)
	{
		if (temp->GetSibling() != NULL)
		{
			temp = temp->GetSibling();
		}
	}
	if (temp->GetChild() == NULL)
	{
		temp->SetChild(node);
	}
	else
	{
		temp = temp->GetChild();
		while (1)
		{
			if (temp->GetSibling() == NULL)
			{
				temp->SetSibling(node);
				break;
			}
			temp = temp->GetSibling();
		}
	}
}

SortedMenuList* Tree::GetShop(int c_num, string& Name) {
	shop* temp = root;
	shop* start;
	int treecommand;

	for (int i = 0; i < c_num - 1; i++) {
		if (temp->GetSibling() != NULL) {
			temp = temp->GetSibling();
		}
	}
	if (temp->GetChild() != NULL) {
		temp = temp->GetChild();
		start = temp;
		int i = 1;
		while (1)
		{
			if (temp == NULL) break;
			cout << i << ". " << temp->GetName() << endl;
			i++;
			temp = temp->GetSibling();
		}
		cout << "식당 고르세요.";
		cin >> treecommand;
		temp = start;
		for (int j = 0; j < treecommand - 1; j++) {
			if (start->GetSibling() != NULL) {
				temp = temp->GetSibling();
			}
		}
		Name = temp->GetName();
		return temp->returnList();
	}
}

void Tree::PrintRecord() {
	shop* temp = root;
	int i = 1;
	while (1)
	{
		if (temp == NULL) break;
		cout << i << ". " << temp->GetName() << endl;
		i++;
		temp = temp->GetSibling();
	}
}

shop* Tree::ReturnRoot() {
	return root;
}

void Tree::RetrieveItem(shop& item, bool& found) const {
	Retrieve(root, item, found);
}

void Retrieve(shop* root, shop& item, bool& found) {
	if (root == NULL)
		found = false;
	else if (item.GetName() != root->GetName()&&!found) {
		Retrieve(root->GetChild(), item, found);
		Retrieve(root->GetSibling(), item, found);
	}
	else {
		item = *root;
		found = true;
		return;
	}
}
