// DSA09002 - CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        if (s.empty()) continue;
        stringstream ss(s);
        int j;
        while(ss >> j){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    set<pair<int,int>> se;
    for(int i = 1; i <= n; i++){
        for(int j : adj[i]){
            int minn = min(i, j);
            int maxx = max(i, j);
            se.insert({minn, maxx});
        }
    }
    for(auto e : se){
        cout << e.first << " " << e.second << endl;
    }
}
