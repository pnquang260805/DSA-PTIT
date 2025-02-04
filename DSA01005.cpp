// Sinh hoán vị

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
vector<bool> mark;

void init(){
    cin >> n;
    ans.clear();
    for(int i = 0; i < n; i++){
        mark.push_back(false);
    }
}

void BackTrack(){
    if(ans.size() == n){
        for(auto j : ans){
            cout << j;
        }
        cout << " ";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            mark[i] = true;
            ans.push_back(i);
            BackTrack();
            mark[i] = false;
            ans.pop_back();
        }
    }
}

void solve(){
    init();
    BackTrack();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
