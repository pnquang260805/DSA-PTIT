// DSA03027 - GIÁ TRỊ LỚN NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x > 0){
            ans += x * 2;
        }
    }
    cout << ans;
}