// DÃY CON TỔNG BẰNG K

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;
vector<int> process;
vector<vector<int>> ans;
bool found;

void init(){
    found = false;
    nums.clear();
    process.clear();
    ans.clear();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
}

void BackTrack(int pos, int sum = 0){
    if(sum == k){
        ans.push_back(process);
        return;
    }
    if(sum > k)
        return;

    for(int i = pos; i < n; i++){
        process.push_back(nums[i]);
        sum += nums[i];
        BackTrack(i+1, sum);
        process.pop_back();
        sum -= nums[i];
    }
}

void solve(){
    init();
    BackTrack(0,0);
    if(ans.size() != 0){
        for(int i = 0; i < ans.size(); i++){
            cout << "[";
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << (j == ans[i].size() - 1 ? "] " : " ");
            }
        }
    }
    else
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
        cout << endl;
    }
}
