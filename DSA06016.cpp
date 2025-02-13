// TÍCH LỚN NHẤT - NHỎ NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> n1, n2;
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        n1.push_back(num);
    }
    for(int i = 0; i < m; i++){
        ll num;
        cin >> num;
        n2.push_back(num);
    }
    sort(n1.rbegin(), n1.rend());
    sort(n2.begin(), n2.end());
    cout << n1[0] * n2[0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
