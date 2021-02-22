#include <bits/stdc++.h>
using namespace std;
 
int LongestNonRepeating(string str) {
    int n = str.size();
    int longest = 0;
    unordered_map()
    vector<int> l(256, 0);
 
    int i = 0;
 
    for (int j = 0; j < n; j++) {
        i = max(i, l[str[j]] + 1);
        longest = max(longest, j - i + 1);
        l[str[j]] = j;
    }
    return longest;
}
 
int main() {
    string str = "hellothere";
    cout<<LongestNonRepeating(str);
    return 0;
}
