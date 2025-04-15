// DSA_P011 - ĐẾM SỐ VẬT CẢN TRÊN MÊ CUNG

#include <bits/stdc++.h>
using namespace std;

vector<int> x_direct = {-1, 0, 0, 1};
vector<int> y_direct = {0, -1, 1, 0};

void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited){
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int max_col = grid[0].size();
    int max_row = grid.size();

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        int row = top.first;
        int col = top.second;
        for(int i = 0; i < x_direct.size(); i++){
            int new_row = row + y_direct[i];
            int new_col = col + x_direct[i];

            if(new_row >= 0 && new_row < max_row &&
               new_col >= 0 && new_col < max_col &&
               grid[new_row][new_col] == '#' &&
               !visited[new_row][new_col]){
                    q.push({new_row, new_col});
                    visited[new_row][new_col] = true;
               }
        }
    }
}

int main(){
    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row, vector<char>(col));
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int islands = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == '#' && !visited[i][j]){
                islands++;
                bfs(i, j, grid, visited);
            }
        }
    }
    cout << islands;
}
