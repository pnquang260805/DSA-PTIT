// DSA08022 - BỘI SỐ LỚN NHẤT CỦA 3

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> m0, m1, m2;
    int acc = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        acc += x;
        if(x % 3 == 0)
            m0.push_back(x);
        else if(x % 3 == 1)
            m1.push_back(x);
        else
            m2.push_back(x);
    }
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    if(acc % 3 == 1){
        if(!m1.empty()){
            m1.erase(m1.begin());
        }
        else{
            if(m2.size() > 2){
                m2.erase(m2.begin());
                m2.erase(m2.begin());
            }
            else{
                cout << -1;
                return;
            }
        }
    }
    if(acc % 3 == 2){
        if(!m2.empty()){
            m2.erase(m2.begin());
        }
        else{
            if(m1.size() > 2){
                m1.erase(m1.begin());
                m1.erase(m1.begin());
            }
            else{
                cout << -1;
                return;
            }
        }
    }
    vector<int> ans;
    ans.insert(ans.end(), m0.begin(), m0.end());
    ans.insert(ans.end(), m1.begin(), m1.end());
    ans.insert(ans.end(), m2.begin(), m2.end());;
    if(ans.empty()){
        cout << -1;
        return;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    if(ans[0] == 0){
        cout << 0;
        return;
    }

    // In ra số lớn nhất
    for(int x : ans) cout << x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}