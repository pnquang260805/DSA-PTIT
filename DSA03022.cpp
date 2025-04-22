// DSA03022 - TÍCH LỚN NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    vector<int> res;
    res.push_back(a[0] * a[1]);
    res.push_back(a[n - 1] * a[n - 2]);
    res.push_back(a[0] * a[1] * a[n - 1]);
    res.push_back(a[n - 1] * a[n - 2] * a[n - 3]);
    sort(res.rbegin(), res.rend());
    cout << res[0];
}
