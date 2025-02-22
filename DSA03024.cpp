// LỰA CHỌN TỐI ƯU

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> candidates;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        candidates.push_back(make_pair(x, y));
    }
    sort(candidates.begin(), candidates.end(), [](pair<int,int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else{
            return a.second < b.second;
        } 
    });
    pair<int,int> last = candidates[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(last.second <= candidates[i].first){
            ans++;
            last = candidates[i];
        }
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