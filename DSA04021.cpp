// DSA04021 - DÃY XÂU NHỊ PHÂN

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll LIMIT = 94;

vector<ll> len(LIMIT);

void precalc(){
    len[1] = 1;
    len[2] = 1;
    for(ll i = 3; i < LIMIT; i++){
        len[i] = len[i-2] + len[i-1];
    }
}

char findNum(ll n, ll k){
    if(n == 1)
        return '0';
    if(n == 2)
        return '1';
    if(k <= len[n-2])
        return findNum(n-2, k);
    else
        return findNum(n-1, k - len[n-2]);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    cout << findNum(n, k);
}

int main(){
    precalc();

    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
