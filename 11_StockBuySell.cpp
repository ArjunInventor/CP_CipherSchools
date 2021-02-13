#include <bits/stdc++.h>
using namespace std;
 
int BuySell(vector<int> p)
{
    int n = p.size();
    int profit = 0, max_profit = 0;
    int m = p[0];
    for(int i = 0; i < n; i++) {  
        m = min(m, p[i]);
        profit = p[i] - m;
        max_profit = max(max_profit, profit);
    }
    return max_profit;
}
 
int main()
{
   
    vector<int> p = {1000, 1400, 900, 800, 1500};
     
    cout << BuySell(p);
 
    return 0;
}
 