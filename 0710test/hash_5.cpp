//해시 : 위장
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

//unordered_map 활용한 풀이
int solution1(vector<vector<string>>clothes){
    int answer = 1;
    unordered_map <string, int> m;
    for (auto clo : clothes){
        m[clo[1]] += 1;
    }
    for (auto n : m ){
        answer *= (n.second+1);
    }
    return answer-1;
}

//map 활용한 풀이
int solution2(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(auto cloth : clothes){
        m[cloth[1]]+=1;
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        answer *= it->second+1;
    }

    return answer-1;
}