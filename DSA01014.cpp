// DSA01014 - TẬP HỢP

#include <bits/stdc++.h>
using namespace std;

int n, k, s;
vector<int> process;
int ans;

void BackTrack(int pos, int sum){
    if(process.size() == k){
        if(sum == s)
            ans++;
        return;
    }
    for(int i = pos; i <= n; i++){
        process.push_back(i);
        BackTrack(i+1, sum + i);
        process.pop_back();
    }
}

int main(){
    while(true){
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0){
            break;
        }
        process.clear();
        ans = 0;
        BackTrack(1, 0);
        cout << ans << endl;
    }
}