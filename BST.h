// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* BST.h is a template class which implements a binary search tree consisting of Tree Nodes with data of arbitrary type. */

#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();

        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value);//search
        bool deleteNode(T k);
        T deleteNodeReturnValue(T k);
        T deleteRootNodeReturnValue();
        bool isEmpty();
        T* getMin();
        T* getMax();
        TreeNode<T> * getRootNode();
        TreeNode<T> * getSuccessor(TreeNode<T> *d);
        void printNodes();
        void recPrint(TreeNode<T> *node);
        void DestroyRecursive(TreeNode<T> *node);
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    DestroyRecursive(root);
}

template <class T>
void BST<T>::DestroyRecursive(TreeNode<T> *node)
{
    if (node)
    {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    // cout << node->key << endl;//preorder
    // recPrint(node->left);
    // recPrint(node->right);

    recPrint(node->left);//inorder
    cout << node->key << endl;
    recPrint(node->right);

    // recPrint(node->left);//postorder
    // recPrint(node->right);
    // cout << node->key << endl;
}

template <class T>
void BST<T>::printNodes(){
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){
    TreeNode<T> *current = root;//start at root

    if(root == NULL){
        //tree empty
        return NULL;
    }

    while(current->left != NULL){
        current = current->left;
    }

    return &(current->key);
}

template <class T>
T* BST<T>::getMax(){

    TreeNode<T> *current = root;//start at root

    if(root == NULL){
        //tree empty
        return NULL;
    }


    while(current->right != NULL){
        current = current->right;
    }


    return &(current->key);
}

template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);

    if(isEmpty()){
        root = node;
    }
    else{
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true){
            parent = current;

            if(value < current->key){
                // go left
                current = current->left;
                if(current == NULL){
                    //found insert point
                    parent->left = node;
                    break;
                }
            }
            else{
                // go right
                current = current->right;
                if(current == NULL){
                    //found insert point
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty()){
        return false;
    }
    else{
        TreeNode<T> *current = root;
        while((current->key) != value){
            if(value < current->key){
                current = current->left;
            }
            else{
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
    if(isEmpty()){
        return false;
    }
    if(!contains(k)){
        cout << "value does not exist, cannot delete()" << endl;
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    // lets find value so that we can set current and parent 

    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            return false;//value doesnt exist in tree (this is good when tree is massive bc not iterating through nodes twice)
        }
    }

    //found node to be deleted (it exists)

    // no children, leaf node
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }
    else if(current->right == NULL){
        //node to be deleted has left child and no right child
        if(current == root)
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if(current->left == NULL){
        //node to be deleted has right child and no left child
        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else{
        //node to be deleted has two children, at this point cry
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }

        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    return true;
}

template <class T>
T BST<T>::deleteNodeReturnValue(T k){
    if(isEmpty()){
        throw runtime_error("ERROR: TREE EMPTY.");
    }
    if(!contains(k)){
        throw runtime_error("ERROR: VALUE DOES NOT EXIST.");
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    // lets find value so that we can set current and parent 

    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            throw runtime_error("ERROR: VALUE DOES NOT EXIST.");//value doesnt exist in tree (this is good when tree is massive bc not iterating through nodes twice)
        }
    }

    T value = current->key;
    //found node to be deleted (it exists)

    // no children, leaf node
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }
    else if(current->right == NULL){
        //node to be deleted has left child and no right child
        if(current == root)
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if(current->left == NULL){
        //node to be deleted has right child and no left child
        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else{
        //node to be deleted has two children, at this point cry
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }

        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    return value;
}

template <class T>
T BST<T>::deleteRootNodeReturnValue(){
    T temp = getRootNode()->key;
    deleteNode(temp);
    return temp;
}

template <class T>
//d = node to be deleted
TreeNode<T> *BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;//successor parent
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    //if successor is descendant of right child
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class T>
//d = node to be deleted
TreeNode<T> *BST<T>::getRootNode(){
    return root;
}

#endif