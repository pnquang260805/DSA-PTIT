// LIỆT KÊ TỔ HỢP

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;
set<int> temp;
vector<int> process;

void BackTrack(int pos){
    if(process.size() == k){
        for(int i : process)
            cout << i << " ";
        cout << endl;
        return;
    }

    for(int i = pos; i < nums.size(); i++){
        process.push_back(nums[i]);
        BackTrack(i+1);
        process.pop_back();
    }
}

int main(){
    process.clear();
    temp.clear();
    nums.clear();

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        temp.insert(x);
    }
    nums.assign(temp.begin(), temp.end());
    BackTrack(0);
}