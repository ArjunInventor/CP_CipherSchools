
#include <bits/stdc++.h>
using namespace std;
 
int MissingNumber(vector<int> a) {
    int n = a.size()+1;
    return ((n*(n+1))/2) - accumulate(a.begin(), a.end(), 0);
}
 
int main()
{
    vector<int> a = { 1, 6, 2, 4, 3 };
    cout << MissingNumber(a);
}