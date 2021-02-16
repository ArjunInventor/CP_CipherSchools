#include<bits/stdc++.h>
using namespace std;

void ExcelSheetTitleHelper(vector<char> & res, int n) {
    if(n == 0) return;
    res.push_back((char) ((n - 1) % 26) + 65);
    ExcelSheetTitleHelper(res, (n-1)/26);
}

void ExcelSheetTitle(int n) {
    vector<char> res = {};
    ExcelSheetTitleHelper(res, n);
    for(int i = 0; i <res.size(); i++) {
        cout<<res[res.size()-1-i];
    }
    cout<<" ";
}

int main() {
    for(int i=1; i<100; i++) {
        ExcelSheetTitle(i);
    }
    return 0;
}
