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

void Preorder(Node<int> *n) {
    if(n==NULL) return;
    cout<<n->value<<" ";
    Preorder(n->left);
    Preorder(n->right);
}

void Inorder(Node<int>* n) {
    if(n==NULL) return;
    Inorder(n->left);
    cout<<n->value<<" ";
    Inorder(n->right);
}

void Postorder(Node<int> *n) {
    if(n==NULL) return;
    Postorder(n->left);
    Postorder(n->right);
    cout<<n->value<<" ";
}

int Height(Node<int> *n) {
    if (n == NULL) return 0;
    return 1 + max(Height(n->left), Height(n->right));
}

void printNLevel(Node<int> *n, int level) {
    if (n == NULL) return;
    if (level == 1) { 
        cout << n->value << " ";
        return;
    }
    level--;
    printNLevel(n->left, level);
    printNLevel(n->right, level);
      
}

void LevelOrder(Node<int> *n) {
    if (n == NULL)
        return;
    int h = Height(n);
    for (int level = 1; level <= h; level++) {
        printNLevel(n, level);
    }
}

int main() {
    Node<int> *root = new Node<int>(5);
    root->left = new Node<int>(3);
    root->right = new Node<int>(8);
    root->left->right = new Node<int>(4);
    root->right->left = new Node<int>(7);
    root->right->right = new Node<int>(12);
    
    cout<<"Preorder: "; Preorder(root); cout<<endl;
    cout<<"Inorder: "; Inorder(root); cout<<endl;
    cout<<"Postorder: "; Postorder(root); cout<<endl;
    cout<<"Levelorder: "; LevelOrder(root); cout<<endl;

    return 0;
}
