#include<iostream>
using namespace std;
 struct Node{
        Node* next;
        int data;
        Node(){
            next = nullptr;
        }
    };
class MyQueue{
public:
   
    Node* front;
    Node* rear;
    
    MyQueue(){
          front =  nullptr;
          rear  = nullptr;
        int noofItems  = 0;
    }
    bool isEmpty(){
        if( front == nullptr)
            return 1;
        return 0;
    }
    void Enqueue(int val){
        Node* tNode = new Node;
        tNode ->data = val;
        tNode->next = nullptr;
        if(isEmpty() == 1){
            front = tNode;
            rear = tNode;
            cout<<"helo\n";
            return;
        }
        rear->next = tNode;
         rear = tNode;
    }

    int Dqueue(){
        if(isEmpty())
            return -1;
        int num = front->data;
        Node* temp = front->next;
        delete front;
        front = temp;        
        return num;
    }
    ~MyQueue(){
        while (!isEmpty()){
            Dqueue();
        }
        
    }
};
int main(){
    MyQueue iQueue;
    cout << "Enqueuing 5 items...\n";
    // Enqueue 5 items
    for (int x = 0; x < 5; x++)
    iQueue.Enqueue(x+1);
    // Deqeue and retrieve all items in the queue
    cout<<iQueue.Dqueue()<<endl;;
    cout<<iQueue.Dqueue()<<endl;;
    iQueue.Enqueue(10);
    iQueue.Enqueue(12);
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty()){
        int value;
        value= iQueue.Dqueue();
        cout << value << endl;
    }
}