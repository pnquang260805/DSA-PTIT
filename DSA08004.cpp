// DSA08004 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<ll> freq(26, 0);
    for (char x : s)
        freq[x - 'A']++;

    // Những bài cần ưu tiên --> dùng priority queue

    priority_queue<ll> pq;
    for(ll f : freq)
        if(f != 0)
            pq.push(f);
    ll ans = 0;
    while(k-- && !pq.empty())
    {
        ll top = pq.top();
        pq.pop();
        top--;
        if(top > 0)
            pq.push(top);
    }
    while(!pq.empty())
    {
        ll top = pq.top();
        ans += top * top;
        pq.pop();
    }
    cout << ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
