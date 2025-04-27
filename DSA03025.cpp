// DSA03025 - TRỤC TỌA ĐỘ

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

void solve(){
    int n;
    cin >> n;
    vector<ii> p;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end(), [](ii a, ii b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    vector<ii> ans = {p[0]};
    for(int i = 1; i < n; i++){
        auto [f, s] = p[i];
        if(f >= ans.back().second){
            ans.push_back(p[i]);
        }
    }
    cout << ans.size();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
