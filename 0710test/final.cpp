//수의 자릿수 바꾸는 걸 좋아하는 하이닉스

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //나누기와 나머지 연산을 사용해 while문을 돌면서 일의 자리수부터 각 자릿수를 구할 수 있다.
    int a = 1234567;
    while(a) {
        cout << a % 10 << " ";
        a /= 10;
    }
    cout << "\n";
    //숫자를 문자열로 형변환해 인덱스로 간단하게 각 자릿수의 문자에 접근할 수 있다.
    a = 1234567;
    string s = to_string(a);
    vector<int> v,v2;
    for(char c : s){
        cout << c << " ";
        //문자열의 문자들은 char형으로, int형의 vector에 저장하려면 아스키 코드가 저장됨.
        v2.push_back(c);
    }
    cout << "\n";

    cout << "vector2 : ";
    for(int i : v2){
        cout << i << " ";
    }
    return 0;
}