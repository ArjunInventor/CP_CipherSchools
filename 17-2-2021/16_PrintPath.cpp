#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

void PathPrint(Node *root, vector<int> path) {
    if(root == NULL) {
        for(auto i:path) cout<<i<<"->";
        cout<<endl; 
        return;
    }

    path.push_back(root->value);
    PathPrint(root->left, path);
    PathPrint(root->right, path);
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    vector<int> path;
    PathPrint(root, path);
    return 0;
}
