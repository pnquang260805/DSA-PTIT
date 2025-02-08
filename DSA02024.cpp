// Dãy con tăng dần

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<string> ans;
vector<int> process;

void BackTrack(int pos){
    if(process.size() > 1){
        string temp = "";
        for(int i = 0; i < process.size(); i++){
            temp += to_string(process[i]) + " ";
        }
        ans.push_back(temp);
    }
    for(int i = pos; i < n; i++){
        if(process.size() == 0 || nums[i] > process[process.size() - 1]){
            process.push_back(nums[i]);
            BackTrack(i + 1);
            process.pop_back();
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    BackTrack(0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}
