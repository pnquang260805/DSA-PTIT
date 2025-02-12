// Dãy số 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back(num);
    }

    ans.push_back(nums);
    for(int i = 1; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < n - i; j++){
            temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
        }
        ans.push_back(temp);
    }
    reverse(ans.begin(),ans.end());
    for(auto x : ans){
        cout << "[";
        for(int i = 0; i < x.size(); i++){
            cout << x[i];
            if(i == x.size()-1)
                cout << "] ";
            else
                cout << " ";
        }

    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        cout << endl;
    }
}
