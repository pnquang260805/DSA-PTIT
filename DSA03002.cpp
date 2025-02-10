// NHẦM CHỮ SỐ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calcMax(string a, string b){
    string temp1 = "", temp2 = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '5')
            temp1 += '6';
        else
            temp1 += a[i];
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '5')
            temp2 += '6';
        else
            temp2 += b[i];
    }
    return stoi(temp1) + stoi(temp2);
}

ll calcMin(string a, string b){
    string temp1 = "", temp2 = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '6')
            temp1 += '5';
        else
            temp1 += a[i];
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '6')
            temp2 += '5';
        else
            temp2 += b[i];
    }
    return stoi(temp1) + stoi(temp2);
}


int main(){
    string a, b;
    cin >> a >> b;
    cout << calcMin(a, b) << " " << calcMax(a, b);
}
