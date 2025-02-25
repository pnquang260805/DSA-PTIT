// TẬP QUÂN SỰ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> sensinobango(k);
    unordered_set<int> check;
    for(int &bango : sensinobango){
        cin >> bango;
        check.insert(bango);
    }
    int last = k - 1;
    while(last >= 0 && sensinobango[last] == (n - k + last + 1)){
        last--;
    }
    if(last < 0){
        cout << k;
        return;
    }
    int ans = 1;
    vector<int> asita = sensinobango;
    asita[last]++;
    for(int i = last + 1; i < k; i++){
        asita[i] = asita[i-1]+1;
        if(check.find(asita[i]) == check.end()){
            ans++;
        }
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