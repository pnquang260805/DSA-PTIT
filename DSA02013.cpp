// SỐ NGUYÊN TỐ

#include <bits/stdc++.h>
using namespace std;
// N P S
int n, p ,s;
vector<int> process;
vector<vector<int>> ans;
vector<bool> isPrime;

void primeNumber(){
    isPrime.assign(1e6+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i < 1e3+1; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= 1e6; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void init(){
    cin >> n >> p >> s;
    process.clear();
    ans.clear();
}

void BackTrack(int start, int sum){
    if(process.size() == n && sum == s){
        ans.push_back(process);
        return;
    }
    for(int i = start; i < s; i++){
        if(isPrime[i]){
            process.push_back(i);
            if(sum + i <= s){
                BackTrack(i + 1,sum + i);
            }
            process.pop_back();
        }
    }
}

void solve(){
    init();
    BackTrack(p+1, 0);
    cout << ans.size() << endl;
    for(auto v : ans){
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }
}

int main(){
    int t;
    primeNumber();
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}