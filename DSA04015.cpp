// DSA04015 - TÍNH FLOOR(X)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = -1;
    ll pos = -1;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x <= k){
            ans = max(ans, x);
            pos = i+1;
        }
    }
    cout << pos;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
