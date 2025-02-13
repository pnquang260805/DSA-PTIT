// TRỘN HAI DÃY

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> n1;
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        n1.push_back(num);
    }
    for(int i = 0; i < m; i++){
        ll num;
        cin >> num;
        n1.push_back(num);
    }
    sort(n1.begin(), n1.end());
    for(int i : n1)
        cout << i << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
