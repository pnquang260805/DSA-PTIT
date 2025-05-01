// DSA05011 - SỐ CÓ TỔNG CHỮ SỐ BẰNG K

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve(){
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    for(int i = 1; i <= (k < 9 ? k : 9); i++)
        dp[1][i] = 1;
    for(int i = 1; i <= n; i++){
        for(int l = 0; l <= 9; l++){
            for(int j = l; j <= k; j++){
                dp[i][j] = (dp[i][j] % MOD + dp[i-1][j-l] % MOD) % MOD;
            }
        }
    }
    cout << dp[n][k];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
