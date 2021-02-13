#include<bits/stdc++.h>
using namespace std;

void PrintMatrixInSpiral(vector<vector<int>> matrix) {
    int row_start=0, column_start=0;
    int row_end=matrix.size() - 1, column_end=matrix[0].size() - 1;

    while(row_start <= row_end && column_start <= column_end) {
        for(int i=column_start; i<=column_end; i++) {
            cout << matrix[row_start][i];
        }
        row_start++;

        for(int i=row_start; i<=row_end; i++) {
            cout << matrix[i][column_end];
        }
        column_end--;

        if(row_start<row_end) {
            for(int i=column_end; i>=column_start; i--) {
                cout << matrix[row_end][i];
            }
            row_end--;
        }

        if(column_start < column_end) {
            for(int i=row_end; i>=row_start; i--) {
                cout << matrix[i][column_start];
            }
            column_start++;
        }
    }
}

int main() {

    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    PrintMatrixInSpiral(m);
    return 0;
}