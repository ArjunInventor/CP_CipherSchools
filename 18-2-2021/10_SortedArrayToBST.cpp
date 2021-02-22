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

Node<int> *SortedArrayToBST(vector<int> arr, int l, int h) {
    if(l>h) return NULL;

    int m = (h+l)/2;
    Node<int> *root = new Node<int>(arr[m]);
    root->left = SortedArrayToBST(arr, l, m-1);
    root->right = SortedArrayToBST(arr, m+1, h);
    return root;
}

void Inorder(Node<int> *root) {
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->value<<" ";
    Inorder(root->right);
}

int main() {
    vector<int> arr = {2, 5, 7, 10, 22, 50};
    Node<int> *t = SortedArrayToBST(arr, 0, arr.size()-1);
    Inorder(t);
    return 0;
}
