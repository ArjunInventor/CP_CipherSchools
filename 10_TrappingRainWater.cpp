#include<bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> vec) {
    vector<int> lmax(vec.size());
    vector<int> rmax(vec.size());
    lmax[0] = vec[0];
    int _lmax = vec[0];
    for(int i=1; i<vec.size(); i++) {
        if(vec[i] > _lmax) {
            _lmax = vec[i];
        }
        lmax[i] = _lmax;
    }
    rmax[vec.size()-1] = vec[vec.size()-1];
    int _rmax = vec[vec.size()-1];
    for(int i=vec.size()-2; i>=0; i--) {
        if(vec[i] > _rmax) {
            _rmax = vec[i];
        }
        rmax[i] = _rmax;
    }
    int countWater = 0;
    for(int i=0; i<vec.size(); i++) {
        countWater += max(min(lmax[i], rmax[i]) - vec[i], 0);
    }
    return countWater;
}

int main() {
    vector<int> vec = {5, 1, 6, 1, 3};
    int d = trappingRainWater(vec);
    cout<<d;
    return 0;
}