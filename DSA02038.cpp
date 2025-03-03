// DSA02038 - DÃY CON CÓ K PHẦN TỬ TĂNG DẦN

#include <bits/stdc++.h>
using namespace std;

void BackTrack(int pos, int &k, vector<int> process, vector<int> &nums){
    if(process.size() == k){
        for(int num : process){
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    for(int i = pos; i < nums.size(); i++){
        process.push_back(nums[i]);
        BackTrack(i+1, k, process, nums);
        process.pop_back();
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    sort(nums.begin(), nums.end());
    BackTrack(0, k, {}, nums);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}