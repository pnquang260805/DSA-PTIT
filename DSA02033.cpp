// SỐ XA CÁCH

#include <bits/stdc++.h>
using namespace std;

vector<int> process;
vector<vector<int>> ans;
vector<bool> mark;
int n;

void init(){
    cin >> n;
    ans.clear();
    process.clear();
    mark.assign(n+1,false);
}

void BackTrack(){
    if(process.size() == n){
        ans.push_back(process);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            if(process.empty() || abs(process.back() - i) != 1){ // Phải để điều kiện empty lên trước để tránh gặp lỗi vì nó sẽ check điều kiện này trước
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
    if(ans.size() == 0){
        cout << "";
    }
    else{
        sort(ans.begin(), ans.end());
        for(auto x : ans){
            for(int num : x)
                cout << num;
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
