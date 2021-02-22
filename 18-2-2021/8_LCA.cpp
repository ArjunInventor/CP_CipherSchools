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

Node<int> *LCA(Node<int> *root, int a, int b) {  
    if (root == NULL) return root;  
    if (root->value > a && root->value > b)  
        return LCA(root->left, a, b);  
  
    if (root->value < a && root->value < b)  
        return LCA(root->right, a, b);  
  
    return root;  
}  

int main() {
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(6);
    root->right = new Node<int>(16);
    root->left->left = new Node<int>(2);
    root->left->right = new Node<int>(4);
    root->right->left = new Node<int>(13);
    
    cout<<LCA(root, 4, 14)->value;

    return 0;
}
