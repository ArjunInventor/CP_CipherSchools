#include<bits/stdc++.h>
using namespace std;
 
int TrailingZeros(int n, int i=5) {
    if(n/i < 1) return 0;
    return + n/i + TrailingZeros(n, i*i);
}
 
int main()
{
    cout<<TrailingZeros(100)<<endl;
    return 0;
}