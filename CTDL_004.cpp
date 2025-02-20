// DÃY CON TĂNG DẦN BẬC K

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;
vector<int> process;
int ans;

void init(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    process.clear();
    ans = 0;
}

void BackTrack(int pos){
    if(process.size() == k){
        ans++;
        return;
    }
    for(int i = pos; i < n; i++){
        if(process.size() == 0 ||nums[i] > process[process.size() - 1] ){
            process.push_back(nums[i]);
            BackTrack(i+1);
            process.pop_back();
        }
    }
}

int main(){
    init();
    BackTrack(0);
    cout << ans;
}