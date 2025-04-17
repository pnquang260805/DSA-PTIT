// DSA03008 - SẮP XẾP CÔNG VIỆC 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int,int>> start_end(n);
    for(int i = 0; i < n; i++){
        start_end[i] = {a[i], b[i]};
    }
    sort(start_end.begin(), start_end.end(), [](pair<int,int> x, pair<int,int> y){
        if(x.second == y.second)
            return x.first > y.first;
        return x.second < y.second;
    });
    vector<pair<int,int>> ans;
    ans.push_back(start_end[0]);
    for(int i = 1; i < n; i++){
        if(ans.back().second <= start_end[i].first){
            ans.push_back(start_end[i]);
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
