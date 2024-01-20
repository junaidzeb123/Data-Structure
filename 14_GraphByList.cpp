#include<iostream>
#include<queue>
#include<stack>
struct Node{
int data;
Node*next;
Node(int d){
    this->data = d;
    next = nullptr;
}
Node(){
    this->data = -1;
    next = nullptr;
}
};

class Graph{
Node** list;
int size;
public:
    Graph(int size){
        this->size = size;
        list = new Node*[size];
        for(int i = 0 ; i< size;i++)
            list[i] = nullptr;
    }

    void addAdge(int start, int end){
        Node* newNode1 = new Node(end);
        Node*temp = list[start];
        if(temp != nullptr){
            newNode1->next = temp->next;
            temp->next = newNode1;
        }else{
            newNode1->next = temp;
            list[start] = newNode1;
        }

        Node* newNode2 = new Node(start);
        temp = list[end];
        if(temp != nullptr){
            newNode1->next = temp->next;
            temp->next = newNode1;
        }else{
            newNode1->next = temp;
            list[end] = newNode1;
        }
    }

    void BFS(int root){
        std:: queue<Node*> q;
        q.push(list[root]);
        bool*visited = new bool[size]{false};
        visited[root] = true;
        while (q.empty())  {
            Node*temp = q.front();
            std::cout << q.front()->data<<" ";
            q.pop();
            while(temp){
                if(visited[temp->data] == false){
                    q.push(temp);
                    visited[temp->data]  = true;
                }
            }
        }
        

    }
};


int main() {
    Graph g(7);
    g.addAdge(0, 1);
    g.addAdge(0, 3);
    g.addAdge(1, 3);
    g.addAdge(1, 2);
    g.addAdge(1, 5);
    g.addAdge(2, 3);
    g.addAdge(2,5);
    g.addAdge(2,4);
    g.addAdge(3,4);
    g.addAdge(4,6);
    
    g.BFS(0);
    std::cout << "\n";

    g.DFS(0);
}