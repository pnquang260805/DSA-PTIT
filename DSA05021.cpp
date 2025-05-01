// DSA05021 - CẶP SỐ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<ll, ll> p;

void solve(){
    int n;
    cin >> n;
    vector<p> a(n);
    for(p &x : a){
        cin >> x.first >> x.second;
    }
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    sort(a.begin(), a.end(), [](p a, p b){
        return a.second < b.second;
    });
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        int skip = dp[i-1];
        int pick = 0;
        for(int j = 0; j < i; j++){
            if(a[j].second < a[i].first){
                pick = dp[j] + 1;
            }
        }
        dp[i] = max(pick, skip);
    }
    cout << dp[n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
