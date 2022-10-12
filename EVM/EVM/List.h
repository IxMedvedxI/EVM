#pragma once
#include <iostream>

using namespace std;

template <class T>
class List {
public:
	struct Node {
		T info;
		Node* next;
		Node() {
			info = NULL;
			next = NULL;
		}
		Node(int x, Node* n) {
			info = x;
			next = n;
		}
		Node(Node*& a) {
			this->info = a->info;
			this->next = a->next;
		}
		Node& operator =(Node*& a) {
			this->info = a->info;
			this->next = a->next;
			return *this;
		}
	};
	Node* head;
	Node* tail;

	~List() {
		while (head) {
			Node* cur = head;
			head = head->next;
			delete cur;
		}
		tail = 0;
	}
	friend ostream& operator<<(ostream& os, const List& l) {
		Node* h = l.head;
		for (; h != NULL; h = h->next)
			cout << h->info << " ";
		return os;
	}


	void AddAtBeg(T x) {
		Node* nd = new Node(x, head);
		if (head == NULL)head = tail = nd;
		else head = nd;
	}

	void AddAtEnd(T x) {
		Node* nd = new Node(x, NULL);
		if (tail == NULL) head = tail = nd;
		else {
			tail->next = nd;
			tail = tail->next;
		}

	}

	Node* SearchEl(T x) {
		Node* h;
		for (h = head; h && h->next != NULL && h->info != x; h = h->next);
		if (h->info == x) return h;
		else return NULL;
	}

	void DeleteEl(T x) {
		Node* h;
		Node* prev = new Node;
		for (h = head; h && h->next != NULL && h->info != x; h = h->next) {
			prev = h;
		}
		if (h == head) {
			head = head->next;
			delete h;
			return;
		}
		if (h->info == x) {
			prev->next = h->next;
			delete h;
		}
	}

	void addAfter(T x, T xAdd) {
		Node* cur = new Node(xAdd, NULL);
		Node* h;
		for (h = head; h && h->next != NULL && h->info != x; h = h->next);
		if (h == 0) {
			head = tail = cur;
			return;
		}
		if (h->next == NULL && h->info == x) {
			tail->next = cur;
			tail = tail->next;
			return;
		}
		if (h->info == x) {
			cur->next = h->next;
			h->next = cur;
		}
	}

	void InsertionSort() {
		Node* cur1, * prev1, * cur2, * prev2;
		if (!head) return;
		prev1 = head;
		cur1 = prev1->next;
		while (cur1) {
			cur2 = head;
			prev2 = NULL;
			while (cur2 != cur1 && cur2->info == cur1->info) {
				prev2 = cur2;
				cur2 = cur2->next;
			}
			if (cur1 == cur2) {
				prev1 = cur1;
				cur1 = cur1->next;
			}
			else {
				prev1->next = cur1->next;
				if (prev2) prev2->next = cur1;
				else head = cur1;
				cur1->next = cur2;
				cur1 = prev1->next;
			}
		}
	}
};
