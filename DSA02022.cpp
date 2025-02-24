// NGÀY ĐẶC BIỆT
// Note: Không cần check xuôi ngược :))))
// Note: Không cần check xuôi ngược :))))

#include <bits/stdc++.h>
using namespace std;

string process;

void BackTrack(){
    if(process.size() == 8){
        string day = process.substr(0, 2);
        string month = process.substr(2, 2);
        string year = process.substr(4, 4);

        if(month == "02" && year[0] == '2' && day != "00"){
            cout << day << "/" << month << "/" << year << endl;
        }
        return;
    }

    process += "0";
    BackTrack();
    process.pop_back();

    process += "2";
    BackTrack();
    process.pop_back();
    
}

int main(){
    process = "";
    BackTrack();
}