//해시-전화번호 목록
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string>phone_book){
    unordered_map<string,int> phone;
    for(int i=0; i<phone_book.size(); i++){
        phone[phone_book[i]] = 1;
    }

    for (int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book[i].length(); ++j){
            if(phone[phone_book[i].substr(0,j)] != 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout << solution({"119", "97674223", "1195524421"}) << endl;
}