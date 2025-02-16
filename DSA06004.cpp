// HỢP VÀ GIAO CỦA HAI DÃY SỐ 1

#include <bits/stdc++.h>
using namespace std;

void show(set<int> a){
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

set<int> findUninion(vector<int> a, vector<int> b){
    set<int> ans;
    for(int i : a)
        ans.insert(i);
    for(int i : b)
        ans.insert(i);
    return ans;
}

set<int> findIntersection(vector<int> a, vector<int> b){
    set<int> check, ans;
    for(int i : a)
        check.insert(i);
    for(int i : b){
        if(check.find(i) != check.end()){
            ans.insert(i);
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i : a)
        cin >> i;
    for(int &i : b)
        cin >> i;
    set<int> U = findUninion(a, b);
    set<int> I = findIntersection(a, b);
    show(U);
    show(I);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}