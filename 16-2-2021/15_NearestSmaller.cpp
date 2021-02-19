#include<bits/stdc++.h>
using namespace std;

void NearestSmaller(vector<int> arr) { 
    stack<int> s; 
    for (int i=0; i<arr.size(); i++) { 
        while (!s.empty() && s.top() >= arr[i]) s.pop(); 
        if (s.empty()) {
            cout << "_ "; 
        } else {
            cout<<s.top()<< " ";
        }
        s.push(arr[i]); 
    } 
} 

int main() {
    vector<int> arr = {1, 3, 2, 5, 4, 9, 4};
    NearestSmaller(arr);
    return 0;
}
