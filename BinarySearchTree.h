#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream> 
#include <iomanip>
using namespace std;

class tree_node{
    private:
        int data;
        tree_node *left;
        tree_node *right;

    public:
        tree_node() : left(NULL), right(NULL){}
        tree_node(int data) : data(data), left(NULL), right(NULL){}

        void setData(int data){this->data = data;}
        void setLeft(tree_node* left){this->left=left;}
        void setRight(tree_node* right){this->right = right;}
        int getData(){return data;} 
        tree_node* getLeft(){return left;}
        tree_node* getRight(){return right;}
};


class BinarySearchTree { 
    private: 
        tree_node* root; 
    public: 
        BinarySearchTree() { 
            root = NULL; 
        } 
        bool isEmpty() const {
            return root == NULL; 
        } 
        void print_inorder(); 
        void inorder(tree_node*); 
        void print_preorder(); 
        void preorder(tree_node*); 
        void print_postorder(); 
        void postorder(tree_node*);      
        void insert(int); 
        void remove(int);
        void update(int Old, int New);
        int searchTree(tree_node *, int);
        int search(int);
};

#endif