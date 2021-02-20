#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

Node *Mirror(Node *root) {
    if(root == NULL) return NULL;
    Node *t = new Node(root->value);
    t->left = Mirror(root->right);
    t->right = Mirror(root->left);
} 

void Inorder(Node* n) {
    if(n==NULL) return;
    Inorder(n->left);
    cout<<n->value<<" ";
    Inorder(n->right);
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->right->right = new Node(6);
    
    Inorder(root); cout<<endl;

    Node *mirror = Mirror(root);
    Inorder(mirror);

    return 0;
}
