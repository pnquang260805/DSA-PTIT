// SẮP XẾP THEO SỐ LẦN XUẤT HIỆN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums;
    map<int,int> freq;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        freq[num]++;
        nums.push_back(num);
    }
    // Chuyển map sang vector<pair<int,int>>
    vector<pair<int,int>> vFreq(freq.begin(), freq.end());
    sort(vFreq.begin(), vFreq.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
    });
    for(auto x : vFreq){
        for(int i = 0; i < x.second; i++){
            cout << x.first << " ";
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
