#include<bits/stdc++.h>
using namespace std;

int first(vector<int> arr, int e) {
    int l = 0, h = arr.size()-1;
    while(h >= l) {
        int m = l + (h - l) / 2;
        if (arr[m] == e && (m == 0 || e > arr[m - 1])) return m;
        else if (e > arr[m]) l = m+1;
        else h = m-1;
    }
    return -1;
}

int last(vector<int> arr, int e) {
    int l = 0, h = arr.size()-1;
    while (h >= l) {
        int m = l + (h - l) / 2;
        if (arr[m] == e && (m == arr.size() - 1 || e < arr[m + 1])) return m;
        else if (e < arr[m]) h = m-1;
        else l = m+1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 4, 4, 4, 5, 8};
    int e = 4;
    cout << "First: " << first(arr, e) << endl;
    cout << "Last: " << last(arr, e);

    return  0;
}