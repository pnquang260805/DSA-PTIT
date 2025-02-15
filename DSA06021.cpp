// TÌM KIẾM TRONG DÃY SẮP XẾP VÒNG

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    bool found = false;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        if(num == k && !found){
            found = true;
            ans = i;
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