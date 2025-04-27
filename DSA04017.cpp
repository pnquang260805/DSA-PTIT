// DSA04017 - PHẦN TỬ KHÁC NHAU

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;
    ll i = 0;
    while(i < n-1){
        if(a[i] == b[i]){
            i++;
        }
        else{
            cout << i+1;
            return;
        }
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
