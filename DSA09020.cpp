// DSA09020 - CHUYỂN DANH SÁCH KỀ SANG MA TRẬN KỀ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string num;
        while(ss >> num){
            matrix[i][stoi(num)] = 1;
            matrix[stoi(num)][i] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << endl;   
    }
}