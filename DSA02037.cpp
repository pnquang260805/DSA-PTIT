// DSA02037 - DÃY CON CÓ TỔNG NGUYÊN TỐ

#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime(100001, true);

void seive(){
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= 1000; i++){
        if(is_prime[i]){
            for(int j = i * i; j < 100001; j += i){
                is_prime[j] = false;
            }
        }
    }
}

int n;
vector<int> nums;
set<vector<int>> ans;
vector<int> v;

void BackTrack(int pos, int total){
    if(is_prime[total]){
        ans.insert(v);
    }
    for(int i = pos; i < n; i++){
        v.push_back(nums[i]);
        total += nums[i];
        BackTrack(i+1, total);
        v.pop_back();
        total -= nums[i];
    }
}

void solve(){
    cin >> n;
    ans.clear();
    nums.clear();
    nums.resize(n);
    v.clear();
    for(int &num : nums)
        cin >> num;
    sort(nums.rbegin(), nums.rend());
    BackTrack(0, 0);
    for(auto i : ans){
        for(auto x : i){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    seive();

    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
