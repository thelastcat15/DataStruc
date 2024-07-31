#include <iostream>
using namespace std;

class Queue {
public:
	int head = 0;
	int tail = -1;
	int size = 5;
	int arr[5];
	
	int full() {
		return ((tail+1)%size) == (head%size);
	}
	
	int empty() {
		return (tail%size) == (head%size);
	}
	
	void push(int x) {
		if (!full()) {
			tail++;
			arr[tail%size] = x;
		} else {
			cout << "Full" << endl;
		}
	}
	
	void pop() {
		if (!empty()) {
			int temp = head;
			head++;
			cout << arr[temp%size] << endl;
		} else {
			cout << "Empty" << endl;
		}
	}
	
	void count() {
		int count;
		for (int i=head; i<=tail; i++) {
			count++;
		}
		cout << count << endl;
	}
	
	void showHT() {
		cout << arr[head%size] << " " << arr[tail%size] << endl;
	}
	
	void p() {
		for (int i=head; i<=tail; i++) {
			cout << arr[i%size] << " /n";
		}
	}
};

int main() {
	Queue MyQueue;
	while (true) {
		char temp;
		cin >> temp;
		if (temp == 'e') {
			int n;
			cin >> n;
			MyQueue.push(n);
		}
		else if (temp == 'd') MyQueue.pop();
		else if (temp == 'p') MyQueue.p();
		else if (temp == 'n ') MyQueue.count();
		else if (temp == 's') MyQueue.showHT();
		else if (temp == 'x') break;
	}
}






