// DSA02036 - DÃY CON CÓ TỔNG LẺ

#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
set<vector<int>> ans; // đảm bảo các dãy con được lưu trữ là duy nhất và được tự động sắp xếp theo thứ tự từ điển.
int n;

vector<int> v;

void BacTrack(int pos){
    if(v.size() != 0 && accumulate(v.begin(), v.end(), 0) % 2 != 0){
        vector<int> temp = v;
        sort(temp.rbegin(), temp.rend());
        ans.insert(temp);
    }
    for(int i = pos; i < n; i++){
        v.push_back(nums[i]);
        BacTrack(i+1);
        v.pop_back();
    }
}

void solve(){
    cin >> n;
    nums.clear();
    nums.resize(n);
    ans.clear();
    for(int &num : nums)
        cin >> num;
    BacTrack(0);
    for(auto i : ans){
        for(auto x : i)
            cout << x << " ";
        cout << endl;
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
