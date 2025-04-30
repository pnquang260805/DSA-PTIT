// DSA02009 - CHIA MẢNG

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int acc = 0;
    while(n--){
        int x;
        cin >> x;
        acc += x;
    }
    cout << (acc % k == 0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
