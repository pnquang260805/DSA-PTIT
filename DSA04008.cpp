// DSA04008 - SỐ FIBONACCI THỨ N

#include <bits/stdc++.h>
using namespace std;

/*
    |1 1|^(n-1) = |F(n)     F(n-1)|
    |1 0|         |F(n-1)   F(n-2)|
*/

using ll = long long;
const ll MOD = 1e9+7;

vector<vector<ll>> mul(vector<vector<ll>> mat1, vector<vector<ll>> mat2){
    ll x = ((mat1[0][0] * mat2[0][0]) % MOD + (mat1[0][1] * mat2[1][0]) % MOD) %MOD;
    ll y = ((mat1[0][0] * mat2[0][1]) % MOD + (mat1[0][1] * mat2[1][1]) % MOD) %MOD;
    ll z = ((mat1[1][0] * mat2[0][0]) % MOD + (mat1[1][1] * mat2[1][0]) % MOD) %MOD;
    ll t = ((mat1[1][0] * mat2[0][1]) % MOD + (mat1[1][1] * mat2[1][1]) % MOD) %MOD;

    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = t;
    return mat1;
}

vector<vector<ll>> powMat(ll n, vector<vector<ll>> mat){
    if(n == 1)
        return mat;
    if(n <= 0)
        return {{1, 0}, {0, 1}};
    vector<vector<ll>> half = powMat(n/2, mat);
    vector<vector<ll>> full = mul(half, half);
    if(n % 2 != 0)
        full = mul(full, mat);
    return full;
}

void solve(){
    ll n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return;
    }
    vector<vector<ll>> ans = powMat(n-1, {{1,1}, {1,0}});
    cout << ans[0][0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
