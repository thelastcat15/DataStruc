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
			}
		}
		
		void push(int search_id, int id, char mode) {
			Node* current = new Node(id);
			if (head) {
				for (Node* temp=head; (temp && (temp->next==NULL)); temp=temp->next) {
					if (temp->id == search_id) {
						cout << "[Error] Duplicate ID" << endl;
						return;
					}
				}
				for (Node* temp=head; (temp && (temp->next==NULL)); temp=temp->next) {
					if (temp->id == search_id) {
						Node* current = new Node(id);
						connector(temp, current, mode);
						print();
						return;
					}
				}
			}
			head = current;
			print();
		}
		
		void del(int search_id) {
			if (head->id == search_id) {
				if (head->next) {
					head = head->next;
				} else {
					head = NULL;
				}
				return;
			}
			for (Node* temp=head->next; (temp && (temp->next==NULL)); temp=temp->next) {
				if (temp->id == search_id) {
					delete temp;
					return;
				}
			}
		}
		
		void print() {
			for (Node* temp=head; (temp && (temp->next==NULL)); temp=temp->next) {
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
			int id, pos;
			cin >> id;
			cin >> pos;
			MyList->push(pos, id, temp);
		}
		else if (temp == 'D') {
			int id;
			cin >> id;
			MyList->del(id);
		}
		else if (temp == 'E') break;
	}
}






