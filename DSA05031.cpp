// DSA05031 - TỔNG BÌNH PHƯƠNG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

void solve(){
    ll n;
    cin >> n;
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 1; j <= sqrt(i); j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
