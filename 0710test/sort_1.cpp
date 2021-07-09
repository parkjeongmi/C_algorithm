//정렬 : 가장 큰 수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int a, int b){
    string first = to_string(a) + to_string(b);
    string second = to_string(b) + to_string(a);
    return first>second;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),compare);
    for(auto&i : numbers){
        answer+=to_string(i);
    }
    return answer[0] == '0' ?  "0" : answer;
}
