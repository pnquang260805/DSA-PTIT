// DSA05016 - SỐ UGLY

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void solve(){
    ull n;
    cin >> n;
    vector<ull> factors = {2, 3, 5};
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    unordered_set<ull> seen; // loại bỏ trùng nhau
    pq.push(1);
    seen.insert(1);
    int cnt = 1;
    for (ull i = 1; i < n; ++i) {
        ull curr = pq.top();
        pq.pop();

        for (auto f : factors) {
            ull next = curr * f;
            if (seen.find(next) == seen.end()) {
                seen.insert(next);
                pq.push(next);
            }
        }
    }
    for(int i = cnt - pq.size() + 1; i <= n; i++){
        pq.pop();
    }
    cout << pq.top();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
