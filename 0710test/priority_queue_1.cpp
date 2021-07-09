//스택 : 프린터
#include <algorithm>
#include  <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location){
    int answer=0;
    queue<pair<int,int>> que;
    priority_queue<int> que2;
    for(int i=0; i<priorities.size(); i++){
        que.push(make_pair(i,priorities[i]));
        que2.push(priorities[i]);
    }
    while(!que.empty()){
        int f = que.front().first;
        int s = que.front().second;
        if(s == que2.top()){
            if(f == location){
                return answer+1;
            }
            else {
                answer++;
                que.pop();
                que2.pop();
            }
        }
        else{
            que.push(que.front());
            que.pop();
        }
    }
    return answer;
}