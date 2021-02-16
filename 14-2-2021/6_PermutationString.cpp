#include<bits/stdc++.h>
using namespace std;

void GeneratePermutationString(vector<string> & result, int start, int end, string str) {
    if(start>=end) {
        result.push_back(str);
        return;
    }
    for(int i=start; i<=end; i++) {
        swap(str[i], str[start]);
        GeneratePermutationString(result, start+1, end, str);
        swap(str[i], str[start]);
    }
}

int main() {
    vector<string> result;
    string str = "abc";
    GeneratePermutationString(result, 0, str.size()-1, str);
    for(string p : result) {
        cout<<p<<endl;
    }
    return 0;
}