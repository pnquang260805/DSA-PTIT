// DSA05017 - DÃY SỐ BI-TONIC

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vv;

int max_inc(int n, vector<int> &a, vector<int> &inc_mem){
    if(n >= a.size())
        return 0;
    if(inc_mem[n] != -1)
        return inc_mem[n];
    int res = a[n];
    for(int j = 0; j < n; j++){
        if(a[j] < a[n]){
            res = max(res, a[n] + max_inc(j, a, inc_mem));
        }
    }
    inc_mem[n] = res;
    return res;
}

int max_desc(int n, vector<int> &a, vector<int> &desc_mem){
    if(n >= a.size())
        return 0;
    if(desc_mem[n] != -1)
        return desc_mem[n];
    int res = a[n];
    for(int j = n+1; j < a.size(); j++){
        if(a[j] < a[n]){
            res = max(res, a[n] + max_desc(j, a, desc_mem));
        }
    }
    desc_mem[n] = res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    vector<int> inc_mem(n, -1);
    vector<int> desc_mem(n, -1);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int inc = max_inc(i, a, inc_mem);
        int des = max_desc(i, a, desc_mem);
        ans = max(ans, inc + des - a[i]);
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
