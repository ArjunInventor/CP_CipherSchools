#include<bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    int minE = INT_MIN;
    public:
    push(int value) {
        if(s.size() == 0) {
            s.push(value);
            minE = value;
        } else {
            if(value >= minE) {
                s.push(value);
            } else {
                s.push((2*value) - minE);
                minE = value;
            }
        }
    }

    int pop() {
        if(s.empty()) {
            cout<<"Stack empty";
            return 0;
        }
        int value = s.top();
        s.pop();
        if(value < minE) {
            int t = minE;
            minE = (2*minE)-value;
            return t;
        }
        return value;
    }

    int getMin() {
        return minE;
    }
};

int main() {
    SpecialStack s;
    s.push(2);
    s.push(4);
    s.push(1);
    s.push(3);

    for(int i = 0; i<4; i++) {
        cout<<"Min: "<<s.getMin()<<endl;
        cout<<s.pop()<<endl;
    }
}
