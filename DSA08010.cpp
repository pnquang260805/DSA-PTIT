// DSA08010 - BIẾN ĐỔI SỐ TỰ NHIÊN

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll k;
    cin >> k;
    unordered_map<ll, bool> visited;
    queue<pair<ll, ll>> q;
    q.push({k, 0});
    while(!q.empty()){
        ll n = q.front().first;
        ll steps = q.front().second;
        q.pop();
        if(n == 2){
            cout << steps+1;
            return;
        }
        for(ll i = 2; i <= sqrt(n); i++){
            if(n%i==0 && visited[n/i] == false){
                visited[n/i] = true;
                q.push({n/i, steps+1});
            }
        }
        q.push({n-1, steps+1});
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
