// DSA08025 - QUÂN MÃ
#include <bits/stdc++.h>
using namespace std;

vector<int> X = {-2, -1, 2, 1, -2, -1, 2, 1};
vector<int> Y = {-1, -2, -1, -2, 1, 2, 1, 2};

bool inBoard(int x, int y){
    return (x >= 1 && y >= 1 && x <= 8 && y <= 8);
}

void solve(){
    string s, e;
    cin >> s >> e;
    if(s == e){
        cout << 0;
        return;
    }
    vector<vector<int>> filled(9, vector<int>(9,-1));
    int sx = s[0] - 'a' + 1;
    int sy = s[1] - '0';
    int ex = e[0] - 'a' + 1;
    int ey = e[1] - '0';
    filled[sx][sy] = 0;

    queue<pair<int,int>> q;
    q.push({sx, sy});

    // BFS
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < X.size(); i++){
            int nx = x + X[i];
            int ny = y + Y[i];

            if(inBoard(nx, ny) && filled[nx][ny] == -1){
                filled[nx][ny] = filled[x][y] + 1;
                if(nx == ex && ny == ey){
                    cout << filled[nx][ny];
                    return;
                }
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
