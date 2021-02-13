#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int binarySearch(vector<int> vec, int start, int end, int x) {

}

int findPivot(vector<int> vec) {
    int start = 0, end = vec.size()-1;
    int mid = (start + (end - start)) / 2
    while(true) {
        if(mid < end && vec[mid] > vec[mid + 1]) {
            return mid;
        }

        if(start < mid && vec[mid - 1] > vec[mid]) {
            return mid - 1;
        }
    }
}

int searchInSortedRotated (vector<int> vec, int x) {
    int i = 0, j=vec.size() - 1;
    int pivotElement = findPivot(vec, i, j);

    int res1 = binarySearch(vec, i, pivotElement, x);
    int res2 = binarySearch(vec, pivotElement + 1, j, x);

    if(res1 < 0) {
        return res2;
    } else {
        return res1;
    }
}

int main() {

    return 0;
}