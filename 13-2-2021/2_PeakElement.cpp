#include<bits/stdc++.h>
using namespace std;

int PeakElement(vector<int>& a) {
    int s = 0, e = a.size()-1;

    if(a.size() == 1) return a[0];
    if(a.size() == 2) return max(a[0], a[1]);

    while(s<=e) {
        int m = (s + (e - s)) / 2;
        if(a[m-1] < a[m] && a[m] > a[m+1]) return a[m];
        if(a[m] < a[m+1]) s = m + 1;
        else e = m-1;
    }
}

int main() {
    vector<int> a = {2, 4, 7, 1, 2};
    cout<<PeakElement(a);
    return 0;
}