/* Di chuyển trong mê cung
1
4
1 0 0 0
1 1 0 1
0 1 0 0
0 1 1 1
*/

#include <bits/stdc++.h>
using namespace std;

bool found = true;
// L, U, D, R
vector<int> x_direct = {0, 0, -1, 1}; // L, R, U, D
vector<int> y_direct = {-1, 1, 0, 0};
vector<char> dir = {'L', 'R', 'U', 'D'};

string res = "";

void Try(int x, int y ,vector<vector<int>> &grid, string &s, vector<vector<bool>> &visited){
    int n = grid.size();
    if(x == 0 && y == 0 && grid[x][y] == 0){
        found = false;
        return;
    }
    if(x == n-1 && y == n-1){
        res = s;
        found = true;
        return;
    }
    for(int i = 0; i < x_direct.size(); i++){
        int new_x = x + x_direct[i];
        int new_y = y + y_direct[i];

        if(new_x >= 0 && new_x < n &&
           new_y >= 0 && new_y < n &&
           grid[new_x][new_y] == 1 &&
           !visited[new_x][new_y]){
                s += dir[i];
                visited[new_x][new_y] = true;
                Try(new_x, new_y, grid, s, visited);
                s.pop_back();
                visited[new_x][new_y] = false;
        }
    }

}

void solve(){
    int n;
    cin >> n;
    string s = "";
    res = "";
    found = true;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    visited[0][0] = true;
    Try(0, 0, grid, s, visited);
    if(found)
        cout << res;
    else
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
