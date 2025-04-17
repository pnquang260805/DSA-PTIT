// CTDL_003 - PHƯƠNG ÁN TỐI ƯU --> Bài toán cái túi + truy vết

#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<int> values, weight;
string ans;

int dp(int i, int cap, vector<vector<int>> &mem){
    if(i == n || cap == 0)
        return 0;

    if(mem[i][cap] != -1)
        return mem[i][cap];

    int skip = dp(i+1, cap, mem);
    int pick = 0;
    if (cap >= weight[i]){
        pick = dp(i+1, cap-weight[i], mem) + values[i];
    }
    mem[i][cap] = max(pick, skip);
    return mem[i][cap];
}

void trace(int i, int cap, vector<vector<int>> &mem) {
    if (i == n || cap == 0) return;

    if (dp(i, cap, mem) == dp(i + 1, cap, mem)) {
        ans[i] = '0';
        trace(i + 1, cap, mem);
    } else {
        ans[i] = '1';
        trace(i + 1, cap - weight[i], mem);
    }
}

int main(){
    cin >> n >> w;
    ans.resize(n, '0');
    values.clear();
    weight.clear();
    values.resize(n);
    weight.resize(n);
    vector<vector<int>> mem(n+1, vector<int>(w+1,-1));
    for(int &x : values)
        cin >> x;
    for(int &x : weight)
        cin >> x;
    int max_value = dp(0, w, mem);
    cout << max_value << '\n';

    trace(0, w, mem);
    for (char c : ans) cout << c << ' ';
    cout << '\n';
}
