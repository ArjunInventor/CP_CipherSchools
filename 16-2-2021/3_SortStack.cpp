#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int t) {
    if(s.empty() || t > s.top()) {
        s.push(t);
    } else {
        int p = s.top();
        s.pop();
        sortedInsert(s, t);
        s.push(p);
    }
}

void sortStack(stack<int> &s) {
    if(!s.empty()) {
        int t = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, t);
    }
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(4);

    sortStack(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
