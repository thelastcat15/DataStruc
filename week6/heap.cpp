#include <iostream>

using namespace std;

class MaxHeap {
    public:
        int *heap;
        int size;
        int maxsize;

        MaxHeap(int s) {
            maxsize = s;
            heap = new int[s];
            size = -1;
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

        void swap(int i, int replace) {
            int temp = heap[replace];
            heap[replace] = heap[i];
            heap[i] = temp;
        }

        void add(int x) {
            if (size == maxsize-1) {
                cout << "Heap Full" << endl;
                return;
            }
            size++;
            heap[size] = x;
            int i = size;
            while (i != 0 && heap[parent(i)] < heap[i]) {
                swap(i, parent(i));
                i = parent(i);
            }
        }

        void remove() {
            if (size == -1) {
                cout << "Heap Empty" << endl;
                return;
            }
            cout << heap[0] << endl;
            heap[0] = heap[size];
            size--;

            int i = 0;
            while (leftChild(i) <= size) {
                int largest = i;
                if (heap[leftChild(i)] > heap[largest]) {
                    largest = leftChild(i);
                }
                if (rightChild(i) <= size && heap[rightChild(i)] > heap[largest]) {
                    largest = rightChild(i);
                }
                if (largest != i) {
                    swap(i, largest);
                    i = largest;
                } else {
                    break;
                }
            }
        }

        void showall() {
            if (size == -1) {
                cout << "Heap Empty" << endl;
                return;
            }
            for (int i = 0; i <= size; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    MaxHeap maxHeap(20);
    while (true) {
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
    return 0;
}
