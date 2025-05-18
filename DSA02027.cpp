// DSA02027 - NGƯỜI DU LỊCH

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> cost;
int amount = 0;
vector<bool> visited;
int cmin = INT_MAX;
int ans = INT_MAX;
vector<int> traveled;

void TSP(int current_city){
    if(current_city > n){
        ans = min(ans, amount+cost[traveled[n]][traveled[1]]);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            traveled[current_city] = i;
            amount += cost[traveled[current_city-1]][traveled[current_city]];
            if(ans > amount+(n-i+1)*cmin)
                TSP(current_city+1);
            amount -= cost[traveled[current_city-1]][traveled[current_city]];
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    cost.resize(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
            if(cost[i][j] != 0){
                cmin = min(cmin, cost[i][j]);
            }
        }
    }
    visited.assign(n+1, false);
    traveled.assign(n+1, 0);
    visited[1] = true;
    traveled[1] = 1;
    TSP(2);
    cout << ans;
}