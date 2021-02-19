#include<bits/stdc++.h>
using namespace std;

class ReversibleQueue {
    queue<int> q;
    public:
    void push(int value) {q.push(value);}
    void pop() {q.pop();}
    int front() {return q.front();}

    void reverse() {
        if(q.empty())
            return;
        int value = q.front();
        q.pop();
        reverse();
        q.push(value);
    }

    void print() {
        queue<int> qcopy = q;
        while(!qcopy.empty()) {
            cout<<qcopy.front()<<" ";
            qcopy.pop();
        }
    }
};

int main() {
    ReversibleQueue q;
    q.push(4);
    q.push(3);
    q.push(2);

    q.reverse();

    q.print();
    return 0;
}
