// DSA08003 - HÀNG ĐỢI HAI ĐẦU (DEQUEUE)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq;
    while(n--){
        string s;
        cin >> s;
        if(s == "PUSHFRONT"){
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(s == "PRINTFRONT"){
            cout << (!dq.empty() ? to_string(dq.front()) : "NONE") << endl;
        }
        else if(s == "POPFRONT"){
            if(!dq.empty()){
                dq.pop_front();
            }
        }
        if(s == "PUSHBACK"){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(s == "PRINTBACK"){
            cout << (!dq.empty() ? to_string(dq.back()) : "NONE") << endl;
        }
        else if(s == "POPBACK"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
    }
}
