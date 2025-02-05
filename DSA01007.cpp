// XÂU AB CÓ ĐỘ DÀI N

#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> ans;
void init(){
    cin >> n;
    ans.clear();
}

void BackTrack(){
    if(ans.size() == n){
        for(auto x : ans)
            cout << x;
        cout << " ";
        return;
    }
    // A = 65
    for(int i = 0; i < 2; i++){
        ans.push_back(char(i+65));
        BackTrack();
        ans.pop_back();
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
