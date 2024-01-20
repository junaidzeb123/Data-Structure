#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d = -1){
        data = d;
        next = nullptr;
        prev = nullptr;
    }

};

class DoublyeList{
    public:
    Node* head;
    Node* tail;
    DoublyeList(){
        head = nullptr;
        tail = nullptr;
    }
    // inserting the first Elemnet 
    void InsertFirstElement(int d){
        Node* newNode = new Node(d);  // creation of new Node;     
        if(head == nullptr){   // no previos node i.e empty
            head = newNode;         // head-> [d]
            newNode->next = nullptr;  // 
            newNode->prev = nullptr;
            tail = newNode;     // for first element the head and tail will point to same node
        }else{
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev = newNode;
            head = newNode;
        }
       
    }

    // inserting at last index;
    void InsertAtEnd(int d){
        if(tail){   // if there is already nodes in list then it means tail will exist which will point to last element
        Node* newNode = new Node(d); // creating the node;
            tail->next  = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
        // if tail is nullptr then it means no node exist in the list  so we can use the same logic as for insert first element
        else{
            InsertFirstElement(d);
        }
    }


    // inserting at specific index 
    void InsetAtIndex(int d, int index){
        // we have to iterate from head to specific index
        int no = 0 ;
        Node*temp = head;
        while (temp && no < index -1) // itereate untill end of list or temp points to the node which is previouw to index where we have to inset data
        {
            temp = temp->next;
            no++;
        }

        // NOW MANAGING THE CASES
        // 1)  if index = 0 i.e we have to insert the node at head points
        if(temp == head && no == 0){
            InsertFirstElement(d);
        }
        // 2) this will run if head != nullptr and temp = nullptr i.e the list is ended but the did't get the index where we have to insert i.e no such index exist
        else if(!temp){
            cout<<"data = "<<d<<endl;
            return;
        }
        // This will run if we have to insert at the index which exist but index is not first
        else {
            Node* newNode = new Node(d);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            cout<<"data = "<<d<<endl;

        }

        // This will only run if the index is last one i.e we have to change the tail
        if( temp == tail){
            tail = temp->next;
        }
      
        
    }

    void print(){
        Node* temp = head; 
        while (temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
            cout<<endl<<"in revers\n";

         temp = tail; 
        while (temp){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
    cout<<endl;

        
    }

    void DeletingNode(int d){
            Node*curr = head;
           
            while (curr && curr->data != d){
                curr = curr->next;
            }
            if(curr == head){   // curr == head   !prev means that loop did't run means that we have to deletee the head element
                head = head->next;
                head->prev = nullptr;
                delete curr;
                return;
            }
            if(!curr)    // if end of list came d did't founded or list is alredy empty
                return;
          Node* temp = curr;
          temp->prev->next = curr->next;
          temp->next->prev = temp->prev;
          delete temp; 
                       
    }

};
int main(){
    DoublyeList ddl;
    ddl.InsertFirstElement(33);
    ddl.InsertFirstElement(32);
    ddl.InsertAtEnd(20);
    ddl.print();
    ddl.InsetAtIndex(10,0);
    ddl.print();
    ddl.InsetAtIndex(200,1);
    ddl.print();
    ddl.InsetAtIndex(300,5);
    ddl.print();

    //ddl.InsetAtIndex(500,5);
    ddl.InsetAtIndex(100,9);
    ddl.print();
    cout<<"\n\nstart deleting\n";
    ddl.DeletingNode(32);
    ddl.print();
    ddl.DeletingNode(200);
    ddl.print();


}