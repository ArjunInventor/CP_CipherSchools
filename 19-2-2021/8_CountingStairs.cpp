#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;

int Fib(int n) { 
    if (n <= 1) 
        return n;
    if(!m[n])
        m[n] = Fib(n - 1) + Fib(n - 2);
    return m[n];
} 

int CountStairs(int s) { 
    return Fib(s + 1); 
} 

int main() {
    cout<<CountStairs(5);
    return 0;
}
