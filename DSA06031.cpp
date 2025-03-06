// DSA06031 - PHẦN TỬ LỚN NHẤT TRONG DÃY CON

// https://viblo.asia/p/deque-va-tim-min-max-tren-doan-tinh-tien-maGK7Bda5j2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    deque<ll> dq; // Lưu chỉ số tăng dần và có giá trị trong nums giảm dần
    for(int i = 0; i < n; i++){
        // loại bỏ tất cả các phần tử ở cuối hàng đợi mà có giá trị nhỏ hơn hoặc bằng ai 
        // (để đảm bảo tính giảm ngặt về giá trị của các phần tử trong hàng đợi).
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        // Loại bỏ toàn bộ các phần tử ở đầu hàng đợi có vị trí nhỏ hơn i−k+1, vì ta đang xét đoạn [i−k+1,i]
        while(!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

        dq.push_back(i);
        if(i + 1 >= k){
            cout << nums[dq.front()] << " ";
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