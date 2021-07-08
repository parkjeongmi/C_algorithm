//딕셔너리 이용한 풀이
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion){
    string answer = "";
    unordered_map<string, int> temp;
    for (string name : participant){
        temp[name]++;
    }
    for (string name : completion){
        temp[name]--;
    }
    for (auto pair : temp){
        if (pair.second > 0){
            answer = pair.first;
            break;
        }
    }
    return answer;
}
int main(){
    vector<string> a = {"leo", "kiki", "eden"};
    vector<string> b = {"eden", "kiki"};
    cout << solution(a,b) << endl;
    return 0;
}