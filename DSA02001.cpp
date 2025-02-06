// DÃY SỐ 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int temp = n-1;
    while(temp >= 0){
        cout << "[";
        for(int i = 0 ; i <= temp; i++){
            cout << nums[i];
            if(i != temp){
                cout << " ";
                nums[i] += nums[i+1];
            }
        }
        cout << "]\n";
        temp--;
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
