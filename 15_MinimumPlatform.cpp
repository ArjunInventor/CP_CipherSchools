#include<bits/stdc++.h>
using namespace std;

int MinimumPlatform(vector<int> a, vector<int> d)
    {
        sort(a.begin(), a.begin());
        sort(d.begin(), d.begin());
 
        int min_p = 1, res = 1, i = 1, j = 0;
 
        while (i < a.size() && j < d.size()) {
            if (a[i] <= d[j]) {
                min_p++; i++;
            } else if (a[i] > d[j]) {
                min_p--; j++;
            }
            res = max(min_p, res);
        }
        return res;
    }
 

int main() {
    vector<int> a = { 1000, 1100, 1410 };
    vector<int> d = { 1300, 1400, 1500 };

    cout<< MinimumPlatform(a, d);
    return 0;
}