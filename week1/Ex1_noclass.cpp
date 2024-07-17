#include <iostream>
using namespace std;

int main() {
	int left = 0;
	int right = 0;
	
	string temp;
	getline(cin, temp);
	
	for (int i = 0; temp[i] != '\0'; i++){
		if (temp[i] == '(') {
			left++;
		} else if (temp[i] == ')') {
			right++;
			if (right > left) {
				right = -1;
				break;
			}
		}
	}
	if (left == right) {
    	cout << "Pass";
	} else {	
    	cout << "Error";
	}
}


