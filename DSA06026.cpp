// DSA06026 - SẮP XẾP NỔI BỌT

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    for(int i = 0; i < n; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                swapped = true;
                swap(a[j+1], a[j]);
            }
        }
        if(swapped){
            cout << "Buoc " << i+1 << ": ";
            for(int l = 0; l < n; l++)
            {
                cout << a[l] << " ";
            }
            cout << endl;
        }
    }
}
