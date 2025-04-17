// DSA06025 - SẮP XẾP CHÈN

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    for(int i = 0; i < n; i++){
        cout << "Buoc " << i << ": ";
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        for(int l = 0; l <= i; l++){
            cout << a[l] << " ";
        }
        cout << endl;
    }
}
