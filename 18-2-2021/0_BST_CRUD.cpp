#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node {
    public:
    T value;
    Node<int> *left, *right;
    Node () {
        left = right = NULL;
    }

    Node (T _value) {
        value = _value;
        left = right = NULL;
    }
};

template <class T>
class BST {
    public:
    Node<T> *root = NULL;
    Node<T> *search(T value, Node<T> *root) {
        if(root == NULL) return NULL;
        if(root->value == value) return root;
        if(value < root->value) return search(value, root->left);
        return search(value, root->right);
    }

    void insertItem(T value) {
        if(root==NULL) {
            root = new Node<T>(value);
            return;
        }
        Node<T> *t = root, *pt = root;
        while(t!=NULL) {
            pt = t;
            if(value < t->value) t = t->left;
            else t = t->right;
        }
        if(value < pt->value) pt->left = new Node<T>(value);
        else pt->right = new Node<T>(value);
    }

    deleteItem(T value) {
        deleteItemUtil(root, value);
    }

    Node<T> *deleteItemUtil(Node<T> *n, T value) {
        if(n == NULL) return NULL;
        if(value<n->value) deleteItemUtil(n->left, value);
        else if(value>n->value) deleteItemUtil(n->right, value);
        else {
            if(n->left == NULL && n->right == NULL) {
                delete n;
                return NULL;
            }
            if(n->left == NULL) {
                Node<T> *t = n->right;
                delete n;
                return t;
            }
            if(n->right == NULL) {
                Node<T> *t = n->left;
                delete n;
                return t;
            }

            Node<T> *t = n->right;
            while(t->left != NULL) t = t->left;

            n->value = t->value;
            n->right = deleteItemUtil(n->right, t->value);
        }
    }

    void inorder() {
        inorderUtil(root);
        cout<<endl;
    }

    void inorderUtil(Node<T> *n) {
        if(n==NULL) return;
        inorderUtil(n->left);
        cout<< n->value << " ";
        inorderUtil(n->right);
    }
};

int main() {
    BST<int> b;
    b.insertItem(1);
    b.insertItem(3);
    b.insertItem(2);
    b.insertItem(6);
    b.insertItem(4);
    b.inorder();

    b.deleteItem(6);
    b.inorder();
    return 0;
}
