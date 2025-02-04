// Bậc thang

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9+7;

void solve(){
    ll stairs, steps;
    cin >> stairs >> steps;
    vector<ll> dp(stairs + 1);
    dp[0] = dp[1] = 1;
    for(ll stair = 2; stair <= stairs; stair++){
        for(ll step = 1; step <= min(stair,steps); step++){\
            dp[stair] += dp[stair - step];
            dp[stair] %= mod;
        }
    }
    cout << dp[stairs] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
