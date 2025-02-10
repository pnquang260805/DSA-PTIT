// Tổng dãy con = K

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;
vector<bool> mark;
vector<int> process;
vector<vector<int>> ans;

void init(){
    nums.clear();
    mark.clear();
    process.clear();
    ans.clear();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back(num);
        mark.push_back(false);
    }

}

void BackTrack(int pos,int sum){
    for(int i = pos; i < n; i++){
        if(!mark[i]){
            mark[i] = true;
            process.push_back(nums[i]);
            sum += nums[i];
            if(sum == k){
                ans.push_back(process);
            }
            else if(sum < k)
                BackTrack(i+1, sum);
            mark[i] = false;
            process.pop_back();
            sum -= nums[i];
        }
    }
}

int main(){
    init();
    BackTrack(0,0);
    sort(ans.rbegin(), ans.rend()); // sắp xếp theo thứ tự giảm dần. có thể áp dụng cho vector 2 chiều
    for(auto x : ans){
        for(int l : x)
            cout << l << " ";
        cout << endl;
    }
    cout << ans.size();
}
