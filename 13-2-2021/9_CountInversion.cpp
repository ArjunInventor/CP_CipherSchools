#include<bits/stdc++.h>
using namespace std;
 
int Merge(vector<int> arr, vector<int> temp, int left, int mid, int right) {
    int ic=0, i=left, j=mid, k=right;
    while ((i < mid) && (j < right+1)) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
             ic += (mid - i);
        }
        k++;
    }
    while (i <= mid-1) {
        temp[k++] = arr[i++];
    }
 
    while (j <= right) {
        temp[k++] = arr[j++];
    }
 
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return ic;
}

int MergeSort(vector<int> arr, vector<int> temp, int left, int right) {
    int ic = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        ic += MergeSort(arr, temp, left, mid) + 
                    MergeSort(arr, temp, mid + 1, right) +
                    Merge(arr, temp, left, mid + 1, right);
    }
    return ic;
}

int main()
{
    vector<int> arr = {4, 1, 6, 20, 100, 2};
    vector<int> temp(arr.size());
    cout<<MergeSort(arr, temp, 0, arr.size()-1)<<endl;
    return 0;
}