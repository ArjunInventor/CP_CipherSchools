#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int> & a, int i, int n) {
    int largest, loc, 
        l = 2 * i, r = (2 * i + 1);
    if ((l <= n) && a[l] > a[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if ((r <= n) && (a[r] > a[largest])) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, largest, n);
    }
}
void BuildHeap(vector<int> &a, int n) {
    for (int k = n / 2; k >= 1; k--) {
        Heapify(a, k, n);
    }
}
void Heapsort(vector<int> &a, int n) {

    BuildHeap(a, n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        Heapify(a, 1, i - 1);
    }
}

int main()
{
    int n;
    vector<int> arr = {1, 5, 2, 7, 3, 10};
    Heapsort(arr, arr.size());
    for (auto a : arr)
    {
        cout << a << " ";
    }
}
