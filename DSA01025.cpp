// ĐẶT TÊN - 2

#include <bits/stdc++.h>
using namespace std;
// A = 65
const int A = 65;

vector<char> name;
int n, k;

void init(){
    name.clear();
    cin >> n >> k;
}

void BackTrack(int pos){
    if(name.size() == k){
        for(auto x : name)
            cout << x;
        cout << endl;
        return;
    }

    for(int i = pos; i < n; i++){
        name.push_back(char(i + A));
        BackTrack(i+1);
        name.pop_back();
    }
}

void solve(){
    init();
    BackTrack(0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
