#include<bits/stdc++.h>
using namespace std;

int ExcelSheetColumnHelper(string & title, int i) {
    if(i==title.size()) return 0;
    return (((int)title[title.size()-1-i] - 64) * pow(26,i)) + ExcelSheetColumnHelper(title, i+1);
}

int ExcelSheetColumn(string title) {
    return ExcelSheetColumnHelper(title, 0);
}

int main() {
    cout<<ExcelSheetColumn("AA") << endl;
    cout<<ExcelSheetColumn("CD") << endl;
    return 0;
}
