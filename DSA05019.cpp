// DSA05019 - HÌNH VUÔNG LỚN NHẤT
// https://www.youtube.com/watch?v=6X7Ha2PrDmM

#include <bits/stdc++.h>
using namespace std;

int calc(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &mem){
    int row = mat.size();
    int col = mat[0].size();
    if(r >= row || c >= col)
        return 0;
    if(mem[r][c] != -1)
        return mem[r][c];
    mem[r][c] = 0;
    if(mat[r][c] == 1){
        int right = calc(r, c+1, mat, mem);
        int down = calc(r+1, c, mat, mem);
        int diag = calc(r+1, c+1, mat, mem);
        mem[r][c] = 1 + min(right, min(down, diag));
    }
    return mem[r][c];
}

void solve(){
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> mem(row, vector<int>(col, -1));
    int ans = INT_MIN;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ans = max(ans, calc(i, j, mat, mem));
        }
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
