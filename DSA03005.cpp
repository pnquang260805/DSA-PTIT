// CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> nums;
    for(int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    ll a = 0, b = 0;
    if(k <= n / 2)
    {
        for(int i = 0; i < n; i++)
        {
            if(i < k)
            {
                a += nums[i];

            }
            else
            {
                b +=nums[i];

            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(i < (n - k))
                a += nums[i];
            else
                b += nums[i];
        }
    }
    cout << b - a;
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
