// DSA03010 - NỐI DÂY 1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        int x;
        cin >> x;
        cout << x;
        return;
    }
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> q; // hàng chờ trọng số nhỏ hơn đứng đầu
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    while(q.size() > 1){
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();

        int sum = t1 + t2;
        ans += sum;
        q.push(sum);
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
