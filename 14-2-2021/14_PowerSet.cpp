#include<bits/stdc++.h>
using namespace std;

void powerSet(vector<int> & set, vector<int> selected, int i, vector<vector<int>> & result) {
    if(i == set.size()) {
        result.push_back(selected);
        return;
    }

    powerSet(set, selected, i+1, result);

    selected.push_back(set[i]);
    powerSet(set, selected, i+1, result);
}

int main() {
    vector<int> set = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> temp = {};
    powerSet(set, temp, 0, result);
    for(vector<int> i: result) {
        cout<<"{";
        for(int j: i)
            cout<<j<<" ";
        cout<<"}"<<endl;
    }

    return 0;
}