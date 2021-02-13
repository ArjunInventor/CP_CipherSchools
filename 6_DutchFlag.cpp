#include<bits/stdc++.h>

using namespace std;

void DutchFlag(vector<int>& d) {
   int p0 = 0, p1 = 0, p2 = d.size()-1;

   while(p1<=p2) {
        if(d[p1] == 0) {
            swap(d[p0], d[p1]);
            p0++;
            p1++;
       } else if(d[p1] == 1) {
            p1++;
       } else {
            swap(d[p2], d[p1]);
            p2--;
       }
   }
}

int main() {
    vector<int> d = {2, 1, 2, 1, 0, 0, 1, 0, 2, 1};

    DutchFlag(d);

    for(auto i: d) {
        cout<<i<<" ";
    }

    return 0;
}