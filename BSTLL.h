#include <iostream>

// Node class for LinkedList
class LinkedListNode {
public:
    int data;
    LinkedListNode* next;

    LinkedListNode() : data(0), next(nullptr) {}
    LinkedListNode(int data) : data(data), next(nullptr) {}
};

// LinkedList class definition
class LinkedList {
private:
    LinkedListNode* head;
    LinkedListNode* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();
    LinkedList(const LinkedList& ll);

    bool append(int val);
    bool prepend(int val);
    bool search(int val);
    bool remove(int val);
    void clear();
    void display(std::ostream& os);

    friend std::ostream &operator<<(std::ostream& os, LinkedList& ll);
};









// Node class for BST
class BSTNode {
public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode() : data(0), left(nullptr), right(nullptr) {}
    BSTNode(int data) : data(data), left(nullptr), right(nullptr) {}

    int degree() const;
};

// Binary Search Tree (BST) class definition
class BST {
private:
    BSTNode *root;

    void destroy(BSTNode *&node);
    void dup(BSTNode *node);

    bool insert(BSTNode *&node, int val);
    bool remove(BSTNode *&node, int val);
    bool search(BSTNode *node, int val);

    void inorder(BSTNode *node, std::ostream &os);
    void preorder(BSTNode *node, std::ostream &os);
    void postorder(BSTNode *node, std::ostream &os);

public:
    BST() : root(nullptr) {}
    ~BST() { clear(); }
    BST(const BST &bst) { dup(bst.root); }

    bool insert(int val) { return insert(root, val); }
    bool remove(int val) { return remove(root, val); }
    bool search(int val) { return search(root, val); }
    void clear();

    void inorder(std::ostream &os) { inorder(root, os); }
    void preorder(std::ostream &os) { preorder(root, os); }
    void postorder(std::ostream &os) { postorder(root, os); }
};