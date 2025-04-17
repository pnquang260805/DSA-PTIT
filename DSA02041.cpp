// DSA02041 - BIẾN ĐỔI VỀ 1

#include <bits/stdc++.h>
using namespace std;

int calc(int n, vector<int> &mem){
    if(n == 1)
        return 0;
    if(mem[n] != -1)
        return mem[n];

    int res = calc(n-1, mem)+ 1;
    if(n % 2 == 0){
        res = min(res, calc(n/2, mem) + 1);
    }
    if(n % 3 == 0){
        res = min(res, calc(n/3, mem) + 1);
    }
    mem[n] = res;
    return mem[n];
}

void solve(){
    int n;
    cin >> n;
    vector<int> mem(n+1, -1); // lưu số bước để biến số i về 1
    cout << calc(n, mem);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
