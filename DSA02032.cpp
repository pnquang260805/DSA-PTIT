// DSA02032 - TỔ HỢP SỐ CÓ TỔNG BẰNG X

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> ans;
vector<int> process;
vector<int> nums;

void BackTrack(int pos, int sum){
    if(sum == k){
        ans.push_back(process);
        return;
    }
    for(int i = pos; i < n; i++){
        process.push_back(nums[i]);
        if(sum + nums[i] <= k)
            BackTrack(i, sum + nums[i]);
        process.pop_back();
    }
}

void init(){
    cin >> n >> k;
    ans.clear();
    process.clear();
    nums.clear();
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

void solve(){
    init();
    BackTrack(0, 0);
    if(ans.size() != 0){
        cout << ans.size() << " ";
        for(auto v : ans){
            cout << "{";
            for(int i = 0; i < v.size(); i++){
                cout << v[i];
                if(i == v.size() - 1)
                    cout << "} ";
                else
                    cout << " ";
            }
        }
    }
    else{
        cout << -1;
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