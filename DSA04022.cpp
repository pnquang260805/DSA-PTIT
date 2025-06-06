// DSA04022 - KÝ TỰ THỨ K TRONG XÂU

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char calc(ll n, ll k){
    ll mid = (1LL << (n-1)); // !!!!!!!!
    if(k == mid)
        return 'A' + n - 1;
    else if(k < mid)
        return calc(n-1, k);
    else
        return calc(n-1, k-mid);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    char res = calc(n, k);
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
