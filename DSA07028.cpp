// DSA07028 - NHỊP CHỨNG KHOÁN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v)
        cin >> x;
    vector<int> ans(n);
    stack<pair<int,int>> st; // pos - value
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().second <= v[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = i+1;
        }
        else{
            ans[i] = i-st.top().first;
        }
        st.push({i, v[i]});
    }
    for(int i : ans)
        cout << i << ' ';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}