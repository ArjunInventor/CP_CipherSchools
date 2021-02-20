#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

int Sum(Node *root) {
    if(root == NULL) return 0;
    return Sum(root->left) +
            Sum(root->right) +
            root->value;
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    cout<<Sum(root);
    return 0;
}
