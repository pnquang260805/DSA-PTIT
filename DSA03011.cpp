// DSA03011 - NỐI DÂY 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

ll sumMod(ll a, ll b){
    return (a + b) % MOD;
}

void solve(){
    ll n;
    cin >> n;
    if(n == 1){
        int x;
        cin >> x;
        cout << x;
        return;
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;

    while(q.size() > 1){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        int summ = sumMod(x, y);
        ans = sumMod(ans, summ);
        q.push(summ);
    }
//    ans = sumMod(ans, q.top());
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
