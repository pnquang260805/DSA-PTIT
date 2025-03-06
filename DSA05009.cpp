// DSA05009 - TẬP CON BẰNG NHAU

#include <bits/stdc++.h>
using namespace std;

int calc(int pos, int total, int target, int n, vector<int> &nums, vector<vector<int>> &mem){
    if(pos >= n){
        return 0;
    }

    if(total == target){
        return 1;
    }

    if(mem[pos][total] != -1)
        return mem[pos][total];

    int skip = calc(pos + 1, total, target, n, nums, mem);
    int pick = ((total + nums[pos] <= target) ? calc(pos+1, total + nums[pos], target, n, nums, mem) : 0);
    mem[pos][total] = pick || skip;
    return mem[pos][total];
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    sort(nums.begin(), nums.end());
    for(int &num : nums)
        cin >> num;
    int summ = accumulate(nums.begin(), nums.end(), 0);
    if(summ % 2 != 0){
        cout << "NO";
        return;
    }
    int target = summ / 2;
    vector<vector<int>> mem(n, vector<int>(summ+1, -1));
    cout << (calc(0, 0, target, n, nums, mem) ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}