#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

void PrintKDistance(Node *root, int &distance, int currDistance=0) {
    if(root==NULL) return;
    if(distance==currDistance)
        cout<<root->value<<" ";
    PrintKDistance(root->left, distance, currDistance+1);
    PrintKDistance(root->right, distance, currDistance+1);
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->right->right = new Node(6);

    int distance = 2;
    PrintKDistance(root, distance);
    return 0;
}
