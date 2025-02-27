// DSA02039 - PHÂN TÍCH SỐ 2

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;
vector<int> process;

void BackTrack(int pos, int sum){
    if(sum == n){
        ans.push_back(process);
        return;
    }
    for(int i = pos; i > 0; i--){
        process.push_back(i);
        if(sum + i <= n)
            BackTrack(i, sum + i);
        process.pop_back();
    }
}

void init(){
    cin >> n;
    ans.clear();
    process.clear();
}

void solve(){
    init();
    BackTrack(n, 0);
    cout << ans.size() << endl;
    for(auto v : ans){
        cout << "(";
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            if(i == v.size() - 1)
                cout << ") ";
            else
                cout << " ";
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