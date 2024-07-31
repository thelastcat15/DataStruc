#include <iostream>
using namespace std;
class Stackk{
public:
	int pos = -1;
	int arr[5];
	void push(int data) {
		if (pos < 4) {
			arr[pos+1] = data;
			pos++;
		} else {
			cout << "Full" << endl;
		}
	}
	void pop() {
		if (pos > -1) {
			cout << arr[pos] << endl;
			arr[pos] = -1;
			pos--;
		} else {
			cout << "Emply" << endl;
		}
	}
	void top() {
		if (pos > -1) {
			cout << arr[pos] << endl;
		} else {
			cout << "Empty" << endl;
		}
	}
	void showall() {
		if (pos > -1) {
			for (int i=0; i<=pos; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		} else {
			cout << "Empty" << endl;
		}
	}
	void showsize() {
		cout << pos+1 << endl;
	}
};

int main() {
	Stackk mystack;
	while (true) {
		char temp;
		cin >> temp;
		if (temp == 'U') {
			int temp2;
			cin >> temp2;
			mystack.push(temp2);
		}
		else if (temp == 'O') mystack.pop();
		else if (temp == 'T') mystack.top();
		else if (temp == 'P') mystack.showall();
		else if (temp == 'N') mystack.showsize();
		else if (temp == 'X') break;
	}
}


