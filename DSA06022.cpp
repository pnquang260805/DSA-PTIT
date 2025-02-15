// SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> se;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        se.insert(num);
    }
    
    if(se.size() < 2){
        cout << -1;
    }
    else{
        auto it = se.begin();
        cout << *it << " ";
        it++;
        cout << *it;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}