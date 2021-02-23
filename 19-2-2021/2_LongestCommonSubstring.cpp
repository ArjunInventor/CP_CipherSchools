#include <iostream>
#include <string.h>
using namespace std;
 
int LongestSubstring(string str1, string str2) {
    int m=str1.length(), n=str2.length();
    int t[m + 1][n + 1];
    int result = 0; 

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i*j == 0) {
                t[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                t[i][j] = t[i - 1][j - 1] + 1;
                result = max(result, t[i][j]);
            } else {
                t[i][j] = 0;
            }
        }
    }
    return result;
}
 
int main()
{
    
    string str1 = "hello there";
    string str2 = "llo the";
    cout<<LongestSubstring(str1, str2);
    return 0;
}
