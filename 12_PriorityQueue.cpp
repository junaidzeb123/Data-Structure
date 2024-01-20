/*here is the implemenatation of  binary heap on array  based implementation  */
/*
    Min heap
*/
#include<iostream>
template< class T>
class binaryHeap {
    T* arr;
    int current_size;
    int capacity;

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    int minChildIndex(int left, int right) {
        if (arr[left] <arr[right])
            return left;
        return right;
    }
public:
    binaryHeap(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        current_size = 0;
    }

    void insert(T value) {
        if (current_size == capacity - 1) {
            std::cout << "overflow occur\n";
            return;
        }
        current_size++;
        arr[current_size] = value;
        int i = current_size;
        /*we are at root if i == 1*/
        while (i != 1) {
            int parent = i / 2;
            if (arr[parent] > arr[i]) { /*swap if violation*/
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else {
                break;
            }
        }

    }

    T deleteMin() {
        if (current_size == 0) {
            std::cout << "under flow\n";
                return item(-1,-1) ;
        }

        T value = arr[1];
        arr[1] =  arr[current_size];
        current_size--;

        int i = 1;
        while (i*2 < current_size) {
            int minChild = minChildIndex(i * 2, i * 2 + 1);

            if (arr[i] > arr[minChild]) {
                if (minChild == i * 2) {
                    swap(arr[i], arr[i*2]);
                    i = i*2;
                }
                else {
                    swap(arr[i], arr[i * 2 + 1]);
                    i = i * 2 + 1 ;
                }
            }
            else {
                break;
            }

        }

        return value;
    }

    void print() {
        for (int i = 1; i <= current_size; i++)
            std::cout << arr[i] << " ";
    }
};

struct item
{
    int value;
    int priority;
    item(int v, int pr) {
        value = v;
        priority = pr;
    }
    item() {
        value = -1;
        priority = -1;
    }
    bool operator<(item i) {
        return this->priority < i.priority;
    }
    bool operator>(item i) {
        return this->priority > i.priority;
    }
};


class Priorityqueue {
    binaryHeap<item> heap;
public:
    Priorityqueue() : heap(11) {}
    void enqueue(item i) {
        heap.insert(i);
    }
    item dequeue() {
        return heap.deleteMin();
    }
};

int main() { 
    Priorityqueue q;
    q.enqueue(item(10, 4));
    q.enqueue(item(11, 3));
    q.enqueue(item(12, 1));
    q.enqueue(item(14, 7));
    q.enqueue(item(20, 6));
    std::cout << q.dequeue().value<<" ";
    std::cout << q.dequeue().value<<" ";
    std::cout << q.dequeue().value<<" ";
    std::cout << q.dequeue().value<<" ";

}