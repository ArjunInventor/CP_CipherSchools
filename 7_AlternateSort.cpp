#include<bits/stdc++.h>
using namespace std;

void AlternativeSort(vector<int> & a) {
    sort(a.begin(), a.end());
    for(int i=0; i<a.size()/2; i++) {
        cout<<a[a.size()-1-i]<<" ";
        cout<<a[i]<<" ";
    }
}

int main() {
    vector<int> a = {5, 2, 1, 6, 3, 4};
    AlternativeSort(a);
    return 0;
}