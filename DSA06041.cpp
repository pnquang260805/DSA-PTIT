// DSA06041 - SỐ XUẤT HIỆN NHIỀU NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        mp[x]++;
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        if(ans < mp[a[i]] && mp[a[i]] > n/2){
            ans = a[i];
        }
    }
    if(ans == INT_MIN)
        cout << "NO";
    else
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