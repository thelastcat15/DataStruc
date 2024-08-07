#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		Node* next;
		Node* previous;
		
		Node(int x) {
			id = x;
			next = NULL;
			previous = NULL;
		}
};

class LinkList {
	Node* head = NULL;
	public:
		void connector(Node* PointNode, Node* currNode,int mode) {
			if (mode == 'A') {	// PointNode was before CurrNode
				if (PointNode->next) {
					PointNode->next->previous = currNode;
					currNode->next = PointNode->next;
				}
				currNode->previous = PointNode;
				PointNode->next = currNode;
			} else if (mode == 'I') {	// PointNode was after CurrNode
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
		
		void push(int search_id, int id, char mode) {
			Node* current = new Node(id);
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
					if (temp->id == search_id) {
						connector(temp, current, mode);
						print();
						return;
					}
					if (temp->next == NULL) break;
					else temp = temp->next;
				}
				connector(temp, current, 'A');
			} else {
				head = current;
			}
			print();
		}
		
		void del(int search_id) {
			if (head->id == search_id) {
				if (head->next) {
					head = head->next;
				} else {
					head = NULL;
				}
			} else {
				Node* temp = head;
				while (temp) {
					if (temp->id == search_id) break; // Found
					else temp = temp->next;
				}
				if (temp) {
					if (temp->previous && temp->next) { 					// Check Left & Right
						connector(temp->previous, temp->next, 'M'); // Connect
					} else if (temp->previous) {									// Check Left
						temp->previous->next = NULL;
					} else if (temp->next) {											// Check Right
						temp->next->previous = NULL;
					}

					delete temp;
				}
			}
			print();
		}
		
		void print() {
			for (Node* temp=head; temp; temp=temp->next) {
				cout << (temp->id) << " ";
			}
			cout << "\n";
		}
};

int main() {
	LinkList* MyList = new LinkList();
	
	while (true) {
		char temp;
		cin >> temp;
		if (temp == 'A' || temp == 'I') {
			int id, search_id;
			cin >> id;
			cin >> search_id;
			MyList->push(search_id, id, temp);
		}
		else if (temp == 'D') {
			int search_id;
			cin >> search_id;
			MyList->del(search_id);
		}
		else if (temp == 'P') MyList->print();
		else if (temp == 'E') break;
	}
}






