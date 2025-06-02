// DSA03009 - SẮP XẾP CÔNG VIỆC 2

#include <bits/stdc++.h>
using namespace std;

struct job{
    int a, b, c;
};

void solve(){
    int n;
    cin >> n;
    vector<job> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v.begin(), v.end(), [](job A, job B){
        return A.c > B.c;
    });
    bool ok[10000] = {false}; // Thời gian i đã được dùng chưa 
    int profit = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = v[i].b; j > 0; j--){
            if(!ok[j]){
                profit += v[i].c;
                cnt++;
                ok[j] = true;
                break;
            }
        }
    }
    cout << cnt << " " << profit;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}