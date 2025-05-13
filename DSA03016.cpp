// DSA03016 - SỐ NHỎ NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> k >> n;
    if(k <= 0 || 9*n < k){
        cout << -1;
        return;
    }
    vector<int> v(n, 0);
    k--;
    for(int i = n-1; i >= 0; i--){
        if(k > 9){
            k-=9;
            v[i] = 9;
        }
        else{
            v[i] = k;
            k = 0;
        }
    }
    v[0]++;
    for(int i : v)
        cout << i;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}