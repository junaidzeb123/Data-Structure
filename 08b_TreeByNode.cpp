#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d = 0) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int v) {
        Node* newNode = new Node(v);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        while (current) {
            if (v < current->data) {
                if (current->left) {
                    current = current->left;
                }
                else {
                    current->left = newNode;
                    return;
                }
            }
            else {
                if (current->right != nullptr) {
                    current = current->right;
                }
                else {
                    current->right = newNode;
                    return;
                }
            }
        }
    }

    void insertRecursively(int val, Node* curr) {
        if (val < curr->data) {
            if (!curr->left) {
                curr->left = new Node(val);
                return;
            }
            else {
                insertRecursively(val, curr->left);
            }
        }
        else if (val > curr->data) {
            if (!curr->right) {
                curr->right = new Node(val);
                return;
            }
            else {
                insertRecursively(val, curr->right);
            }
        }
    }

    void insertRecursively(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        insertRecursively(val, root);
    }

    void BreadthFirstTraversalWithQueue() {
        if (!root)
            return;
        queue<Node*> q;
        q.push(root);
        Node* current = nullptr;
        while (!q.empty()) {
            current = q.front();
            cout << q.front()->data << " ";
            q.pop();
            if (current->left) {

                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }

    }
    /*not working*/
    void BreadthFirstTraversalWithoutQueue() {
        if (!root)
            return;

        Node* current = root;
        Node* currentLeft = root->left;
        Node* currentRight = root->right;
        Node* prev = root;
        cout << current->data << " ";
        while (currentLeft || currentRight) {
            if (currentLeft) {
                cout << current->data << " ";
            }

        }

    }

    void InorderTarveralWithStack() {
        stack<Node*> mystack;

        Node* current = root;
        while (!mystack.empty() || current) {
            while (current != nullptr) {

                mystack.push(current);
                current = current->left;
            }
            current = mystack.top();
            mystack.pop();
            cout << current->data << " ";
            current = current->right;

        }


    }

    void preOrderWithStack() {
        stack<Node*> mystack;
        Node* current = root;
        while (!mystack.empty() || current) {
            while (current != nullptr) {
                cout << current->data << " ";
                mystack.push(current);
                current = current->left;
            }
            current = mystack.top();
            mystack.pop();

            current = current->right;

        }
    }

    void PostOrderWithStack() {
        stack<Node*> mystack;
        Node* current = root;
        // stack 
        //push to stack the left sub tree
        // pop and print
        // push the right sub tree
        while (!mystack.empty() || current) {
            while (current != nullptr) {
                mystack.push(current);
                current = current->left;
            }
            current = mystack.top();
            mystack.pop();
            current = current->right;
            cout << current->data << " ";

        }
    }

    // need two function 
    // one for user othre will for recursion
    void inorderRecusive(Node* root) {
        if (root == nullptr)
            return;
        inorderRecusive(root->left);
        cout << root->data;
        inorderRecusive(root->left);

    }
    void inorderRecusive() {
        inorderRecusive(root);
    }

    void preorderRecusive(Node* root) {
        if (root == nullptr)
            return;
        preorderRecusive(root->left);
        cout << root->data;
        preorderRecusive(root->left);

    }
    void preorderRecusive() {
        preorderRecusive(root);
    }

    void postorderRecusive(Node* root) {
        if (root == nullptr)
            return;
        postorderRecusive(root->left);
        cout << root->data;
        postorderRecusive(root->left);

    }
    void postorderRecusive() {
        postorderRecusive(root);
    }
    bool FindNodeIterative(int val){
        if(!root)
            return 0;
        Node* curr = root;
        while (curr){
            if(curr->data == val)
                return 1;
            if(val < curr->data){
                curr = curr->left;
            }else{
                curr = curr->right;
            }

        }
        
        return 0;
    }
    bool FindNodeRecursive(int val,Node*root){
        if(!root)
            return 0;
        if(val == root->data)
            return 1;
        if (val < root->data)
            FindNodeRecursive(val,root->left);
        else if(val > root->data)
            FindNodeRecursive(val ,root->right);
        
    }
    bool FindNodeRecursive(int val){
        return FindNodeRecursive(val,root);
    }

    /*case where when node with 2 childs come then we delete it. and 
        replace the pointer which points to node to the node->right
        and the least element in right subtree is attached to rood->left
        Node*temp = root->right; // root is node to be deleted
            while (temp->left){ // finding the lease element in right sub tree
                temp = temp->left;
            }
        temp->left = root->left; //the left of least element in right sub tree is attached to root->left
        temp = root; //
        root = root->right; // the pointer pointing to root(node) will point to its right child
        delete root; // deleting
    */
    void deleteNode(int val,Node*&root){ // by raference root will help us to deleter 
        if(root == nullptr)
            return; // no node with val exist
      
        if(val < root->data){ // val is less then move to left side
            deleteNode(val,root->left);
        }
        if(val > root->data) // move to right side
            deleteNode(val,root->right);
        else if(val == root->data){ // we have reached to the node tobe deleted
            if(root->left == nullptr) {// manget will node to be deleted have only right child or no child
                    Node* temp = root->right;
                    delete root;
                    root = temp;
                    return;
            }
            if(root->right == nullptr) { // when root have only left child
                Node* temp = root->left;
                delete root;
                root = temp;
                return;
            }
            else { // root have both childs
                /* here we have more then two options*/
                Node*temp = root->right;
                while (temp->left){
                    temp = temp->left;
                }
                temp->left = root->left;
                temp = root;
                root = root->right;
                delete temp;
              
            }
        }
        

    }
   
   
    void deleteNode(int val){
        deleteNode( val,root);
    }


    /* 
        here the new method to tackle the node with 2 childs
        the nodetoBeDeleted->data will be replaced by its precssor of inorder travel
        i.e nodetoBeDeleted->left->left->left until nullptr
        and delete the    i.e nodetoBeDeleted->left->left->left until nullptr
    */
       void deleteNode2(int val,Node*&root){ // by raference root will help us to deleter 
        if(root == nullptr)
            return; // no node with val exist
      
        if(val < root->data){ // val is less then move to left side
            deleteNode2(val,root->left);
        }
        if(val > root->data) // move to right side
            deleteNode2(val,root->right);
        else if(val == root->data){ // we have reached to the node tobe deleted
            if(root->left == nullptr) {// manget will node to be deleted have only right child or no child
                    Node* temp = root->right;
                    delete root;
                    root = temp;
                    return;
            }
            if(root->right == nullptr) { // when root have only left child
                Node* temp = root->left;
                delete root;
                root = temp;
                return;
            }
            else { // root have both childs
                /* here we have more then two options*/
                /*replacing the data of nodeTObeDelted with its precssor of inorder travesal*/
                Node*temp = root->left;
                while(temp->left){
                    temp = temp->left;
                }
                int minData = temp->data;
                root->data = minData;
                deleteNode2(temp->data,temp);
            }
        }
        

    }
    void deleteNode2(int val){
        deleteNode2( val,root);
    }
    int GiveHeight(Node*root){
        if(root == nullptr)
            return 0;
        int leftHeigth = 1 + GiveHeight(root->left);
        int RightHeigth = 1 + GiveHeight(root->right);
        return max(leftHeigth,RightHeigth);
    }
    int GiveHeight(){
        return  GiveHeight(root);
    }
    int MaxCost(Node*root){
        if(root == nullptr)
            return 0;
        int leftHeigth = root->data + GiveHeight(root->left);
        int RightHeigth = root->data + GiveHeight(root->right);
        return max(leftHeigth,RightHeigth);
    }
    int MaxCost(){
       return MaxCost(root);
    }
    void deleteAllLeaves(Node*&root){
        if(root->left == nullptr && root->right){
            delete root;
            root = nullptr;
            return;
        }
        if(root->left)
        deleteAllLeaves(root->left);
        if(root->right)
        deleteAllLeaves(root->right);
    }
    void deleteAllLeaves(){
         deleteAllLeaves(root);
    }
    void countLeaves(Node*root,int&num){
        if(root->left == nullptr && root->right == nullptr){
            num++;
            return;
        }
        if(root->left)
            countLeaves(root->left,num);
        if(root->right)
            countLeaves(root->right,num);

    }
    int countLeaves(){
        int num = 0 ;
        countLeaves(root,num);
        return num;
    }
};
int count = 0 ;
Node*element(Node*root,int&k){
    if(root == nullptr)
        return NULL;
    Node*left = element(root->left,k);
    if(left != nullptr)
        return left;
   :: count++;
    if(::count == k)
        return root;
    return element(root->right,k);
}
void show(BinarySearchTree bst){
    int arr[4] = {6,4,2,8};
    Node* head = bst.root;
    for(int i = 0 ; i< 4; i++)
        cout<<element(head,arr[i])->data<<endl;
}
int main() {
    BinarySearchTree bst;
    bst.insertRecursively(50);
    bst.insertRecursively(17);
    bst.insertRecursively(76);
    bst.insertRecursively(9);
    bst.insertRecursively(23);
    bst.insertRecursively(54);
    bst.insertRecursively(14);
    bst.insertRecursively(19);   
    bst.insertRecursively(72);   
    bst.insertRecursively(12);   
    bst.insertRecursively(67);   
    bst.BreadthFirstTraversalWithQueue();
    cout<<endl;
    bst.deleteNode2(18);
     bst.BreadthFirstTraversalWithQueue();
    cout<<endl;
    cout<<bst.countLeaves()<<endl;
    show(bst);
    // cout<<endl;
    // cout<<bst.GiveHeight()<<endl;
    // cout<<bst.MaxCost();
   // bst.deleteAllLeaves();
  ///  bst.BreadthFirstTraversalWithQueue();
    //cout<<bst.FindNodeRecursive(19)<<" ";
   // cout<<bst.FindNodeRecursive(30);
    // bst.PostOrderWithStack();
}


