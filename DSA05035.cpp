// DSA05035 - CHỮ SỐ SẮP XẾP TĂNG DẦN
// https://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;
ll mod_sum(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(10, 0));
    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                // Mỗi trạng thái con cần được duyệt theo một tập điều kiện (k nào đó).
                // Ví dụ muốn đếm tổng số lượng số hạn <= số 20 --> dp[2][0] = dp[2][0]+dp[1][0]+...+dp[1][9]
                dp[i][j] = mod_sum(dp[i][j], dp[i-1][k]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++)
        ans = mod_sum(ans, dp[n][i]);
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
