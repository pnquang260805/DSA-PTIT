// TRÒ CHƠI VỚI CÁC CON SỐ

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> process;
vector<vector<int>> ans;
vector<bool> mark;

void init(){
    cin >> n;
    ans.clear();
    process.clear();
    mark.assign(n+1, false);
}


void BackTrack(){
    if(process.size() == n){
        ans.push_back(process);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            if(process.empty() || abs(process.back() - i) != 1){
                mark[i] = true;
                process.push_back(i);
                BackTrack();
                process.pop_back();
                mark[i] = false;
            }
        }
    }
}

void solve(){
    init();
    BackTrack();
    if(ans.empty())
        cout << "";
    else{
        sort(ans.begin(), ans.end());
        for(auto x : ans){
            for(int l : x)
                cout << l;
            cout << endl;
        }
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
