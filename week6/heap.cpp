#include <iostream>

using namespace std;

class MaxHeap {
	public:
		int *heap;
		int size = -1;
		int maxsize;
				
		MaxHeap(int s) {
			maxsize = s;
			heap = new int[s];
		}
		
		int parent(int i) {
			return (i-1)/2; 
		}
		int leftChild(int i) {
			return (i*2)+1;
		}
		int rightChild(int i) {
			return (i*2)+2;
		}
		
		int swap(int i, int replace) {
			int temp = heap[replace];
			heap[replace] = heap[i];
			heap[i] = temp;
			return replace;
		}
		
		void add(int x) {
			if (size == maxsize-1) {
				cout << "Heap Full" << endl;
			}
			size++;
			heap[size] = x;
			int i = size;
			while (i != 0 && heap[parent(i)] < heap[i]) {
				i = swap(i, parent(i));
			}
		}
		
		void remove() {
			if (size == -1) {
				cout << "Heap Empty" << endl;
			}
			cout << heap[0] << endl;
			heap[0] = NULL;
			if (size > 0) {
				heap[0] = heap[size];
				
				int i = 0;
				while (leftChild(i) <= size) {
					if (heap[leftChild(i)] > heap[i] && heap[i] < heap[rightChild(i)]) {
						if (heap[leftChild(i)] >= heap[rightChild(i)]) {
							i = swap(i, leftChild(i));
						} else {
							i = swap(i, rightChild(i));
						}
					} else if (heap[leftChild(i)] > heap[i]) {
						i = swap(i, leftChild(i));
					} else if (heap[rightChild(i)] > heap[i]) {
						i = swap(i, rightChild(i));
					} else {
						break;
					}
				}
			}
			size--;
		}
		
		void showall() {
			if (size == -1) {
				cout << "Heap Empty" << endl;
			}
			for (int i=0; i<=size; i++) {
				cout << heap[i] << " ";
			}
			cout << endl;
		}
};

int main() {
	MaxHeap maxHeap(20);
	while (1) {
		char x;
		cin >> x;
		if (x == 'a') {
			int y;
			cin >> y;
			maxHeap.add(y);
		} else if (x == 'd') {
			maxHeap.remove();
		} else if (x == 'p') {
			maxHeap.showall();
		} else if (x == 'e') {
			break;
		}
	}
}




