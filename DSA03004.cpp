// Tổng nhỏ nhất
// Dùng xử lý số nguyên lớn

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

string sumBigInt(string a, string b)  // a.size() > b.size();
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = "";
    int carry = 0;
    for(int i = 0; i < b.size(); i++)
    {
        int temp = (a[i] - '0') + (b[i] - '0');
        res += to_string((temp + carry) % 10);
        carry = (temp + carry) / 10;
    }
    for(int i = b.size(); i < a.size(); i++)
    {
        int temp = (a[i] - '0');
        res += to_string((temp + carry) % 10);
        carry = (temp + carry) / 10;
    }
    if(carry != 0)
        res += to_string(carry);
    while(res[res.size() - 1] == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}


void solve()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    string s1 = "", s2 = "";
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        if(i % 2 == 0)
        {
            s1 += to_string(nums[i]);
        }
        else
        {
            s2 += to_string(nums[i]);
        }
    }
    if(s1.size() < s2.size())
    {
        string temp = s1;
        s2 = s1;
        s1 = temp;
    }
    cout << sumBigInt(s1, s2);
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
