// DSA02010 - TỔ HỢP SỐ CÓ TỔNG BẰNG X 

#include <bits/stdc++.h>
using namespace std;

bool found = false;

void BackTrack(int pos, int n, int k, int sum, vector<int> &nums, vector<int> &process){
    if(sum == k){
        cout << "[";
        for(int i = 0; i < process.size(); i++){
            cout << process[i];
            if(i == process.size() - 1)
                cout << "]"; // Không có dấu cách :)) đề lừa lắm :)))
            else
                cout << " ";
        }
        found = true;
        return;
    }

    for(int i = pos; i < nums.size(); i++){
        if(sum + nums[i] > k)
            break;
        process.push_back(nums[i]);
        BackTrack(i, n, k, sum + nums[i], nums, process);
        process.pop_back();
    }
}

void solve(){
    int n, k;
    found = false;
    cin >> n >> k;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    sort(nums.begin(), nums.end());
    vector<int> process;
    BackTrack(0, n, k, 0, nums, process);
    if(!found)
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}