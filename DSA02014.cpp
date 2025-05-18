// DSA02014 - TỪ ĐIỂN

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> vv;

int k, n, m;
vv v;
vector<string> words;
vector<string> ans;

vector<int> d_row = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> d_col = {-1, 0, 1, -1, 1, -1, 0, 1};
string temp;
vector<vector<bool>> visited;

void BackTrack(int x, int y){
    if(find(words.begin(), words.end(), temp) != words.end()){
        ans.push_back(temp);
    }
    for(int i = 0; i < (int)d_row.size(); i++){
        int new_col = y + d_col[i];
        int new_row = x + d_row[i];
        if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !visited[new_row][new_col]){
            visited[new_row][new_col] = true;
            temp += v[new_row][new_col];
            BackTrack(new_row, new_col);
            temp.pop_back();
            visited[new_row][new_col] = false;
        }
    }
}

void solve(){
    words.clear();
    v.clear();
    ans.clear();
    temp = "";

    cin >> k >> n >> m;
    v.resize(n, vector<char>(m+1));
    words.resize(k);
    for(string &s : words)
        cin >> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited.assign(n, vector<bool>(m, false));
            visited[i][j] = true;
            temp = v[i][j];
            BackTrack(i, j);
            temp.clear();
            visited[i][j] = false;
        }
    }
    if(ans.size() == 0){
        cout << -1;
    }
    else{
        for(string s : ans)
            cout << s << " ";
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