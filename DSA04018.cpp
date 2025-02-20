// ĐẾM SỐ 0

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    map<int,int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    cout << mp[0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}