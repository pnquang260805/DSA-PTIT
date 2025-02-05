// HOÁN VỊ NGƯỢC

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
        for(auto x : ans)
            cout << x;
        cout << " ";
        return;
    }

    for(int j = n; j >= 1; j--){
        if(!mark[j]){
            mark[j] = true;
            ans.push_back(j);
            BackTrack();
            ans.pop_back();
            mark[j] = false;
        }
    }
}

void solve(){
    init();
    BackTrack();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
