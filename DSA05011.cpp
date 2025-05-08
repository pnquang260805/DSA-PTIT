// DSA05011 - SỐ CÓ TỔNG CHỮ SỐ BẰNG K

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;
const ll MOD = 1e9+7;

ll sum_mod(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll calc(ll n, ll k, vv &mem){
    if(n == 0){
        return (k == 0 ? 1 : 0);
    }
    if(mem[n][k] != -1)
        return mem[n][k];
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        if(k - i >= 0){
            ans = sum_mod(ans, calc(n-1, k-i, mem));
        }
    }
    mem[n][k] = ans;
    return ans;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vv mem(n+1, vector<ll>(k+1, -1)); // [pos][remain]
    ll res = 0;
    for(int i = 1; i <= 9; i++){ // handle first digit
        if(k >= i){
            res = sum_mod(res, calc(n-1, k-i, mem));
        }
    }
    cout << res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
