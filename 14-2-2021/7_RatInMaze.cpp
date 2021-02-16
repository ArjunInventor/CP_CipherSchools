#include<bits/stdc++.h>
using namespace std;

int numDirections = 4;
pair<int, int> moves[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};


bool RatInMaze(vector<vector<int>> & grid, vector<vector<bool>> &visited, int x, int y) {
    int m=grid.size(), n=grid[0].size();
    if(x == m-1 && y == n-1) {
        visited[x][y] = true;
        return true;
    }

    if(x>=0 && x<m && y>=0 && y<n && visited[x][y] == false && grid[x][y] == 0) {
        visited[x][y] = true;
        for(int i=0; i<numDirections; i++) {
            if (RatInMaze(grid, visited, x+moves[i].first, y+moves[i].second)) {
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
    return false;
}

void printGrid(vector<vector<bool>> &grid) {
    for(int i = 0; i <grid.size(); i++) {
        for(int j = 0; j < grid.size(); j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    int m = 4, n = 4;
    vector<vector<int>> grid = {{0, 0, 1, 1},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 0}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    if(RatInMaze(grid, visited, 0, 0)) {
        printGrid(visited);
    }

    return 0;
}