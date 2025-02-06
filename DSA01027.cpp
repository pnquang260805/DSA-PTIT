// HOÁN VỊ DÃY SỐ

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<int> bt;
vector<bool> mark;

void init(){
    int maxx = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        maxx = max(maxx, num);
        nums.push_back(num);
    }
    for(int i = 0; i <= maxx; i++){
        mark.push_back(false);
    }
    sort(nums.begin(),nums.end());
}

void BackTrack(){
    if(bt.size() == n){
        for(int num : bt)
            cout << num << " ";
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        if(!mark[nums[i]]){
            mark[nums[i]] = true;
            bt.push_back(nums[i]);
            BackTrack();
            bt.pop_back();
            mark[nums[i]] = false;
        }
    }
}

int main(){
    init();
    BackTrack();
}
