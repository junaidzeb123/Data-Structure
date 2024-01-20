#include<iostream>
using namespace std;
class MyQueue{
    int front;
    int rear;
    int size;
    int* arr ;
public:
MyQueue(int size  = 0 ){
    int front = -1; 
    int rear = -1;
    int size = -1;
    int* arr ;
}
bool isEmpty(){
    return front == -1;
}
bool isFull(){
    return rear == size -1;
}
void enQueue(int val){
    if(isEmpty()){
        front++;
        rear++;
        arr[rear] = val;
        return;
    }
    if(isFull()){
        return ;
    }
    rear = (rear + 1) % size;
    arr[rear] = val;


}
int Dqueue(){
    if(isEmpty())
        return -1;
    int num ;    
    num = arr[rear];
    if(front == rear){
        rear = -1;
        front = -1;
    }
    rear = (rear + 1) % size;
    return num;


}


};
int main(){

}