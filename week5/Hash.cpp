#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		int id;
		string data;
		Node* next;
		Node* previous;
		
		Node(int x, string val) {
			id = x;
			data = val;
			next = NULL;
			previous = NULL;
		}
};

class LinkList {
	public:
		Node* head = NULL;
		void connector(Node* PointNode, Node* currNode,int mode) {
			if (mode == 'A') {	// PointNode before CurrNode
				if (PointNode->next) {
					PointNode->next->previous = currNode;
					currNode->next = PointNode->next;
				}
				currNode->previous = PointNode;
				PointNode->next = currNode;
			} else if (mode == 'I') {	// PointNode after CurrNode
				if (PointNode->previous) {
					PointNode->previous->next = currNode;
					currNode->previous = PointNode->previous;
				}
				currNode->next = PointNode;
				PointNode->previous = currNode;
				if (head->id == PointNode->id) {
					head = currNode;
				}
			} else if (mode == 'M') {	// Force Connect
				PointNode->next = currNode;
				currNode->previous = PointNode;
			}
		}
		
		void push(int id, string data) {
			Node* current = new Node(id, data);
			if (head) {
				for (Node* temp=head; temp; temp=temp->next) {
					// cout << temp->id << " " << id << " " << (temp->id == id) << endl;
					if (temp->id == id) {
						cout << "[Error] Duplicate ID" << endl;
						return;
					}
				}
				Node* temp = head;
				while (temp) {
					if (temp->next == NULL) break;
					else temp = temp->next;
				}
				connector(temp, current, 'A');
			} else {
				head = current;
			}
		}
		
		string search(int search_id) {
			Node* temp = head;
			while (temp) {
				if (temp->id == search_id) return temp->data; // Found
				else temp = temp->next;
			}
			return "-";
		}
		
		void print() {
			for (Node* temp=head; temp; temp=temp->next) {
				cout << "(" << (temp->id) << "," << (temp->data) << ") ";
			}
		}
};

class dictHash {
	public:
		Node* head = NULL;
		int size = 17;
		LinkList* Hash[17];
		
		dictHash() {
			for (int i=0; i<size; i++) {
				Hash[i] = NULL;
			}
		}
	
		void add(int key, string value) {
			int i = key%size;
			if (Hash[i] == NULL) {
				Hash[i] = new LinkList();
			}
			Hash[i]->push(key, value);
		}
		
		void find(int key) {
			int i = key%size;
			if (Hash[i] == NULL) {
				cout << "-" << endl;
			} else {
				cout << Hash[i]->search(key) << endl;;
			}	
		}
				
		void print() {
			for (int i=0; i<size; i++) {
				if (Hash[i] != NULL) {
					Hash[i]->print();
				} else {
					cout << "(-1,-)";
				}
				cout << "\n";
			}
		}
};

int main() {
	dictHash* myHash = new dictHash();
	
	while (true) {
		char temp;
		cin >> temp;
		if (temp == 'a') {
			int id;
			string data;
			cin >> id;
			cin >> data;
			myHash->add(id, data);
		}
		else if (temp == 's') {
			int search_id;
			cin >> search_id;
			myHash->find(search_id);
		}
		else if (temp == 'p') myHash->print();
		else if (temp == 'e') break;
	}
}
