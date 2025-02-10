// XÂU NHỊ PHÂN CÓ K BIT 1

#include <bits/stdc++.h>
using namespace std;

int n, k, cnt_one;
vector<int> per;

void init(){
    cin >> n >> k;
    cnt_one = 0;
    per.clear();
}

void BackTrack(){
    if(per.size() == n){
        if(cnt_one == k){
            for(int i = 0; i < n; i++)
                cout << per[i];
            cout << endl;
        }
        return;
    }

    for(int i = 0; i <= 1; i++){
        if(cnt_one + (i==1) > k)
            continue;
        if(i == 1)
            cnt_one++;
        per.push_back(i);
        BackTrack();
        per.pop_back();
        if(i == 1)
            cnt_one--;
    }
}

void solve(){
    init();
    BackTrack();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
