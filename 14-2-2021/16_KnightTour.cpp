#include<bits/stdc++.h>
using namespace std;

pair<int, int> steps[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int numSteps = sizeof(steps)/sizeof(steps[0]);

bool isValidMove(vector<vector<int>> &grid, int i, int j) {
    if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0) {
        return false;
    }
    if(grid[i][j] != -1) {
        return false;
    }
    return true;
}

bool KnightTour(vector<vector<int>> &grid, int i, int j, int moves = 1) {
    if(moves == (grid.size() * grid[0].size())-1) {
        return true;
    }

    for(int a = 0; a < numSteps; a++) {
        int _i = i + steps[a].first;
        int _j = j + steps[a].second;
        if(isValidMove(grid, _i, _j)) {
            grid[_i][_j] = moves;
            if(KnightTour(grid, _i, _j, moves+1)) {
                return true;
            } else {
                grid[_i][_j] = -1;
            }
        }
    }
    return false;
}

void printGrid(vector<vector<int>> &grid) {
    system("cls");
    for(int i = 0; i <grid.size(); i++) {
        for(int j = 0; j < grid.size(); j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int m = 8;
    vector<vector<int>> grid(m, vector<int>(m, -1));
    grid[0][0] = 0;
    if(KnightTour(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout<<"Solution not found";
    }
    return 0;
}
