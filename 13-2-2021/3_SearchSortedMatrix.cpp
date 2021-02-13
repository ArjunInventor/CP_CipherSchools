#include<bits/stdc++.h>
using namespace std;

pair<int, int> SearchSortedMatrix(vector<vector<int>> m, int e) {
    int i=0, j=m.size()-1;

    while(j>=0 && i<m.size()) {
        if(m[i][j] == e) {
            return pair<int, int>(i, j);
        } else if (m[i][j] > e) {
            j = j-1;
        } else {
            i = i+1;
        }
    }
}

int main() {
    vector<vector<int>> m = {
        {3, 12, 14},
        {7, 15, 18},
        {20, 19, 22}
    };
    int e = 15;
    pair<int, int> r = SearchSortedMatrix(m, e);
    cout<<r.first<< " " << r.second;
    return 0;
}