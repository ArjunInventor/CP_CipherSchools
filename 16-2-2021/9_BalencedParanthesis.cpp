#include <bits/stdc++.h>
using namespace std;

bool isMatching(char c1, char c2) {
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '{' && c2 == '}') return true;
    if(c1 == '[' && c2 == ']') return true;
    return false;
}

bool isOpen(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool Balenced(string expr) {
    stack<char> s;
    int n = expr.size();
    for (int i = 0; i < n; i++) {
        if (isOpen(expr[i])) {
            s.push(expr[i]);
        } else {
            if (s.empty())
                return false;

            char c1 = s.top(); 
            s.pop();
            if (!isMatching(c1, expr[i]))
                return false;
        }
    }
    return s.empty();
}

int main() {
    cout<<"(())"<<" - "<<(Balenced("(())")?"TRUE":"FALSE")<<endl;
    cout<<"(()()))"<<" - "<<(Balenced("(()()))")?"TRUE":"FALSE")<<endl;
    return 0;
}
