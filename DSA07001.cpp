// DSA07001 - NGĂN XẾP 1

#include <bits/stdc++.h>
using namespace std;

int main(){
    string cmd;
    vector<int> st;
    while(cin >> cmd){
        if(cmd == "push"){
            int x;
            cin >> x;
            st.push_back(x);
        }

        if(cmd == "pop"){
            if(st.size() != 0){
                st.pop_back();
            }
        }

        if(cmd == "show"){
            if(st.size() != 0){
                for(int i : st)
                    cout << i << " ";
                cout << endl;
            }
            else{
                cout << "empty\n";
            }
        }
    }
}