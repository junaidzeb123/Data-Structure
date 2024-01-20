#include<iostream>
#include<queue>
using namespace std;
template<class t>
struct AvlNode {
	t data;
	AvlNode<t>* left;
	AvlNode<t>* right;
	int height;
	AvlNode(t d = 0) {
		data = d;
		left = NULL;
		right = NULL;
		height = 0;
	}
};
template<class t>
class AVLTree {
	AvlNode<t>* root;
public:
	AVLTree() {
		root = NULL;
	}
	int Height(AvlNode<t>* node) {
		if (node == NULL)
			return -1;
		return node->height;
	}
	void singleRightRotaion(AvlNode<t>*&node) {
		AvlNode<t>* temp1 = node;
		AvlNode<t>* temp2 = node->left;
		temp1->left = temp2->right;
		temp2->right = temp1;
		node = temp2;
		temp1->height = max(Height(temp1->left), Height(temp1->right)) + 1;
		temp2->height = max(Height(temp2->left), Height(temp2->right)) + 1;
	}
	void singleLeftRotation(AvlNode<t>*& node) {
		AvlNode<t>* temp1 = node;
		AvlNode<t>* temp2 = node->right;
		temp1->right = temp2->left;
		temp2->left = temp1;
		node = temp2;
		temp1->height = max(Height(temp1->left), Height(temp1->left)) + 1;
		temp2->height = max(Height(temp2->left), Height(temp2->left)) + 1;
	}
	void insert(t& data, AvlNode<t>*& node) {
		if (node == NULL) {
			node = new AvlNode<t>(data);
			return;
		}
		else if  (data < node->data) {
			/* if this runs then it means that data will be inserted to left of node->data
			* which further means that here only LL and LR insertion can occur.
			* it can tell us that after insertion if this node become imbalance we have to
			* perform either RR or RL rotation to make this balance.
			*/
			insert(data, node->left);
			if (Height(node->left) - Height(node->right) == 2) {//if this node is imbalancc
				// no checking wher LL or LR insertion occur
				if (data < node->left->data) {	// if LL insertion occur
					//we are perfoming RR rotaion 
					singleRightRotaion(node);
				}
				if (data > node->left->data) {	// if LR insertion occur
					//we are performing RL rotaion 
					// first R then  L
					singleLeftRotation(node->left);
					singleRightRotaion(node);
				}
			}
		}
		else if(data > node->data) {
			insert(data, node->right);
			/*if imbalance occur then the right side is heavy because insertion occur on right side*/
			if (Height(node->left) - Height(node->right) == -2) {
				if (data > node->right->data) { // means insertion occur on RR of node
					//we are performing LL rotation
					singleLeftRotation(node);

				}
				if (data < node->right->data) {// means insertion occur or RL of node
					singleRightRotaion(node->right);
					singleLeftRotation(node);
				}
			}
		}
		node->height = 1 + max(Height(node->left), Height(node->right));

	}
	void insert(t data) {
		insert(data, root);
	}
	void print(AvlNode<t>* root) {
		if (!root)
			return;
		queue<AvlNode<t>*> q;
		q.push(root);
		while (!q.empty()) {
			AvlNode<t>* current = q.front();
			q.pop();
			cout << current->data << " ";
			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
		}

	}
	void print() {
		print(root);
	}
	int balancingFactor(AvlNode<t>* node) {
		return (Height(node->left) - Height(node->right));
	}
	void deleteNode(int val, AvlNode<t>*& root) { // by raference root will help us to deleter 
		if (root == nullptr)
			return; // no node with val exist
		int bf = 0;
		if (val < root->data) { // val is less then move to left side
			deleteNode(val, root->left);
			bf = balancingFactor(root);
			

		}
		if (val > root->data) {
			deleteNode(val, root->right);
			bf = balancingFactor(root);
		}
		else if (val == root->data) { // we have reached to the node tobe deleted
			if (root->left == nullptr) {// manget will node to be deleted have only right child or no child
				AvlNode<t>* temp = root->right;
				delete root;
				root = temp;
				return;
			}
			if (root->right == nullptr) { // when root have only left child
				AvlNode<t>* temp = root->left;
				delete root;
				root = temp;
				return;
			}
			else { // root have both childs
				/* here we have more then two options*/
				AvlNode<t>* temp = root->right;
				while (temp->left) {
					temp = temp->left;
				}
				temp->left = root->left;
				temp = root;
				root = root->right;
				delete temp;
				return;

			}
		}
		if (bf == -1 || bf == 0 || bf == 1) {
			return;
		}
		else if (bf == 2) {
			int childbf = balancingFactor(root->left);
			if (childbf == 1) {
				singleLeftRotation(root);
			}
			else if (childbf == -1) {
				singleRightRotaion(root->left);
				singleLeftRotation(root);
			}
		}
		else if (bf == -2) {
			int childbf = balancingFactor(root->right);
			if (childbf == -1) {
				singleRightRotaion(root);
			}
			else if (childbf == 1) {
				singleLeftRotation(root->right);
				singleRightRotaion(root);
			}
		}

	}


	void deleteNode(t val) {
		if (root == NULL) {
			cout << "tree is empty\n";
			return;
		}
		deleteNode( val, root);
	}

};


int main() {
	AVLTree<int> tree;
	tree.insert(14);
	tree.insert(17);
	tree.insert(11);
	tree.insert(7);
	tree.insert(53);
	tree.insert(4);
	tree.insert(13);
	tree.insert(12);
	tree.insert(8);
	tree.insert(60);
	tree.insert(19);
	tree.insert(16);
	tree.insert(20);
	tree.deleteNode(20);
	tree.deleteNode(19);
	tree.deleteNode(16);

	tree.print();
}