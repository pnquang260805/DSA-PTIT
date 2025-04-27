// DSA03017 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,ll> mp;
    for(char x : s)
        mp[x]++;
    priority_queue<ll> q;
    for(int i = 0; i < mp.size(); i++)
        q.push(mp[i]);
    while(n-- && !q.empty()){
        ll biggest = q.top();
        q.pop();
        biggest-=1;
        q.push(biggest);
    }
    ll ans = 0;
    while(!q.empty()){
        ans += q.top() * q.top();
        q.pop();
    }
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
