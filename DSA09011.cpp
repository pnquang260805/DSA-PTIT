// DSA09011 - SỐ LƯỢNG HÒN ĐẢO

#include <bits/stdc++.h>
using namespace std;

vector<int> x_direct = {-1,0,1,-1,1,-1,0,1};
vector<int> y_direct = {-1,-1,-1,0,0,1,1,1};

void bfs(int r, int c, vector<vector<int>> &grid, set<pair<int,int>> &visited){
    int max_row = grid.size();
    int max_col = grid[0].size();
    queue<pair<int,int>> q;
    q.push({r, c});
    visited.insert({r, c});
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        int row = top.first;
        int col = top.second;
        for(int i = 0; i < x_direct.size(); i++){
            int new_row = row + y_direct[i];
            int new_col = col + x_direct[i];

            if(new_row < max_row
               && new_col < max_col
               && new_row >= 0 && new_col >= 0
               && grid[new_row][new_col] == 1
               && visited.find({new_row, new_col}) == visited.end()){
                    visited.insert({new_row, new_col});
                    q.push({new_row, new_col});
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    set<pair<int,int>> visited;
    int islands = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 && visited.find({i, j}) == visited.end()){
                islands++;
                bfs(i, j, grid, visited);
            }
        }
    }
    cout << islands;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
