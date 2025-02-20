// DI CHUYỂN TRONG MÊ CUNG 2 - 2004

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<int> X = {1, 0, 0, -1};  // D, R, L, U tăng chỉ số hàng là x
vector<int> Y = {0, 1, -1, 0};
vector<char> moving = {'D', 'R', 'L', 'U'};
vector<string> ans;
string process;

void init(){
    process = "";
    matrix.clear();
    visited.clear();
    ans.clear();
    cin >> n;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    visited.assign(n, vector<bool>(n, false));
}

void BackTrack(int x, int y){
    if(x == n-1 && y == n-1){
        ans.push_back(process);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + X[i], ny = y + Y[i];
        if(nx < n && ny < n && nx >= 0 && ny >= 0 && matrix[nx][ny] == 1 && !visited[nx][ny]){
            visited[nx][ny] = true;
            process += moving[i];
            BackTrack(nx, ny);
            process.pop_back();
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
    BackTrack(0, 0);
    if(ans.size() == 0)
        cout << -1;
    else{
        sort(ans.begin(), ans.end());
        for(string s : ans)
            cout << s << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}