#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

bool CheckBST(Node* root, Node* left, Node* right) { 
    if (root == NULL) return true; 
    if (left != NULL && left->value > root->value) return false; 
    if (right != NULL && right->value < root->value) return false; 
    return CheckBST(root->left, left, root) && CheckBST(root->right, root, right); 
} 

int main() {
    Node * root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    cout<<(CheckBST(root, NULL, NULL)?"TRUE":"FALSE");
    return 0;
}
