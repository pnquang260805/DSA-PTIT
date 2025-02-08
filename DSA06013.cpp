// Số lần xuất hiện

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    unordered_map<int,int> freq;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        freq[num]++;
    }
    if(freq.find(k) != freq.end()){
        cout << freq[k];
    }
    else{
        cout << -1;
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
