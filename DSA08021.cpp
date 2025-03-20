// DSA08021 - DI CHUYỂN TRONG MA TRẬN

#include <bits/stdc++.h>
using namespace std;

int calc(int x, int y, int &m, int &n, vector<vector<int>> &matrix, vector<vector<int>> &mem){
    if(x > m || y > n)
        return INT_MAX;
    if(x == m && y == n)
        return 0;
    if(mem[x][y] != -1)
        return mem[x][y];

    int move_x = calc(x + matrix[x][y], y, m, n, matrix, mem);
    int move_y = calc(x, y + matrix[x][y], m, n, matrix, mem);
    if(move_x != INT_MAX)
        move_x += 1;
    if(move_y != INT_MAX)
        move_y += 1;
    mem[x][y] = min(move_x, move_y);
    return mem[x][y];
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m+1, vector<int>(n+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> mem(m+1, vector<int>(n+1, -1));
    int res = calc(1, 1, m, n, matrix, mem);
    cout << (res != INT_MAX ? res : -1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }   
}