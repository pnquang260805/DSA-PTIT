// DI CHUYỂN TRONG MA TRẬN

#include <bits/stdc++.h>
using namespace std;

int calc(int &col, int &row, unordered_map<string, int> &mem, int x, int y){
    if(x >= row || y >= col)
        return 0;
    if(x == row - 1 && y == col - 1)
        return 1;
    string key = to_string(x) + " " + to_string(y);
    if(mem.find(key) != mem.end())
        return mem[key];
    int move_right = calc(col, row, mem, x, y + 1);
    int move_down = calc(col, row, mem, x + 1, y);
    mem[key] = move_down + move_right;
    return mem[key];
}

void solve(){
    int row, col;
    cin >> row >> col;
    for(int i = 0; i < row * col; i++){
        int temp;
        cin >> temp;
    }
    unordered_map<string, int> mem;
    cout << calc(row, col, mem, 0, 0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
