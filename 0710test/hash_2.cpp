#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


string solution(vector<string> participant, vector<string> completion){
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
    cout << solution(a,b) << endl;
    return 0;
}