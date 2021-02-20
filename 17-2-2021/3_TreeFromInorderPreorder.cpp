#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    Node() { left = right = NULL; }
    Node(int v) { value = v; left = right = NULL; }
};

Node *BuildTree(vector<int> &inorder, vector<int> &preorder, vector<int>::iterator s, vector<int>::iterator e) {
    if(distance(s, e) < 1) return NULL;
    static int p = 0;
    Node *n = new Node(preorder[p++]);
    if(distance(s, e) == 1) return n;
    auto m = find(s, e, preorder[p]);

    n->left = BuildTree(inorder, preorder, s, m-1);
    n->right = BuildTree(inorder, preorder, m+1, e);
    
    return n;
}

void PrintInorder(Node *root) {
    if(root==NULL) return;
    PrintInorder(root->left);
    cout<<root->value<<" ";
    PrintInorder(root->right);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    Node *root = BuildTree(inorder, preorder, inorder.begin(), preorder.begin());
    PrintInorder(root);
    return 0;
}
