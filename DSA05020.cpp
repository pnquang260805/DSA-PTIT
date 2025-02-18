// ĐƯỜNG ĐI NHỎ NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix, dp;
    dp.assign(row+1, vector<int>(col+1, 0));
    for(int i = 0; i < row; i++){
        vector<int> temp;
        for(int j = 0; j < col; j++){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        matrix.push_back(temp);
    }
    dp[0][0] = matrix[0][0];
    for (int j = 1; j < col; j++){
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    for (int i = 1; i < row; i++){
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }


    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            int move_down = dp[i-1][j];
            int move_right = dp[i][j-1];
            int move_rd = dp[i-1][j-1];
            dp[i][j] = min(move_rd, min(move_down, move_right)) + matrix[i][j];
        }
    }
    cout << dp[row - 1][col - 1];

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}