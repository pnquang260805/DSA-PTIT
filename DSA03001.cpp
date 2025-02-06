// ĐỔI TIỀN

#include <bits/stdc++.h>
using namespace std;

vector<int> cash = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

void init(){
    sort(cash.begin(), cash.end(), greater<int>());
}

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i : cash){
        if(n >= i){
            ans += n / i;
            n %= i;
        }
    }
    cout << ans;
}

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
