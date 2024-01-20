#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class List
{
public:
    Node *head;
    List()
    {
        head = nullptr;
    }
    Node *insert(int index, int value)    {
        Node *temp = head;
        int no = 1;
        while (temp && index > no){
            temp = temp->next;
            no++;
        }
        if(index > 0 && !temp)
            return nullptr;
        Node *newNode = new Node;
        newNode->data = value;
        if (index == 0){
            newNode->next = head;
            head = newNode;
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return newNode;
    }
   
  
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    int deleteNode(int value){
        Node* temp = head;
        Node*prev = nullptr;
        int no = 1;
        while(temp && temp->data != value){
            prev = temp;
            temp = temp->next;
            no++;
        }
        if(temp){
            if(prev){
                prev->next = temp->next;
                delete temp;
            }
            else{
               prev = head->next;
               delete head;
               head = prev;
            }
        }
    }
};



int main()
{

    List l1;
    l1.insert(0, 12);
    l1.insert(2, 13);
    l1.insert(1, 14);
    l1.insert(2, 15);
    l1.print();
}