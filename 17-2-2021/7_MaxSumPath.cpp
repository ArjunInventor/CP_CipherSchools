#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

int MaxSum(Node *root) {
    if(root == NULL) return 0;
    return root->value + max(MaxSum(root->left), MaxSum(root->right));
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    
    cout<<MaxSum(root);
    return 0;
}
