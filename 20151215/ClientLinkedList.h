#pragma once
#include <iostream>
#include "Client.h"

using namespace std;

//template <typename T>
struct CNode {
	Client data;
	CNode* next;
};

//template <typename T>
class CList {
public:
	CList() {
		m_length = 0;
		m_first = NULL;
		m_curr = NULL;
	}
	CList(const CList& src) {
		m_length = src.m_length;
		m_first = src.m_first;
		m_curr = src.m_curr;
	}
	~CList() {
		MakeEmpty();
	}
	void MakeEmpty() {
		CNode* tempPtr;

		while (m_first != NULL) {
			tempPtr = m_first;
			m_first = m_first->next;
			delete tempPtr;
		}

		m_length = 0;
	}

	int GetLength() const {
		return m_length;
	}

	int Add(Client& newclient) {
		ResetList();

		CNode* node = new CNode;
		CNode* pre;
		Client dummy;

		node->data = newclient;
		node->next = NULL;

		if (!m_length) {
			m_first = node;
		}
		else {
			GetNextItem(dummy);
			if (node->data.GetId() < m_curr->data.GetId()) {
				node->next = m_curr;
				m_first = node;
			}
			else {
				pre = m_first;
				while (1) {
					if (node->data.GetId() < m_curr->data.GetId()) {
						node->next = m_curr;
						pre->next = node;
						break;
					}
					else if (m_curr->next == NULL) {
						m_curr->next = node;
						break;
					}
					pre = m_curr;
					GetNextItem(dummy);
				}
			}
		}
			m_length++;

			return 1;
	}

	int Get(Client& client) {
		bool moreToSearch, found;
		CNode* location;

		if (m_first == NULL) {
			return 0;
		}

		location = m_first;
		found = false;
		moreToSearch = (location != NULL);

		while (moreToSearch && !found) {
			if (client.GetId() == location->data.GetId()) {
				found = true;
				client = location->data;
			}
			else {
				location = location->next;
				moreToSearch = (location != NULL);
			}
		}
		if (found)
			return 1;
		else
			return 0;
	}

	void ResetList() {
		m_curr = NULL;
	}

	void GetNextItem(Client& item) {
		if (m_curr == NULL) {
			m_curr = m_first;
		}
		else
			m_curr = m_curr->next;

		item = m_curr->data;
	}
private:
	CNode* m_first;
	CNode* m_curr;
	int m_length;
};