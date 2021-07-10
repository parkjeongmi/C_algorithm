//스택 : 기능개발

//반례 (테스트케이스11) : rest가 정수가 아닐 때
#include <string>
#include <vector>
#include <queue>

using namespace std;

//내 코드
vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int>answer;
    queue<int> rest;
    for(int i=0;i<progresses.size(); i++){
        int re = 100-progresses[i];
        if (re%speeds[i]!=0) re += speeds[i];
        rest.push(re/speeds[i]);
    }
    
    
    while(!rest.empty()){
        int count = 1;
        int now = rest.front();
        rest.pop();
        while(rest.size()>=1){
            if (rest.front()<=now) {
                rest.pop();
                count++;
            }
            else break;
        }
        answer.push_back(count);
       
    }
    return answer;
}

vector<int> solution(vector<int> progresses, vector<int>speeds){
    vector<int> answer;
    queue<int> rest;
    for(int i=0; i<progresses.size();i++){
        int re = 100-progresses[i];
        if (re%speeds[i]!=0) re+= speeds[i];
        rest.push(re/speeds[i]);
    }
    int now = rest.front();
    int count = 0;
    while(!rest.empty()){
        if(now < rest.front()){
            answer.push_back(count);
            now = rest.front();
            count = 0;
        }
        else{
            count++;
            rest.pop();
        }
    }
    if(count!=0) answer.push_back(count);
    return answer;
}