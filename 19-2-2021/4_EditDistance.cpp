#include <bits/stdc++.h>
using namespace std;


int EditDistance(string str1, int s1, string str2, int s2) {
    vector<int> t(s1*s2);
    for (int i = 1, im = 0; i < s2; ++i, ++im) {
        for (int j = 1, jn = 0; j < s1; ++j, ++jn) {
            if (str1[jn] == str2[im]) {
                t[(i*s1)+j] = t[((i-1) * s1) + (j - 1)];
            } else {
                t[(i * s1) + j] = min(t[(i - 1) * s1 + j] + 1,
                    min(t[i * s1 + (j - 1)] + 1, t[(i - 1) * s1 + (j - 1)] + 1)); 
            }
        }
    }
    return t[s1*s2-1];
}



int main() {
    string str1 = "helo";
    string str2 = "hello";
    cout<<EditDistance(str1, str1.length(), str2, str2.length());
   return 0;
}
