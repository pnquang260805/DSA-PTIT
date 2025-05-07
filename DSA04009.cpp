// DSA04009 - LŨY THỪA MA TRẬN 1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

const ll MOD = 1e9+7;

vv mul(vv a, vv b){
    ll n = a.size();
    ll m = a[0].size();
    ll p = b[0].size();
    vv c(n, vector<ll>(p));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < p; j++){
            c[i][j] = 0;
            for(ll k = 0; k < m; k++){
                c[i][j] = (c[i][j] % MOD + ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD;
            }
        }
    }
    return c;
}

vv power(vv a, ll n){
    if(n == 1)
        return a;
    vv half = power(a, n/2);
    vv full = mul(half, half);
    if(n % 2 != 0)
        full = mul(full, a);
    return full;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vv mat(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    vv ans = power(mat, k);
    for(auto x : ans){
        for(auto i : x){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
