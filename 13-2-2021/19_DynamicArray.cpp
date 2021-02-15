#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
    int capacity, size;
    int *arr;
    public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        free(arr);
    }

    void resize() {
        capacity *= 2;
        int *temp = new int[capacity];
        for(int i = 0; i < capacity/2;i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        cout<<"new capacity: "<<capacity<<endl;
    }

    void push(int item) {
        if(size == capacity) {
            resize();
        }
        arr[size++] = item;
    }

    int pop() {
        return arr[size--];
    }

    void replace(int item, int index) {
        arr[index] = item;
    }

    int get(int index) {
        return arr[index];
    }
};


int main() {
    DynamicArray d = DynamicArray();
    for(int i=0; i<16; i++)
        d.push(i);

    return 0;
}