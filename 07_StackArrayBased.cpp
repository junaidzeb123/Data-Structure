#include<iostream>
using namespace std;
class Stack{
    public:
    int*arr ;
    int top;
    int size;
    Stack(int s = 0){
        this->size = s;
        top = -1;
        arr = new int[s];
    }   
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size-1;
    }
    void push(int data){
        if(isFull())
            return;   
        top++;
        arr[top] = data;
    }
    int  pop(){
        if(isEmpty())
            return -1;
        int v = arr[top];
        top--;
        return v;   
    }
    void print(){     
        for(int i =  0 ; i <= top ;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};
int main(){
  Stack s(7);

  s.push(2);
  s.push(4);
  s.print();
  s.push(8);
  s.pop();
  s.print();

}