#include<bits/stdc++.h>

using namespace std;

void SegregateZeroOnes(vector<int>& d) {
   int p0 = 0, p1 = d.size()-1;

   while(p0<p1) {
        while(d[p0]==0) p0++;
        while(d[p1]==1) p1--;
        if(p0<p1) swap(d[p0], d[p1]);
   }
}

int main() {
    vector<int> d = {0, 1, 0, 1, 0, 0, 1, 0, 1, 1};

    SegregateZeroOnes(d);

    for(auto i: d) {
        cout<<i<<" ";
    }

    return 0;
}