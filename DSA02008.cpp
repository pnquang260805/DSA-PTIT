// DSA02008 - CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> ans, mat;
vector<int> temp;
unordered_set<int> cols;

void BackTrack(int r, int total){
    if(total == k && temp.size() == n){
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < n; i++){
        if(cols.find(i) == cols.end()){
            cols.insert(i);
            temp.push_back(i+1);
            total += mat[r][i];
            if(total <= k)
                BackTrack(r+1, total);
            cols.erase(i);
            temp.pop_back();
            total -= mat[r][i];
        }
    }
}

int main(){
    cin >> n >> k;
    mat.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    ans.clear();
    temp.clear();
    BackTrack(0, 0);
    cout << ans.size() << endl;
    for(auto v : ans){
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
}
