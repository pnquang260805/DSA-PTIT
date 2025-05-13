// DSA03026 - LỰA CHỌN THAM LAM
// https://www.geeksforgeeks.org/find-smallest-number-with-given-number-of-digits-and-digit-sum/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void large(ll n, ll k){
    if(k <= 0 || 9 * n < k){
        cout << -1;
        return;
    }

    vector<ll> v;
    for(int i = 0; i < n; i++){
        if(k >= 9){
            k -= 9;
            v.push_back(9);
        }
        else{
            v.push_back(k);
            k = 0;
        }
    }
    for(int i : v)
        cout << i;
}

void small(ll n, ll k){
    if(9*n < k || k <= 0){
        cout << -1;
        return;
    }
    k--; // Để dành 1 cho v[0]
    vector<int> v(n, 0);
    for(int i = n-1; i >= 0; i--){
        if(k > 9){
            v[i] = 9;
            k -= 9;
        }
        else{
            v[i] = k;
            k = 0;
        }
    }
    v[0] += 1; // tăng v[0] lên 1. ví dụ v hiện tại: 0 9 9 thì sẽ là 1 9 9
    for(int i : v)
        cout << i;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    small(n, k);
    cout << " ";
    large(n, k);
}

int main(){
    solve();
}