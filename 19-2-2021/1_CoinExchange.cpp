#include<bits/stdc++.h>
using namespace std;

int count(vector<int> coins, int n) { 
    vector<int> table(n+1, 0);
    table[0] = 1; 
    for(int i=0; i<coins.size(); i++)  {
        for(int j=coins[i]; j<=n; j++) {
            table[j] += table[j-coins[i]]; 
        }
    }
    return table[n]; 
} 

int main() { 
    vector<int> arr = {1, 2, 5, 10}; 
    cout<<count(arr, 20);
    return 0; 
} 
