#include<bits/stdc++.h>
using namespace std;

string minWindow(string &str1, string &str2) {
    if (str1.empty() || str1.length() < str2.length()) {
        return "";
    }

    int cnt = 0, start = 0;
    int l = 0;
    int w = INT_MAX;

    vector<int> h1(256, 0);
    vector<int> h2(256, 0);

    for(int i = 0; i < str2.size(); i++) {
        h1[str2[i]]++;
    }

    for (int i = 0; i < str1.length(); ++i) {
        if (h1[str1[i]] > 0) {
            h2[str1[i]]++;
            if (h2[str1[i]] <= h1[str1[i]]) ++cnt;
        }
        if (cnt == str2.size()) {
            while (h1[str1[start]] == 0 || h2[str1[start]] > h1[str1[start]]) {
                h2[str1[start++]]--;
            }

            if (w>i-start+1) { 
                w=i-start+1;
                l=start;
            }
        }
    }

    if (w == INT_MAX) {
        return "";
    }

    return str1.substr(l, w);
}

int main() {

    string str1 = "asahfglb";
    string str2 = "sgfh";
    cout<<minWindow(str1, str2);
    return 0;
}