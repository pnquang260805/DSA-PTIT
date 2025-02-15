// TÍNH P(N,K)

#include <bits/stdc++.h>
using namespace std;

// P(n,k) = P(n-1, k) + k * P(n-1, k-1)

using ll = long long;
const ll MOD = 1e9+7;

int calcP(ll n, ll k, vector<vector<ll>> &mem){
    if(n < k)
        return 0;

    if(k == 0)
        return 1;

    if(mem[n][k] != -1)
        return mem[n][k];

    mem[n][k] = ((calcP(n-1, k, mem) % MOD) + ((k % MOD) * (calcP(n-1, k-1, mem) % MOD)) % MOD) % MOD;
    return mem[n][k];
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> mem;
    mem.assign(n+1, vector<ll>(k+1, -1));
    cout << calcP(n, k, mem);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}