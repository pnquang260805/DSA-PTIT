// DSA04024 - LŨY THỪA MA TRẬN 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

typedef vector<vector<ll>> vv;

ll sumMod(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mulMod(ll a, ll b){
    return (a % MOD * b % MOD) % MOD;
}

vv mulMat(vv a, vv b){
    ll n = a.size();
    ll m = b.size();
    ll p = b[0].size();
    vv c(n, vector<ll>(p, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < p; j++){
            for(ll k = 0; k < m; k++){
                c[i][j] = sumMod(c[i][j], mulMod(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}


vv powMat(vv a, ll k){
    if(k == 0){
        vv m(a.size(), vector<ll>(a.size(), 0));
        for(ll i = 0; i < (ll)a.size(); i++){
            m[i][i] = 1;
        }
        return m;
    }
    vv half = powMat(a, k/2);
    vv full = mulMat(half, half);
    if(k % 2 == 1){
        full = mulMat(full, a);
    }
    return full;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vv mat(n, vector<ll>(n));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> mat[i][j];
    vv res = powMat(mat, k);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans = sumMod(ans, res[i][n-1]);
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