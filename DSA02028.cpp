// DSA02028 - CHIA ĐỀU

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> a;
int ans = 0;

void BackTrack(int pos, int cnt){
    if(pos == n && cnt == m){
        ans++;
        return;
    }
    int total = 0;
    for(int i = pos; i < n; i++){
        total += a[i];
        if(total == k)
            BackTrack(i+1, cnt+1);
    }
}

int main(){
    cin >> n >> m;
    int acc = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        acc+=x;
        a.push_back(x);
    }
    if(acc % m != 0){
        cout << 0;
    }
    else{
        k = acc / m;
        BackTrack(0, 0);
        cout << ans;
    }
}
