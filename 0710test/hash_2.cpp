//해시-완주하지 못한 선수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution1(vector<string> participant, vector<string> completion) {
    string answer = "";
    std::unordered_map<string, int>d;
    for (auto&i : participant) d[i]++;
    for (auto&i : completion) d[i]--;
    for (auto&i : d){
        if (i.second!=0) answer = i.first;
    }
    return answer;
}
string solution2(vector<string> participant, vector<string> completion){
    sort(participant.begin(), participant.end());
    sort(completion.begin(),completion.end());

    for (int i=0; i<participant.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    return participant[participant.size()-1];
}
int main(){
    vector<string> a = {"leo", "kiki", "eden"};
    vector<string> b = {"eden", "kiki"};
    cout << solution1(a,b) << endl;
    return 0;
}