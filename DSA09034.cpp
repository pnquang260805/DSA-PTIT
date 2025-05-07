// DSA09034 - ĐẾM SỐ AO

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;

vector<int> d_col = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> d_row = {-1, -1, -1, 0, 0, 1, 1, 1}; //
vector<vector<bool>> visited;

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 8; i++){
        int new_col = y + d_col[i];
        int new_row = x + d_row[i];
        if(new_col >= 0 && new_col < m && new_row >= 0 && new_row < n && !visited[new_row][new_col] && grid[new_row][new_col] == 'W'){
            dfs(new_row, new_col);
        }
    }
}

int main(){
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 'W'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}
