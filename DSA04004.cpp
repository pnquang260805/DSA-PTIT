// DSA04004 - GẤP ĐÔI DÃY SỐ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int calc(ll n, ll k){
    ll mid = (1LL << (n-1));
    if(k == mid)
        return n;
    else if(k < mid)
        return calc(n-1, k);
    else
        return calc(n-1, k-mid);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    cout << calc(n, k);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
