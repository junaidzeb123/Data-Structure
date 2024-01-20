#include<iostream>
using namespace std;

template<class t>
class BinaryTree{
public:
    t* arr;
    int size;
    BinaryTree(int s = 0){
        arr = new t[s];
        size = s;
        for(int i = 0 ;i< s;i++)
            arr[i] = '\0';
    }
    void insertRoot(t v){
        arr[1] = v;
    }
    void insertLeftChild(t parent,t child){
        int i = 1;
        for( ;i < size;i++){
            if(arr[i] == parent)
                break;
        }
        i = i << 1;
        arr[i] = child;
    }
    void insertRightChild(t parent,t child){
        int i = 1;
        for( ;i < size;i++){
            if(arr[i] == parent)
                break;
        }
        i = i << 1 | 1;
        arr[i] = child;
    }
    t getParent(t v){
        int i = 1;
        for( ;i < size;i++){
            if(arr[i] == v)
                break;
        }
        i >> 1;
        return arr[i];
    }
    t* getChildren(t v){
         int i = 1;
         t* val = new t[2];
        for( ;i < size;i++){
            if(arr[i] == v)
                break;
        }
        i <<= 1;
        val[0] = arr[i]; 
        val[1] = arr[i+1]; 
        return val;
    }
    t* getAllNode(){
        t* val = new t[10];
        int j = 0 ;
        for(int i = 1; i < size; i++){
            if(arr[i])
                val[j++] = arr[i];

        }
        return val;
    }
    void inorderTraversl(){
        int index = 1;
        
    }
};
int main(){
    BinaryTree<char> bt(100);
    bt.insertRoot('A');
    bt.insertLeftChild('A','B');
    bt.insertRightChild('A','C');
    bt.insertRightChild('C','D');
    bt.insertRightChild('B','E');
    bt.insertLeftChild('B','T');
    char* a = bt.getChildren('B');
    cout<<a[0]<<" "<<a[1]<<endl;
    
}