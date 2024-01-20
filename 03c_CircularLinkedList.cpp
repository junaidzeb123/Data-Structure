#include<iostream>
using namespace std;;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data  = d;
    }
};

class CircularLinkedList{
public:
   Node* head;
   void InsertAtStart(int d){
        Node* newNode = new Node(d);
        if(!head){
            head = newNode;
            head->next = head;
            
        }
        else{
            newNode->next = head;
            head = newNode; 
        }
   }

   void InsertAtIndex(int index, int d){
        Node* temp = head;
        int no = 0 ;
        if(no == 0){
            Node* newNode =  new Node(d);
            newNode->next = head->next;
            head = newNode;
            return;
        }
        while(temp->next != head && no < index -1){
            temp = temp->next;
            no++;
        }
        if(temp->next == head)
            return;
        Node* newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
   }
    void Print(){
        Node* temp = head;
         while(temp->next != head){
            cout<<temp->data<<" ";
            temp = temp->next;
            
        }
    }

};

int main(){
    CircularLinkedList cll;
    cll.InsertAtIndex(0,100);
    cll.InsertAtIndex(0,200);
    cll.InsertAtIndex(0,300);
    cll.InsertAtIndex(1,400);
    cll.InsertAtIndex(6,500);
    cll.InsertAtIndex(3,600);
    cll.Print();
}