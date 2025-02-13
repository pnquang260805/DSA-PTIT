// TỔNG CẶP SỐ NGUYÊN TỐ

#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void init(){
    isPrime.assign(1e6+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 0; i <= 1000; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= 1000000; j+=i)
                isPrime[j] = false;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 2; i <= n / 2; i++){
        if(isPrime[i] && isPrime[n-i]){
            cout << i << " " << n-i;
            return;
        }
    }
    cout << -1;
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
