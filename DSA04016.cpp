// DSA04016 - PHẦN TỬ THỨ K

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(m), b(n), res(m+n);
    for(int &i : a)
        cin >> i;
    for(int &i : b)
        cin >> i;
    int p1 = 0, p2 = 0, idx = 0;
    while(p1 < m && p2 < n){
        if(a[p1] < b[p2]){
            res[idx] = a[p1];
            p1++;
        }
        else{
            res[idx] = b[p2];
            p2++;
        }
        idx++;
    }
    while(p1 < m){
        res[idx] = a[p1];
        p1++;
        idx++;
    }
    while(p2 < n){
        res[idx] = b[p2];
        p2++;
        idx++;
    }
    cout << res[k-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
