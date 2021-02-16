#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, int i, int j) {
    for(int a = 0; a < j; a++) {
        if(grid[i][a]) return false;
    }
    for(int a=i, b=j; a>=0 && b>=0; a--, b--) {
        if(grid[a][b] == 1) return false;
    }
    for(int a=i, b=j; a<grid.size() && b>=0; a++, b--) {
        if(grid[a][b] == 1) return false;
    }
    return true;
}

bool NQueen(vector<vector<int>> &grid, int i, int j, int index = 0) {
    if(index == grid.size()) {
        return true;
    }

    for(int a = 0; a < grid.size(); a++) {
        if(isValid(grid, a, index)) {
            grid[a][index] = 1;
            if(NQueen(grid, a, index, index+1)) {
                return true;
            } 
            grid[a][index] = 0;
        }
    }
    return false;
}

void printGrid(vector<vector<int>> &grid) {
    for(int i = 0; i <grid.size(); i++) {
        for(int j = 0; j < grid.size(); j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int m = 4;
    vector<vector<int>> grid(m, vector<int>(m, 0));
    if(NQueen(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout<<"Solution not found";
    }
    return 0;
}
