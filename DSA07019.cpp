// DSA07019 - HÌNH CHỮ NHẬT LỚN NHẤT
// https://www.youtube.com/watch?v=MMw17pZi5A8
/*
    Với mỗi phần tử, tìm vị trí phần tử bên trái và bên phải gần nhất nhỏ hơn phần tử hiện tại
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> nextSmaller(vector<ll> v){
    ll n = v.size();
    stack<ll> st;
    vector<ll> res(n, n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}

vector<ll> prevSmaller(vector<ll> v){
    ll n = v.size();
    stack<ll> st;
    vector<ll> res(n, -1);
    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> nS = nextSmaller(v);
    vector<ll> pS = prevSmaller(v);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll w = (nS[i] - pS[i] - 1);
        ll area = v[i] * w;
        ans = max(ans, area);
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