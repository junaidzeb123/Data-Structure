#include<iostream>
using namespace std;
class MyQueue{
public:
    int front;
    int rear;
    int *arr ;
    int Size;
    int noOfItem;
    MyQueue(int size = 0){
        Size = size;
        arr = new int[Size];
        front = -1;
        rear = -1;
        noOfItem = 0;
    }
    bool isEmpty(){
        return noOfItem == 0;
    }
    bool isFull(){
        return noOfItem == Size;

    }
    void enQueue(int val){
        if(isEmpty()){
            front++;
            rear++;
            arr[rear] = val; 
        }
        else if(isFull()){
            return ;
        }
        else{
            rear = (rear +1) % Size;
            cout<<"rear = "<<rear<<endl;
            arr[rear] = val;

        }
        noOfItem++;

    }
    int dQueue(){
        if(isEmpty())
            return -1;
        int num = arr[front];
        front = (front +1) % Size;
        noOfItem--;
        if(isEmpty()){
            front = -1;
            rear = -1;
        }
        return num;
    }
    
    void print(){
        cout<<"front "<<arr[front]<<endl;
    }
};
int main(){
    MyQueue iQueue(5);
    cout << "Enqueuing 5 items...\n";
// Enqueue 5 items.
    for (int x = 0; x < 5; x++){
      iQueue.enQueue(x);
     // iQueue.print();
    }
    // Attempt to enqueue a 6th item.
    cout << "Now attempting to enqueue again...\n";
   cout<< iQueue.dQueue()<<endl;;
   cout<< iQueue.dQueue()<<endl;
   cout<< iQueue.dQueue()<<endl;
    iQueue.enQueue(5);
    iQueue.enQueue(6);
    iQueue.enQueue(7);
    iQueue.enQueue(8);
    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty()){
         int value;
        value = iQueue.dQueue();
        cout << value << endl;
          //    iQueue.print();
    }
    cout<<endl;
    iQueue.enQueue(5);
    cout<< iQueue.dQueue()<<endl;
    cout<< iQueue.dQueue()<<endl;
}