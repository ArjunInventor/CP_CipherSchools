#include <bits/stdc++.h>
using namespace std;

int Evaluate(vector<char> &inputs)
{
    stack<int> s;
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] < '0' || inputs[i] > '9') {
            int v1 = s.top();
            s.pop();
            int v2 = s.top();
            s.pop();
            switch(inputs[i]) {
                case '+': 
                    s.push(v2 + v1);
                    break;
                case '-':
                    s.push(v2 - v1);
                    break;
                case '/':
                    s.push(v2 / v1);
                    break;
                case '*':
                    s.push(v2 * v1);
                    break;
                case '^':
                    s.push(pow(v2, v1));
                    break;
                default:
                    cout<<"Invalid operation";
                    return 0;
            }
        }
        else
            s.push(inputs[i] - '0');
    }
    return s.top();
}
int main()
{
    vector<char> s = {'2', '1', '+'};
    cout<<Evaluate(s);
}
