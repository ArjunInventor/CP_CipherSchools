#include <bits/stdc++.h> 
using namespace std; 
  
int kthSmallest(vector<int> a, int e) 
{ 
    set<int> s; 
    for (int i = 0; i < a.size(); i++) 
        s.insert(a[i]); 
    auto it = s.begin();
    advance(it, e-1);
    return *it;
} 
  
int main() 
{ 
    vector<int> a = { 5, 8, 2, 9, 12, 14 };

    int e = 2;

    cout << kthSmallest(a, e); 
    return 0; 
} 