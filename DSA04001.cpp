// Lũy thừa

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9+7;

ll calc(ll n, ll k){
    int res = 1;
    n %= MOD;
    while(k > 0){
        if(k % 2 != 0){
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    cout << calc(n, k) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
