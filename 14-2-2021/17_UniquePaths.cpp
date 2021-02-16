#include<bits/stdc++.h>
using namespace std;

int CountUniquePathsWithoutObstacles(vector<vector<int>> grid) {
    int m=grid.size(), n=grid[0].size();
    for(int i=0; i<m; i++) {
        grid[i][0] = 1;
    }
    for(int j=0; j<n; j++) {
        grid[0][j] = 1;
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}

//with obstacles
int CountUniquePathsWithObstacles(vector<vector<int>> grid) {
    int m=grid.size(), n=grid[0].size();

    for(int i=0; i<m; i++) {
        if(grid[i][0] == -1) break;
        grid[i][0] = 1;
    }
    for(int j=0; j<n; j++) {
        if(grid[0][j] == -1) break;
        grid[0][j] = 1;
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(grid[i][j] == -1) break;
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}

int main() {
    int m = 4, n = 4, res;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    // grid[0][2] = -1;
    res = CountUniquePathsWithoutObstacles(grid);
    cout<<res;
    return 0;
}