#include<bits/stdc++.h>
using namespace std;

void MergeOverlapping(vector<pair<int, int>> &time) {
    sort(time.begin(), time.end());
    stack<int> s;
    s.push(time[0].first);
    s.push(time[0].second);
    for(int i=1; i<time.size(); i++) {
        if(time[i].first <= s.top()) {
            s.pop();
            s.push(time[i].second);
        } else {
            s.push(time[i].first);
            s.push(time[i].second);
        }
    }
    time.clear();
    while(!s.empty()) {
        int d = s.top(); s.pop();
        int a = s.top(); s.pop();
        pair<int, int> p; p.first = a; p.second = d;
        time.push_back(p);
    }
}

int main() {
    vector<pair<int, int>> time = {{1,3}, {3,4}, {5,7}, {6,8}};
    for(auto p : time) {
        cout<< p.first << " " << p.second<< endl;
    }
    MergeOverlapping(time);
    cout<<"New timimgs: "<<endl;
    for(auto p : time) {
        cout<< p.first << " " << p.second<< endl;
    }
    return 0;
}
