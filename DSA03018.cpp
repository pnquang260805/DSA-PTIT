// DSA03018 - SỐ MAY MẮN
// https://www.geeksforgeeks.org/minimum-number-digits-4-7-given-sum/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin >> k;
    int four = 0, seven = 0;
    // Ưu tiên chia số lớn trước rồi đến số nhỏ
    while(k > 0){
        if(k % 7 == 0){
            k -= 7;
            seven++;
        }
        else if(k % 4 == 0){
            k -= 4;
            four++;
        }
        else{
            four++;
            k -= 4;
        }
    }
    if(k < 0){
        cout << -1;
        return;
    }
    for(int i = 0; i < four; i++)
        cout << 4;
    for(int i = 0; i < seven; i++)
        cout << 7;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}