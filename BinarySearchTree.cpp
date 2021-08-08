#include "BinarySearchTree.h"


 
void BinarySearchTree::insert(int d) {
    tree_node* t = new tree_node(d); 
    tree_node* parent;
    t->setLeft(NULL); 
    t->setRight(NULL); 
    parent = NULL; 
    if (isEmpty()){
        root = t;
    } 
    else { 
        //Note: ALL insertions are as leaf nodes 
        tree_node* curr; 
        curr = root;
        // Find the Node's parent 
        while (curr) { 
            parent = curr; 
            if (t->getData() > curr->getData()){
                curr = curr->getRight();
            } 
            else{
                curr = curr->getLeft();
            } 
        }
        //if the data inserted is less than parent, move to the
        //left child of the binary search tree
        if (t->getData() < parent->getData()){ 
            parent->setLeft(t);
        }
        else{
        //else move to the right child
            parent->setRight(t); 
        }
    } 
}
void BinarySearchTree::remove(int d) { 
    //Locate the element 
    bool found = false; 
    if (isEmpty()){ 
        cout << " This Tree is empty! " << endl; 
        return; 
    } 
    tree_node* curr; 
    tree_node* parent; 
    curr = root; 
    parent = curr;  
    while (curr != NULL) { 
        if (curr->getData() == d) { 
            found = true; 
            break; 
        } 
        else {
            parent = curr; 
            if (d>curr->getData()) 
                {curr = curr->getRight();} 
            else 
                {curr = curr->getLeft();} 
        } 
    } 
    if (!found) {
        cout<< " Data not found! " << endl; 
        return; 
    }
    // 3 cases : 
    // 1. We're removing a leaf node 
    // 2. We're removing a node with a single child 
    // 3. we're removing a node with 2 children

    // Node with single child 
    if ((curr->getLeft() == NULL && curr->getRight() != NULL) || (curr->getLeft() != NULL && curr->getRight() == NULL)) { 
        if (curr->getLeft() == NULL && curr->getRight() != NULL) { 
            if (parent->getLeft() == curr) { 
                parent->setLeft ( curr->getLeft()); 
                delete curr; 
            } 
            else { 
                parent->setRight(curr->getRight()); 
                delete curr; 
                } 
        } 
        else // left child present, no right child 
        { 
            if (parent->getLeft() == curr) {
                 parent->setLeft(curr->getLeft()); 
                 delete curr; 
            } 
            else {
                parent->setRight(curr->getLeft()); 
                delete curr; 
            } 
        } 
    return; 
    }
    //We're looking at a leaf node 
    if (curr->getLeft() == NULL && curr->getRight() == NULL) { 
        if (parent->getLeft() == curr) 
            parent->setLeft(NULL); 
        else 
            parent->setRight(NULL); 
            delete curr; 
            return; 
    }
    //Node with 2 children 
    // replace node with smallest value tright subtree 
    if (curr->getLeft() != NULL && curr->getRight() != NULL) { 
        tree_node* chkr; 
        chkr = curr->getRight(); 
        if ((chkr->getLeft() == NULL) && (chkr->getRight() == NULL)) { 
            curr = chkr; 
            delete chkr; 
            curr->setRight(NULL); 
        } 
        else // right child has children 
        { //if the node's right child has a left child 
        // Move all the way down left to locate smallest element
            if ((curr->getRight())->getLeft() != NULL) { 
                tree_node* lcurr; 
                tree_node* lcurrp; 
                lcurrp = curr->getRight(); 
                lcurr = (curr->getRight())->getLeft(); 
                while (lcurr->getLeft() != NULL) { 
                    lcurrp = lcurr;
                    lcurr = lcurr->getLeft(); 
                } 
                curr->setData( lcurr->getData()); 
                delete lcurr; 
                lcurrp->setLeft(NULL); 
            } 
            else { 
                tree_node* tmp; 
                tmp = curr->getRight(); 
                curr->setData( tmp->getData()); 
                curr->setRight( tmp->getRight()); 
                delete tmp; 
            }
        } 
        return; 
    }
}

//prints node in non-decreasing order in_order(left,root,right)
void BinarySearchTree::print_inorder() {
    inorder(root); 
}

void BinarySearchTree::inorder(tree_node* p) {
    if (p != NULL) { 
        if (p->getLeft()) 
            inorder(p->getLeft()); 
        cout << " " << p->getData() << " "; 
        if (p->getRight()) 
            inorder(p->getRight()); 
    } 
    else return; 
}

//prints node in non-decreasing order pre_order(root,left,right)
void BinarySearchTree::print_preorder() { 
    preorder(root); 
}

void BinarySearchTree::preorder(tree_node* p){ 
    if (p != NULL) { 
        cout << " " << p->getData() << " "; 
        if (p->getLeft()) 
            preorder(p->getLeft()); 
            if (p->getRight()) 
            preorder(p->getRight()); 
    } 
    else 
        return; 
}

//prints nodes in non-increasing order post_order(left,right,root)
void BinarySearchTree::print_postorder() { 
    postorder(root); 
}

void BinarySearchTree::postorder(tree_node* p) { 
    if (p != NULL) { 
        if (p->getLeft()) 
            postorder(p->getLeft()); 
        if (p->getRight()) 
            postorder(p->getRight()); 
            cout << " " << p->getData() << " "; 
    } 
    else 
    return; 
}

int BinarySearchTree::searchTree(tree_node *p, int data){
    if(p==NULL){
        return 0;
    }
    else if(p->getData()==data){
        return 1;
    }
    else if(p->getData()<data){
        return searchTree(p->getRight(), data);
    }
    else{
        return searchTree(p->getLeft(), data);
    }
}

int BinarySearchTree::search(int data){
    return searchTree(root,data);
}

void BinarySearchTree::update(int OLD, int NEW){
    if(search(OLD)==1){
        remove(OLD);//removes old data
        insert(NEW);//inserts new data
    }
    else{
        cout<<"Data for Old not found!"<<endl;

    }

}


