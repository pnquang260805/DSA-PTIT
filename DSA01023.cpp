// SỐ THỨ TỰ TỔ HỢP

#include <bits/stdc++.h>
using namespace std;

// n - (k - i - 1)

int n, k, ans;
vector<int> nums;
vector<int> process;
vector<bool> mark;

void init(){
    cin >> n >> k;
    ans = 1;
    nums.clear();
    process.clear();
    mark.clear();
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

void BackTrack(int pos){
    if(process.size() == k){
        if(process == nums){
            cout << ans;
        }
        else{
            ans++;
        }
//        for(int i = 0; i < process.size(); i++)
//            cout << process[i] << " ";
//        cout << endl;
//        return;
    }

    for(int i = pos; i <= n; i++){
        process.push_back(i);
        BackTrack(i+1);
        process.pop_back();
    }
}

void solve(){
    init();
    BackTrack(1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
