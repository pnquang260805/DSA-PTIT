// DSA04035 - TÍNH LŨY THỪA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

ll modPow(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll res = modPow(a, b/2);
    res = (res * res) % MOD;
    if(b % 2 != 0)
        res = (res * a) % MOD;
    return res;
}

int main(){
    ll a, b;
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
            return 0;
        }
        cout << modPow(a, b) << endl;
    }
}
