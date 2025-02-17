// DI CHUYỂN TRONG MÊ CUNG 1

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
string ans = "";
vector<int> X = {1, 0};
vector<int> Y = {0, 1};
bool found;

void init() {
    cin >> n;

    // Reset dữ liệu tránh chồng chéo giữa các test
    matrix.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    ans = "";
    found = false;

    // Nhập dữ liệu vào ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void BackTrack(int x, int y){
    if(x == n-1 && y == n-1){
        found = true;
        cout << ans << " ";
        return;
    }

    for(int i = 0; i < 2; i++){
        int nx = x + X[i], ny = y + Y[i];
        if (nx < n && ny < n && matrix[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            ans += (i == 0) ? "D" : "R";
            BackTrack(nx, ny);
            ans.pop_back();
            visited[nx][ny] = false;
        }
    }
}

void solve(){
    init();
    if(matrix[0][0] == 0 || matrix[n-1][n-1] == 0){
        cout << "-1";
        return;
    }
    visited[0][0] = true;
    BackTrack(0,0);
    if(!found)
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