// SẮP XẾP CHẴN LẺ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> even, odd, ans;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        (i % 2 == 0) ? even.push_back(x) : odd.push_back(x);
    }
    sort(even.begin(), even.end(), greater<ll>());
    sort(odd.begin(), odd.end());
    int evenIdx = 0, oddIdx = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 != 0){
            cout << odd[oddIdx] << " ";
            oddIdx++;
        }
        else{
            cout << even[evenIdx] << " ";
            evenIdx++;
        }
    }
}