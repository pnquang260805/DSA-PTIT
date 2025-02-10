// SỐ THỨ TỰ HOÁN VỊ

#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> nums, process;
vector<bool> mark;

void init(){
    cin >> n;
    ans = 1;
    nums.clear();
    process.clear();
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    mark.assign(n+1, false);
}

void BackTrack(){
    if(process.size() == n){
        if(process == nums)
            cout << ans;
        else
            ans++;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            mark[i] = true;
            process.push_back(i);
            BackTrack();
            process.pop_back();
            mark[i] = false;
        }
    }
}

void solve(){
    init();
    BackTrack();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
