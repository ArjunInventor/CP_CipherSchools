#include <bits/stdc++.h>
using namespace std;
 
void getMax(queue<int> q, vector<int> &res) {
    int m = 0;
    while (!q.empty()) {
        if (q.front() > m) {
            m = q.front();
        }
        q.pop();
    }
    res.push_back(m);
    return;
}
 
void SlidingWindowMax(vector<int> arr, int k, vector<int> &res) {
    queue<int> q;
    for (int i = 0; i < arr.size(); i++) {
        if (i < k) {
            q.push(arr[i]);
        } else {
            getMax(q, res);
            q.pop();
            q.push(arr[i]);
        }
    }
    getMax(q, res);
    return;
}
 
int main()
{
    vector<int> arr = {1, 2, 3, 2, 5, 3, 7, 2};
    int k = 3;
    vector<int> res;
    SlidingWindowMax(arr, k, res);

    for(auto r : res) {
        cout<< r << " ";
    }
    return 0;
}
