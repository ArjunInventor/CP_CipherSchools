#include <bits/stdc++.h>
#include<iostream>

using namespace std;

vector<int> mergeSortedArrays(const vector<int>& first, const vector<int>& second) {
    int i=0, j=0, k=0;
    vector<int> result(first.size() + second.size());

    while(i<first.size() && j < second.size()) {
        if (first[i] <= second[j]) {
            result[k] = first[i];
            i++;
        } else {
            result[k] = second[j];
            j++;
        }
        k++;
    }

    while(i< first.size()) {
        result[i] = first[i];
        i++; k++;
    }

    while(j<second.size()) {
        result[j] = second[j];
        j++; k++;
    }

    return result;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 12, 19};
    vector<int> b = {1, 3, 4, 6, 77, 91};

    vector<int> c = mergeSortedArrays(a, b);

    for(int i=0; i<c.size(); i++) {
        cout<<c[i]<<" ";
    }

    return 0;
}