// DSA07030 - HÌNH CHỮ NHẬT 0-1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<int>> vv;

void solve(){
    int m, n;
    cin >> m >> n;
    vv grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    vv dp(m, vector<int>(n, 0)); // hàng thứ i, cột j có chiều rộng là dp[i][j]
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                continue;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 1 + dp[i][j-1];
            }
            int w = dp[i][j];
            for(int k = i; k >= 0; k--){
                w = min(w, dp[k][j]);
                int area = w*(i-k+1); // i-k+1 = heigh
                ans = max(ans, area);
            }
        }
    }
    cout << ans;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}