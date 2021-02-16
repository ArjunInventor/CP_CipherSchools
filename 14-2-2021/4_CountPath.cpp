  
#include <bits/stdc++.h> 
using namespace std; 

int CountPathHelper(vector<vector<int>> &cache, int m, int n) { 
    if (m == 1 || n == 1) return 1; 
    if(cache[m-1][n-1] != -1) return cache[m-1][n-1];
    int res = CountPathHelper(cache, m - 1, n) + CountPathHelper(cache, m, n - 1); 
    cache[m-1][n-1] = res;
    return res;
} 

int CountPath(int m, int n) {
    vector<vector<int>> cache(m, vector<int>(n, -1));
    return CountPathHelper(cache, m, n);
}
  
int main() 
{ 
    cout << CountPath(4, 4); 
    return 0; 
} 