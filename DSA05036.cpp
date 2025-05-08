// DSA05036 - TĂNG - GIẢM

#include <bits/stdc++.h>
using namespace std;

typedef pair<float,float> ff;
typedef vector<vector<int>> vv;

int calc(int idx, int prev_idx, vector<ff> &v, vv &mem){
    if(idx >= v.size())
        return 0;
    if(mem[idx][prev_idx] != -1)
        return mem[idx][prev_idx];
    int skip = calc(idx+1, prev_idx, v, mem);
    auto [px, py] = v[prev_idx];
    auto [cx, cy] = v[idx];
    int pick = 0;
    if(px < cx && py > cy){
        pick = 1 + calc(idx+1, idx, v, mem);
    }
    mem[idx][prev_idx] = max(pick, skip);
    return mem[idx][prev_idx];
}

void solve(){
    int n;
    cin >> n;
    vector<ff> v;
    v.push_back({-1e9f, 1e9f});
    for(int i = 0; i < n; i++){
        float x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    vv mem(n+1, vector<int>(n+1, -1));
    int ans = calc(1, 0, v, mem);
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
