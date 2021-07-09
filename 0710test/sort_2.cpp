//정렬 : k번째 수
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto i : commands){
        vector<int> now;
        for(int j=i[0]-1; j<i[1]; j++){
            now.push_back(array[j]);
        }
        sort(now.begin(), now.end());  
        answer.push_back(now[i[2]-1]);
    }
    return answer;
}