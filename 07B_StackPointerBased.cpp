#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int d = -1){
        next = nullptr;
        data = d;
    }
};
class Stack{
    public:
    Node* top;
    Stack(){
       
        top = nullptr;
    }
    void push(int d){
        Node*nNode = new Node(d); 
        nNode->next = top;
        top = nNode;
    }
    int pop(){
        if(top == nullptr)
            return -1;
        int v = top->data;
        Node* temp = top->next;
        delete top;
        top = temp;
        return v;

    }
    void print(){
        Node* temp  = top;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
        
    }
};
int main(){
 Stack s;

  s.push(2);
  s.push(4);
  s.print();
  s.push(8);
    s.print();
  s.pop();
  s.print();

}