#include<iostream>
#include<string>
using std::string;
class AssigneNode {
public:
    string AssigneId;
    AssigneNode* right;
    AssigneNode* left;
    AssigneNode* parent;
    AssigneNode* next;
    char color;
    string firstName;
    string lastName;
    string address;
    string DOB;
    bool isAssigned;
    AssigneNode() {
        
    }
    AssigneNode(string firstNames, string lastName, string add,string DOB,string AssigneId) {
        this->firstName = firstNames;
        this->lastName = lastName;
        this->address = add;
        this->DOB = DOB;
        this->AssigneId = AssigneId;
        color = 'R';
        left = NULL;
        right = NULL;
        parent = NULL;
        next = NULL;
        isAssigned = false;
    }
    AssigneNode& operator=(AssigneNode& t) {
        this->firstName = t.firstName;
        this->lastName = t.lastName;
        this->address = address;
        this->DOB = DOB;
        this->color = t.color;
        this->left = left;
        this->right = right;
        this->parent = parent;
        return *this;
    }
    bool operator<(AssigneNode&t) {
        return this->AssigneId < t.AssigneId;
    }
    bool operator<(string& t) {
        return  this->AssigneId < t;
    }
    bool operator>(AssigneNode& t) {
        return this->AssigneId > t.AssigneId;
    }
    bool operator==(AssigneNode& t) {
        return this->AssigneId == t.AssigneId;
    }
    bool operator>(string& t) {
        return  this->AssigneId >t;
    }
    bool operator==(string& t) {
        return t == this->AssigneId;
    }
    AssigneNode& copyData(AssigneNode& t) {
        this->firstName = t.firstName;
        this->lastName = t.lastName;
        this->address = t.address;
        this->DOB = t.DOB;
        this->AssigneId = t.AssigneId;
        this->isAssigned = t.isAssigned;
        return *this;
    }
    void sort(AssigneNode*s){}
};
class Task {
public:
    int priorityLevel;
    string Assigneid;
    int taskId;
    Task* left;
    Task* right;
    Task* next;
    Task* parent;
    string descriptions;
    char color;
    bool status;
    Task(int& taskId, string descriptions, int pL, string assingeId) {
        this->taskId = taskId;
        this->descriptions = descriptions;
        this->priorityLevel = pL;
        this->Assigneid = assingeId;
        color = 'R';
        status = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
        next = nullptr;
    }
    Task& operator=(Task& t) {
        this->taskId = t.taskId;
        this->descriptions = t.descriptions;
        this->priorityLevel = t.priorityLevel;
        this->Assigneid = t.Assigneid;
        this->color = t.color;
        this->left = left ;
        this->right = right;
        this->parent = parent;
        this->next = t.next;
        return *this;
    }
    bool operator<(Task& t) {
        return this->priorityLevel < t.priorityLevel;
    }
    bool operator>(Task& t) {
        return this->priorityLevel > t.priorityLevel;
    }
    bool operator==(Task& t) {
        return this->priorityLevel ==  t.priorityLevel;
    }
    bool operator<(string& t) {
        return this->Assigneid < t;
    }
    bool operator>(string& t) {
        return this->Assigneid > t;
    }
    bool operator==(string& t) {
        return t == this->Assigneid;
    }
    Task& copyData(Task& t) {
        this->descriptions = t.descriptions;
        this->Assigneid = Assigneid;
        this->taskId = t.taskId;
        this->priorityLevel = t.priorityLevel;
        this->next = t.next;
        Task* temp = this->next;
        while (temp) {
            temp->color = this->color;
            temp = temp->next;
        }
        if ( t.next) {
            t.next = nullptr;
        }
        return *this;
    }
    void sort(Task* node) {
        Task* temp1 = node;
        while (temp1) {
            Task* temp2 = temp1->next;
            while (temp2) {
                if (temp2->taskId < temp1->taskId) {
                    string tempDiscription = temp2->descriptions;
                    int temptaskId = temp2->taskId;
                    bool tempS = temp2->status;
                    string tempaSs = temp2->Assigneid;
                    temp2->descriptions = temp1->descriptions;
                    temp2->taskId = temp1->taskId;
                    temp2->status = temp1->status;
                    temp2->Assigneid = temp1->Assigneid;

                    temp1->descriptions = tempDiscription;
                    temp1->taskId = temptaskId;
                    temp1->status = tempS;
                    temp1->Assigneid = tempaSs;

                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
};
template<class t>
class RBTree {
public:
    t*root;
    RBTree() {
        root = nullptr;
    }
    void swapColor(t*&node1,t*&node2) {
        int tempC = node1->color;
        node1->color = node2->color;
        node2->color = tempC;
        t* temp = node1->next;
        while (temp) {
            temp->color = node1->color;
            temp = temp->next;
        }
        temp = node2->next;
        while (temp) {
            temp->color = node2->color;
            temp = temp->next;
        }
    }
    void Recolor(t* node) {
        if (node->color == 'B') {
            node->color = 'R';
            return;
        }
        node->color = 'B';
    }
    char getColor(t* node) {
        if (!node) {
            return 'B';
        }
        return node->color;
    }
    t* singleRightRotaion(t* node) {
        t* temp1 = node;
        t* temp2 = node->left;
        temp1->left = temp2->right;
        temp2->right = temp1;
        t* temp3 = node;
        node = temp2;
        if (temp3 != root) {
            if (temp3 == temp3->parent->left) {
                temp3->parent->left = node;
            }
            else {
                temp3->parent->right = node;
            }
        }
        else {
            this->root = temp2;
            root->parent = NULL;
        }
        if (temp1->parent) {
            temp2->parent = temp1->parent;
            t* temp3 = temp2->next;
            while (temp3) {
                temp3->parent = temp1->parent;
                temp3 = temp3->next;
            }
        }
        temp1->parent = temp2;
        t* temp4 = temp1->next;
        while (temp4) {
            temp4->parent = temp2;
            temp4 = temp4->next;
        }
        return node;

    }
    t* singleLeftRotation(t* node) {
        t* temp1 = node;
        t* temp2 = node->right;
        temp1->right = temp2->left;
        temp2->left = temp1;
        t* temp3 = node;
        node = temp2;
        if (temp3 != root) {
            if (temp3 == temp3->parent->left) {
                temp3->parent->left = node;
            }
            else {
                temp3->parent->right = node;
            }
        }
        else {
            this->root = temp2;
            this->root->parent = NULL;
        }
        if (temp1->parent) {
            temp2->parent = temp1->parent;
            t* temp3 = temp2->next;
            while (temp3) {
                temp3->parent = temp1->parent;
                temp3 = temp3->next;
            }
        }
        temp1->parent = temp2;
        t* temp4 = temp1->next;
        while (temp4) {
            temp4->parent = temp2;
            temp4 = temp4->next;
        }
        return node;
    }
    void insert(t*& data, t*& node) {
        if (node == NULL) {
            node = data;
            return;
        }
        if (*data < *node) {
            if (node->left == NULL) {
                node->left = data;
                node->left->parent = node;
                return;
            }
            else {
                insert(data, node->left);
            }
        }
        else if (*data > *node) {
            if (node->right == NULL) {
                node->right = data;
                node->right->parent = node;
                return;
            }
            else {
                insert(data, node->right);
            }
        }
        else if (*data == *node) {
            t* temp = node;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = data;
            temp->next->color = node->color; 
            temp->next->parent = temp->parent;   
            node->sort(node);
            return;
        }
    }
    void insert(t&data) {
        if (root == NULL) {
            root = new t(data);
            root->color = 'B';
            return;
        }
        t* node = new t(data);
        insert(node, root);
        fixAfterInsertion(node);
    }
    void fixAfterInsertion(t* ptr) {
        // first condition is the color of parent is black then no recolor no adjustment needed
        if (getColor(ptr->parent)== 'B')
            return;
        // if color is not black then remaintain tree
        t* parent = ptr->parent;
        t* uncle = nullptr;
        t* grandParent = parent->parent;

        while (ptr != root && getColor(ptr) == 'R' && getColor(parent) == 'R') {
            /*if parent is left child then uncle will be its right sibling*/

            if (parent == grandParent->left) {
                uncle = grandParent->right;
                if (getColor(uncle) == 'R') { // if unclde is red then just recolor both 
                    Recolor(uncle);
                    Recolor(parent);
                    ptr = grandParent;
                    parent = ptr->parent;
                    if (grandParent != root) {
                        Recolor(grandParent);
                    }
                    /* this is for the condition that if the parent is red and uncle is also red then
                    we will just recolor both parent and uncle and will move to higher to check that
                    if there any violation of RB tree property or not.
                    i.e if grandParent is root then there will not be any violation becasue the roo is
                    alwasy black.
                    */
                }
                /*if the uncle color is not red i.e if unclde is Black or null. we have to to some suitable roations*/
                else {
                    if (ptr == parent->right) {
                        /* as from above if the if (parent == grandParent->left)  if this condition true
                           then it means that grandParent is heavy  of left-right.
                           i.e we have to perform RL rotation.
                           left of grandParent's right child and right of grandParent it self
                        */
                        singleLeftRotation(parent);

                    }
                    t* p = singleRightRotaion(grandParent);
                    swapColor(p, p->right);
                }
            }
            /*if parent is right child then uncle will be its left sibling*/
            else {
                uncle = grandParent->left;
                if (getColor(uncle) == 'R') { // if unclde is red then just recolor both
                    Recolor(uncle);
                    Recolor(parent);
                    ptr = grandParent;
                    if (grandParent != root) {
                        Recolor(grandParent);
                    }
                }
                else {
                    if (ptr == parent->left) {
                        singleRightRotaion(parent);
                    }
                    t* p = singleLeftRotation(grandParent);
                    swapColor(p, p->left);

                }
            }
            parent = ptr->parent;
            if (parent)
                grandParent = parent->parent;
        }
        manageParent();
    }
    t* searchByAssigneId2(string id, t* current) {
        if (current == nullptr)
            return nullptr;
        if (*current > id)
            return searchByAssigneId2(id, current->left);
        else if ( *current < id)
            return searchByAssigneId2(id, current->right);
        else
            return current;
    }
    t* searchByAssigneId(const string& id) {
        if (root == nullptr)
            return nullptr;
        return searchByAssigneId2(id, root);
    }
    t* getSibling(t* curr, t* parent, char& childofParent) {
        if (!parent)
            return nullptr;
        if (curr == parent->left) {
            childofParent = 'L';
            return parent->right;
        }
        childofParent = 'R';
        return parent->left;
    }
    void updateNodeAndParent(t*& node, t*& parent) {
        node = parent;
        parent = node->parent;
    }
    void manageParent(t* node) {
        if (node == this->root)
            node->parent = nullptr;
        if (node->left) {
            node->left->parent = node;
            manageParent(node->left);
        }
        if (node->right) {
            node->right->parent = node;
            manageParent(node->right);
        }
    }
    void manageParent() {
        manageParent(root);
    }
    void FixAfterDeltion(t* node, t* parent, char childofParent) {
        std::cout << "fixAfterDeletion\n";
        t* sibling = nullptr;
        bool DbExist = true;
        if (childofParent == 'R') {
            sibling = parent->left;
        }
        else {
            sibling = parent->right;
        }
        while (DbExist) {
            if (node == this->root) { /*if Db is on root just remove Db and exit*/
                DbExist = false;
                return;
            }
            /*case#3 when sibling and both of siblings's children are balck */
            if (sibling) {
                if (getColor(sibling) == 'B' && getColor(sibling->left) == 'B' && getColor(sibling->right) == 'B') {
                    /*case#3.1 when sibling and both of siblings's children are balck and parent is red */
                    if (getColor(parent) == 'R') {
                        swapColor(parent, sibling);
                        DbExist = false;
                        return;
                    }
                    /*case#3.2 when sibling and both of siblings's children are balck and parent is black so parent become double balck*/
                    else {
                        Recolor(sibling);
                        updateNodeAndParent(node, parent);
                        sibling = getSibling(node, parent, childofParent);
                        DbExist = true;
                    }
                }
                /*case#4 when sibling is red*/
                else if (getColor(sibling) == 'R') {
                    if (parent && sibling) {
                        swapColor(parent, sibling);
                    }
                    if (childofParent == 'R') {
                        singleRightRotaion(parent);
                        node = node;
                        node = node;
                        if (parent)
                            sibling = parent->left;
                    }
                    else {
                        singleLeftRotation(parent);
                        node = node;
                        if (parent)
                            sibling = parent->right;
                    }
                }
                /*case#5 && case #6;
                *	case# 5 when sibling is black and sibling child which is far from DB(double black node) is black and nearer child to Db is red
                *	case# 6 when sibling is black and sibling child which is far from DB(double black node) is ridd
                */
                else if (getColor(sibling)) {
                    /*condition for nearer and far child of sibling of Db node*/
                    if (childofParent == 'L') {
                        if (getColor(sibling->right) == 'R') {
                            swapColor(parent, sibling);
                            singleLeftRotation(parent);
                            node = node;
                            Recolor(sibling->right);
                            if (parent)
                                sibling = parent->right;
                            DbExist = false;
                        }
                        else if (getColor(sibling->right) == 'B' && getColor(sibling->left) == 'R') {
                            swapColor(sibling, sibling->left);
                            sibling = singleRightRotaion(sibling);
                        }
                    }
                    else {
                        if (getColor(sibling->left) == 'R') {
                            swapColor(parent, sibling);
                            singleRightRotaion(parent);
                            node = node;
                            Recolor(sibling->left);
                            if (parent)
                                sibling = parent->left;
                            DbExist = false;
                        }
                        else if (getColor(sibling->left) == 'B' && getColor(sibling->right) && 'R') {
                            swapColor(sibling, sibling->right);
                            sibling = singleLeftRotation(sibling);

                        }
                    }
                }

            }
        }
    }
    t* makeDelete(t* root) {
        /*here we are not actully deleting the node but just returng the node which will actully
          get deleted.
        */
        char childofParent = '\0';
        t* p = root->parent;
        if (p) {
            if(p->left)
            if (*root == *(p->left)) {
                childofParent = 'L';
            }
            else if(p->right) {
                childofParent = 'R';
            }
        }
        if (p) {
            if (root->next) {
                if (childofParent == 'L') {
                    p->left = root->next;
                    p->left->right = root->right;
                    p->left->left = root->left;
                    p->left->next = root->next->next;
                }
                else {
                    p->right = root->next;
                    p->right->right = root->right;
                    p->right->left = root->left;
                    p->right->next = root->next->next;
                }
                delete root;
                return p;
            }
        }
        else if (root->next && root == this->root) {
            root->next->left = root->left;
            root->next->right = root->right;
            this->root = root->next;
            return nullptr;
        }
        if (root->left == NULL && root->right == NULL) {
            if (root == this->root) {
                delete root;
                root = nullptr;
                return nullptr;
            }
            t* p = root->parent;
            if (p) {
                // if this is true if means we have to delete a node 
                // from the linked list
                if (p->left != root && p->right != root) {
                    t* prev = nullptr;
                    t* curr = root;
                    if (*root < *p)
                        curr = p->left;
                    else
                        curr = p->right;
                    while (curr != root ) {
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = curr->next;
                    delete curr;
                    return p;
                }
            }
            char childofParent = '\0';
            bool doubleBlack = false;
            if (getColor(root) == 'B') {
                doubleBlack = true;
            }
            if (p) {
                if (p->left) {
                    if (*root == *(p->left)) {
                        p->left = nullptr;
                        childofParent = 'L';
                    }
                }
                if(p->right) {
                    if (*root == *(p->right)) {
                        p->right = nullptr;
                        childofParent = 'R';
                    }
                }
            }
            if (p) {
                if (root->next) {
                    if (childofParent == 'L') {
                        p->left = root->next;
                        p->left->right = root->right;
                        p->left->left = root->left;
                        p->left->next = root->next->next;
                    }
                    else {
                        p->right = root->next;
                        p->right->right = root->right;
                        p->right->left = root->left;
                        p->right->next = root->next->next;
                    }
                    delete root;
                    return p;
                }
            }
            delete root;
            root = nullptr;
            if (doubleBlack) {
                FixAfterDeltion(root, p, childofParent);
                manageParent();
            }
            return p;
        }
        if (root->left == NULL) {
            t* temp = root->right;
            root->copyData(*temp);;
            return makeDelete(temp);
        }
        if (root->right == NULL) {
            t* temp = inorderPredessor(root);
            root->copyData(*temp);
            return makeDelete(temp);
        }
        else { // root have both childs
            /*deleion with inorderPredssor*/
            t* temp = inorderPredessor(root);
            root->copyData(*temp);
            return makeDelete(temp);
        }
    }
    t* deleteNode(t*&node, t*& root) { // by raference root will help us to deleter 
        if (root == nullptr)
            return nullptr; // no node with val exist
        if (*node < *root) { // val is less then move to left side
            return deleteNode(node, root->left);
        }
        if (*node > *root) {
            return deleteNode(val, root->right);
        }
        else if (*node == *root) { // we have reached to the node tobe deleted
            return makeDelete(root);
        }
    }
    void deleteNode(string&id) {
        /*deletion is inorder predessor*/
        if (root == NULL) {
            std::cout << "tree is empty\n";
            return;
        }
        t* node = searchByAssigneId(id);
        t* pos =  makeDelete(node);
    }
    t* inorderSuccor(t* node) {
        if (node == NULL)
            return NULL;
        node = node->right;
        while (node->left) {
            node = node->left;
        }
        return node;

    }
    t* inorderPredessor(t* node) {
        if (node == NULL)
            return NULL;
        node = node->left;
        while (node->right) {
            node = node->right;
        }
        return node;

    }
   
};
class Assigne :public RBTree<AssigneNode> {
public:
    void searchByName(std::stringstream& output, const string& fName, const string& lName, AssigneNode*& current) {
        if (current == NULL)
            return;
        if (fName == current->firstName && lName == current->lastName) {
            output << "Name: " << current->firstName << " " << current->lastName
                << ", Address: " << current->address
                << ", DOB: " << current->DOB
                << ", Assignee ID: " << current->AssigneId << "\n";
        }
        searchByName(output, fName, lName, current->left);
        searchByName(output, fName, lName, current->right);
    }
    void searchByName(std::stringstream& output, const string& fName, const string& lName) {
        if (root == nullptr)
            return;
        searchByName(output, fName, lName, root);
    }
    AssigneNode* searchByAssigneId2(string id, AssigneNode* current) {
        if (current == nullptr)
            return nullptr;
        if (id < current->AssigneId)
            return searchByAssigneId2(id, current->left);
        else if (id > current->AssigneId)
            return searchByAssigneId2(id, current->right);
        else
            return current;
    }
    AssigneNode* searchByAssigneId(const string& id) {
        if (root == nullptr)
            return nullptr;
        return searchByAssigneId2(id, root);
    }
    void ToogleMarkAssigned(string id) {
        AssigneNode* assine = searchByAssigneId(id);
        if(assine)
        if (!assine->isAssigned)
            assine->isAssigned = true;
        else
            assine->isAssigned = false;
    }
    bool getAssidnedStatus(string id) {
        AssigneNode* assine = searchByAssigneId(id);
        if (assine) {
            if (assine->isAssigned)
                return 1;
        }
        return 0;
    }
    void SearchNotAssigned(std::stringstream& output,AssigneNode*current) {
        if (current == NULL)
            return;
        SearchNotAssigned(output, current->left);
        if (!current->isAssigned) {
            output << "Name: " << current->firstName << " " << current->lastName
                << ", Address: " << current->address
                << ", DOB: " << current->DOB
                << ", Assignee ID: " << current->AssigneId << "\n";
        }
        SearchNotAssigned(output, current->right);

    } 
    void SearchNotAssigned(std::stringstream& output) {
        SearchNotAssigned(output, root);
    }
    void inorder(std::stringstream& output, AssigneNode*& current) {
        if (current == nullptr)
            return;
        inorder(output, current->left);
        output << "Name: " << current->firstName << " " << current->lastName
            << ", Address: " << current->address
            << ", DOB: " << current->DOB
            << ", Assignee ID: " << current->AssigneId << "\n";
        inorder(output, current->right);
    }
    void inorder(std::stringstream& output) {
        inorder(output, root);
    }
    void AssigneAndColor(std::stringstream& output,AssigneNode*&current) {
        if (current == NULL)
            return;
        AssigneAndColor(output, current->left);
        output << current->AssigneId;
        if (getColor(current) == 'B')
            output << " (black)\n";
        else
            output << " (red)\n";
        AssigneAndColor(output, current->right);
    }
    void AssigneAndColor(std::stringstream& output) {
        AssigneAndColor(output, root);
    }
};
class Tasks :public RBTree<Task> {
public:
    void ShiftTask(const string& id1, const string& id2, Task* t) {
        if (t == nullptr)
            return;
        ShiftTask(id1, id2, t->left);
        if (t->Assigneid == id1) {
            if (t->status == 0) {
                t->Assigneid = id2;
            }
        }
        ShiftTask(id1, id2, t->right);
    }
    void ShiftTask(const string& id1, const string& id2) {
        ShiftTask(id1, id2, root);
    }
   
    void inorder(std::stringstream& output, Task* node, Assigne&Assignes) {
        if (node == NULL)
            return;
        inorder(output,node->left, Assignes);
        if (node->status == 0) {
            output << "Task ID: " << node->taskId
                << ", Description: " << node->descriptions
                << ", Priority: " << node->priorityLevel
                << ", Assignee: ";// << node->Assigneid << "\n";
            AssigneNode* a = Assignes.searchByAssigneId(node->Assigneid);
            output << a->firstName << " (" << a->AssigneId << ")" << "\n";;
        }
        Task* temp = node->next;
        while (temp){
            if (temp->status == 0) {
                output << "Task ID: " << temp->taskId
                    << ", Description: " << temp->descriptions
                    << ", Priority: " << temp->priorityLevel
                    << ", Assignee: ";// << node->Assigneid << "\n";
                AssigneNode* a = Assignes.searchByAssigneId(temp->Assigneid);
                output << a->firstName << " (" << a->AssigneId << ")" << "\n";;
            }
            temp = temp->next;
        }
       inorder(output, node->right, Assignes);
    }
    void inorder(std::stringstream& output, Assigne&Assignes) {
        inorder(output, root, Assignes);
    }    
    Task* searchByTaskId(int &id,Task*&current){
        if (!current)
            return nullptr;
        if (current->taskId == id) {
            return current;
        }
        Task* temp = current->next;
        while (temp) {
            if (temp->taskId == id) {
                return temp;
            }
            temp = temp->next;
        }
        Task*l = searchByTaskId(id, current->left);
        Task*R = searchByTaskId(id, current->right);
        return l != nullptr ?  l :  R;
    }
    Task* searchByTaskId(int &id){
        return  searchByTaskId(id, root);
    }
    void markedCompleted(int & id) {
        Task*t = searchByTaskId(id);
        t->status = 1;
    }
    void updateTaskPriority(int&taskId, int&newPriority) {
        Task* t = searchByTaskId(taskId);
        Task newTask(t->taskId, t->descriptions, newPriority, t->Assigneid);
        newTask.status = t->status;
        if (t->status == 0) {
            makeDelete(t);
            insert(newTask);
        }
    }
    void findHighestPriorityTask(Task*current,Task*&Hp) {
        if (current == nullptr)
            return;
        findHighestPriorityTask(current->left, Hp);
        if (current->priorityLevel < Hp->priorityLevel || Hp->status == 1) {
            if(current->status == 0)
                  Hp = current;
            else {
                Task* temp = current->next;
                while (temp) {
                    if (temp->priorityLevel < Hp->priorityLevel || Hp->status == 1)
                    if (temp->status == 0)
                        Hp = temp;
                    temp = temp->next;
                }
            }

        }
        findHighestPriorityTask(current->right, Hp);
    } 
    void findHighestPriorityTask(std::stringstream& output,Assigne& Assignes) {
        Task* Hp = root;
        findHighestPriorityTask(root, Hp);
        if (Hp->status == 0) {
            output << "Highest Priority Task: "
                << "Task ID: " << Hp->taskId
                << ", Description: " << Hp->descriptions
                << ", Priority: " << Hp->priorityLevel
                << ", Assignee: ";
            AssigneNode* a = Assignes.searchByAssigneId(Hp->Assigneid);
            output << a->firstName << " (" << a->AssigneId << ")" << "\n";
        }
        Task* temp = Hp->next;
        while (temp) {
            if (temp->status == 0) {
                output << "Highest Priority Task: "
                    << "Task ID: " << temp->taskId
                    << ", Description: " << temp->descriptions
                    << ", Priority: " << temp->priorityLevel
                    << ", Assignee: ";
                AssigneNode* a = Assignes.searchByAssigneId(temp->Assigneid);
                output << a->firstName << " (" << a->AssigneId << ")" << "\n";
            }
            temp = temp->next;
        }
    }
    void findTasksByAssignee(string& assgneID, std::stringstream& output,Task*&node,Assigne& Assignes) {
        if (node == nullptr)
            return;
        findTasksByAssignee(assgneID, output, node->left, Assignes);
        if (node->Assigneid == assgneID) {
            if (node->status == 0) {
                AssigneNode* t = Assignes.searchByAssigneId(assgneID);
                output << "Task ID: " << node->taskId
                    << ", Description: " << node->descriptions
                    << ", Priority: " << node->priorityLevel
                    << ", Assignee: ";
                output << t->firstName << " (" << t->AssigneId << ")" << "\n";;
            }
        }
        Task* temp = node->next;
        while (temp) {
            if (temp->Assigneid == assgneID) {
                if (temp->status == 0) {
                    AssigneNode* t = Assignes.searchByAssigneId(assgneID);
                    output << "Task ID: " << temp->taskId
                        << ", Description: " << temp->descriptions
                        << ", Priority: " << temp->priorityLevel
                        << ", Assignee: ";
                    output << t->firstName << " (" << t->AssigneId << ")" << "\n";;
                }
            }
            temp = temp->next;

        }
        findTasksByAssignee(assgneID, output, node->right, Assignes);
    }
    void findTasksByAssignee(string&assgneID, std::stringstream& output,Assigne& Assignes) {
        AssigneNode* t = Assignes.searchByAssigneId(assgneID);
        output << "Tasks Assigned to \"" << t->firstName << " (" << assgneID << ")\":\n";
        findTasksByAssignee(assgneID, output, root, Assignes);
    }
    void countTotalTasks(std::stringstream& output, Task* node, int& count) {
        if (node == nullptr)
            return;
        if(node->status == 0)
        count++;
        Task* temp = node->next;
        while (temp) {
            if (temp->status == 0)
            count++;
            temp = temp->next;
        }
        countTotalTasks(output, node->left,count);
        countTotalTasks(output, node->right,count);

    }
    void countTotalTasks(std::stringstream& output) {
        output << "Total Tasks in the System: ";
        int count = 0;
        countTotalTasks(output, root,count);
        output << count << "\n";
    }
    void displayCompletedTasks(std::stringstream& output,Task*node,Assigne& Assignes) {
        if (!node)
            return;
        displayCompletedTasks(output, node->left,Assignes);
        if (node->status) {
            output << "Task ID: " << node->taskId
                << ", Description: " << node->descriptions
                << ", Priority: " << node->priorityLevel
                << ", Assignee: ";// << Hp->Assigneid << "\n";
            AssigneNode* a = Assignes.searchByAssigneId(node->Assigneid);
            output << a->firstName << " (" << a->AssigneId << ")" << "\n";;
        }
        Task* temp = node->next;
        while (temp) {
            if (temp->status) {
                output << "Task ID: " << temp->taskId
                    << ", Description: " << temp->descriptions
                    << ", Priority: " << temp->priorityLevel
                    << ", Assignee: ";// << Hp->Assigneid << "\n";
                AssigneNode* a = Assignes.searchByAssigneId(temp->Assigneid);
                output << a->firstName << " (" << a->AssigneId << ")" << "\n";;
            }
            temp = temp->next;
        }
        displayCompletedTasks(output, node->right,Assignes);
    } 
    void displayCompletedTasks(std::stringstream& output,Assigne&Assignes) {
        output << "Completed Tasks:\n";
        displayCompletedTasks(output, root, Assignes);
    }
    void searchTasksByPriorityRange(int& start, int& end, std::stringstream& output,Task*node,Assigne& Assignes) {
        if (!node)
            return;
        searchTasksByPriorityRange(start, end, output, node->left, Assignes);
        if (node->priorityLevel >= start && node->priorityLevel <= end) {
            AssigneNode* t = Assignes.searchByAssigneId(node->Assigneid);
            if (node->status == 0) {
                output << "Task ID: " << node->taskId
                    << ", Description: " << node->descriptions
                    << ", Priority: " << node->priorityLevel
                    << ", Assignee: ";
                output << t->firstName << " (" << t->AssigneId << ")" << "\n";;
            }
        }
        Task* temp = node->next;
        while (temp) {
            if (temp->priorityLevel >= start && temp->priorityLevel <= end) {
                AssigneNode* t = Assignes.searchByAssigneId(temp->Assigneid);
                if (temp->status) {
                    output << "Task ID: " << temp->taskId
                        << ", Description: " << temp->descriptions
                        << ", Priority: " << temp->priorityLevel
                        << ", Assignee: ";
                    output << t->firstName << " (" << t->AssigneId << ")" << "\n";;
                }
            }
            temp = temp->next;
        }
        searchTasksByPriorityRange(start, end, output, node->right, Assignes);
    }
    void searchTasksByPriorityRange(int& start, int& end, std::stringstream& output, Assigne& Assignes) {
        output << "Tasks within Priority Range (" << start << " to " << end << "):\n";
        searchTasksByPriorityRange(start, end, output, root, Assignes);
    }
    void TasksByColor(std::stringstream& output, Task*& current) {
        if (current == NULL)
            return;
        TasksByColor(output, current->left);
        if (current->status == 0) {
            output << current->taskId;
            if (getColor(current) == 'B')
                output << " (black)\n";
            else
                output << " (red)\n";
        }
        Task* temp = current->next;
        while (temp) {
            if (current->status == 0) {
                output << temp->taskId;
                if (getColor(temp) == 'B')
                    output << " (black)\n";
                else
                    output << " (red)\n";
            }
            temp = temp->next;
        }        
        TasksByColor(output, current->right);
    }
    void TasksByColor(std::stringstream& output) {
        TasksByColor(output, root);
    }
    void deleteTask(int& Taskid) {
        Task*t =  searchByTaskId(Taskid);
        makeDelete(t);
    }
    void print(Task* root) {
        if (!root)
            return;
        print(root->left);
        std::cout << root->priorityLevel << " "<<root->taskId<<" " << root->color << "\n";
        Task* temp = root->next;
        while (temp) {
            std::cout << root->priorityLevel << " " << root->taskId << " " << root->color << "\n";
            temp = temp->next;
        }
        print(root->right);
    }
    void print() {
        print(root);
    }
};
class taskManagementSystem {
public:
    Assigne Assignes;
    Tasks tasks;
    int noofAssignes;
    taskManagementSystem() {
        noofAssignes = 0;
    }
    void addAssignee(string fName, string lName, string address, string Db) {
        noofAssignes++;
        string assId = "";
        if(noofAssignes < 10)
            assId  = "A00" + std::to_string(noofAssignes);
        else {
            assId = "A0" + std::to_string(noofAssignes);
        }
        AssigneNode n(fName, lName, address, Db,assId);
        Assignes.insert(n);
    }
    void displaybyID(std::stringstream& output, string id) {
        AssigneNode*node = Assignes.searchByAssigneId(id);
        if (node) {
            output << "Name: " << node->firstName << " " << node->lastName
                << ", Address: " << node->address
                << ", DOB: " << node->DOB
                << ", Assignee ID: " << node->AssigneId << "\n";
        }        
    }
    void displaybyname(std::stringstream& output,string fName,string lName) {
          Assignes.searchByName(output,fName,lName);
    }
    void addTask(int taskId, string discription, int priorityLevel, string assingeId ) {
        Task t(taskId, discription, priorityLevel, assingeId);
        tasks.insert(t);
        Assignes.ToogleMarkAssigned( assingeId);
    }
    void AssigneeWithNoTask(std::stringstream& output) {
        Assignes.SearchNotAssigned(output);
    }
    void ShiftTask(string id1, string id2) {
        tasks.ShiftTask(id1, id2);
        Assignes.ToogleMarkAssigned(id1);
        if(!Assignes.getAssidnedStatus(id2))
        Assignes.ToogleMarkAssigned(id2);
    }
    void printTaskQueue(std::stringstream& output) {
        tasks.inorder(output,Assignes);
    }
    void DeleteAssignee(string id) {
        Assignes.deleteNode(id);
    }
    void DisplayAssignee(std::stringstream& output){
        Assignes.inorder(output);
    }
    void AssigneeInOrder(std::stringstream& output){
        Assignes.AssigneAndColor(output);
    }
    void completeTask(int taskID){
        tasks.markedCompleted(taskID);
    }
    void updateTaskPriority(int taskId,int newPriority){
        tasks.updateTaskPriority(taskId, newPriority);
    }
    void findHighestPriorityTask(std::stringstream& output) {
        tasks.findHighestPriorityTask(output, Assignes);
    }
    void findTasksByAssignee(string assgneID, std::stringstream& output) {
        tasks.findTasksByAssignee(assgneID, output,Assignes);
    }
    void countTotalTasks(std::stringstream&actualOutput) {
        tasks.countTotalTasks(actualOutput);
    }
    void displayCompletedTasks(std::stringstream& actualOutput) {
        tasks.displayCompletedTasks(actualOutput,Assignes);
    }
    void searchTasksByPriorityRange(int start, int end, std::stringstream& actualOutput) {
        tasks.searchTasksByPriorityRange(start, end, actualOutput,Assignes);
    }
    void PrintTreeInorder(std::stringstream&actualOutput) {
        tasks.TasksByColor(actualOutput);
    }
    void deleteTask(int taskId) {
        tasks.deleteTask(taskId);
    }
};
