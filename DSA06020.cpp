// Tìm kiếm

#include <bits/stdc++.h>
using namespace std;

// Time O(1), Space O(n)

void solve(){
    int n, k;
    cin >> n >> k;
    unordered_set<int> u;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        u.insert(x);
    }
    if(u.find(k) != u.end())
        cout << 1;
    else
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}