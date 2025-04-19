// DSA04025 - DÃY SỐ VÔ HẠN

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

void multiply(vector<vector<ll>>& mat1,vector<vector<ll>>& mat2) {
    // Perform matrix multiplication
    ll x = ((mat1[0][0] * mat2[0][0]) % MOD + (mat1[0][1] * mat2[1][0]) % MOD) % MOD;
    ll y = ((mat1[0][0] * mat2[0][1]) % MOD + (mat1[0][1] * mat2[1][1]) % MOD) % MOD;
    ll z = ((mat1[1][0] * mat2[0][0]) % MOD + (mat1[1][1] * mat2[1][0]) % MOD) % MOD;
    ll w = ((mat1[1][0] * mat2[0][1]) % MOD + (mat1[1][1] * mat2[1][1]) % MOD) % MOD;

    // Update matrix mat1 with the result
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}

void matrixPower(vector<vector<ll>> &mat1, ll n){
    if(n == 0 || n == 1)
        return;
    vector<vector<ll>> mat2 = {{1, 1}, {1, 0}};
    matrixPower(mat1, n/2);
    multiply(mat1, mat1);
    if(n%2 != 0){
        multiply(mat1, mat2);
    }
}

ll fib(ll n){
    if(n <= 1)
        return n;
    vector<vector<ll>> mat1 = {{1, 1}, {1, 0}};
    matrixPower(mat1, n-1);
    return mat1[0][0];
}

void solve(){
    int n;
    cin >> n;
    cout << fib(n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
