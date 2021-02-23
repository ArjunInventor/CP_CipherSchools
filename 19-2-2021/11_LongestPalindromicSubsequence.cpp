#include<bits/stdc++.h>
using namespace std;

int LongestPalindromicSubsequence(string str) { 
    int n = str.length(); 
    int i, j, k; 
    vector<vector<int>> table(n, vector<int>(n, 1));
    for (i=2; i<=n; i++) { 
        for (j=0; j<n-i+1; j++) { 
            if (str[j] == str[j+i-1] && i == 2) {
                table[j][j+i-1] = 2; 
            } else if (str[j] == str[j+i-1])  {
                table[j][j+i-1] = table[j+1][j+i-2] + 2; 
            } else {
                table[j][j+i-1] = max(table[j][j+i-2], table[j+1][j+i-1]); 
            }
        } 
    } 
    return table[0][n-1]; 
} 
  
int main() {
    string str = "BCDCBA";
    cout<<LongestPalindromicSubsequence(str);
    return 0; 
} 
