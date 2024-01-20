/*here is the implemenatation of  binary heap on array  based implementation  */
/*
    Min heap
*/
template< class T>
#include<iostream>
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
                return -1 ;
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

// int main() {
    binaryHeap<int> heap(10);
    heap.insert(10);
    heap.insert(11);
    heap.insert(12);
    heap.insert(13);
    heap.insert(14);
    heap.insert(15);
    heap.insert(16);
    heap.insert(17);
  
    std::cout << heap.deleteMin() << std::endl;    
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
    std::cout << heap.deleteMin() << std::endl;
}