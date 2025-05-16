// DSA08029 - QUAY HÌNH VUÔNG

#include <bits/stdc++.h>
using namespace std;

bool same_vector(vector<int> a, vector<int> b){
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

vector<int> left_rotage(vector<int> a){
    vector<int> x = a;
    x[0] = a[3];
    x[1] = a[0];
    x[3] = a[4];
    x[4] = a[1];
    return x;
}

vector<int> right_rotage(vector<int> a){
    vector<int> x = a;
    x[1] = a[4];
    x[2] = a[1];
    x[4] = a[5];
    x[5] = a[2];
    return x;
}

void solve(){
    vector<int> a(6), b(6);
    for(int &i : a)
        cin >> i;
    for(int &i : b)
        cin >> i;
    queue<pair<vector<int>, int>> q;
    set<vector<int>> se;
    q.push({a, 0});
    se.insert(a);
    while(!q.empty()){
        vector<int> v = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(same_vector(v, b)){
            cout << cnt;
            return;
        }
        vector<int> v1 = left_rotage(v);
        vector<int> v2 = right_rotage(v);
        if(se.count(v1) == 0){
            se.insert(v1);
            q.push({v1, cnt+1});
        }
        if(se.count(v2) == 0){
            se.insert(v2);
            q.push({v2, cnt+1});
        }
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
