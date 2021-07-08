#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v1;
    for (int i=1; i<=5;i++){
        v1.push_back(i);
    }

    for (auto i=v1.begin(); i!=v1.end(); ++i){
        cout << *i << " ";
    }

    cout << "\n";
    for (auto ir = v1.rbegin(); ir!=v1.rend();++ir){
        cout << *ir << " ";
    }

    cout << "\n";
    for (int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }

    cout << "\n";
    for (int i=0l i<v1.size(); i++){
        cout << v1.at(i)<<" ";
    }
    return 0;


}



vector<int> v; //int타입 벡터 생성
vector<int> v = {1,2,3}; //int타입 벡터 생성 후 초기화
vector<int> v[10]; //int타입 벡터 배열(크기는 10)
vector<int> v[] = {{1,2,},{3,4}};
vector<vector<int>> v;
vector<int> v(5);
vector<int> v(5,3);
vector<int> v2(v);

//vector 값 추가
//vector.push_back(value) = 끝에 값 추가
//vector.insert(index,value) = 중간에 값 삽입
v.push_back(10); //마지막 위치에 숫자 10 추가
vector<int>::iterator it = v.begin();
it = v.insert(it,2); //맨 앞에 2 삽입
it = v.insert(it,2,3); //맨 앞에 3을 2개 삽입
it = v.insert(it+2, 2,4); //2번째부터 4를 2개 삽입

//vector 값 삭제
//vector.pop_back = 끝에 값 삭제
//vector.eraser(index,index)
v.pop_back(); //마지막에 넣은 값 제거
v.erase(vec.begin()+10); //index 10의 값 제거
v.erase(vec.begin(),vec.begin()+5) //index 0~5의 값 제거
v.clear() //모든 값 제거

//vector 크기 구하기
v.size(); //vector의 원소 갯수
v.capacity; //vector의 물리적 크기

//vector 값 출력
vecotr<int> v;
for(int i=0; i<5; i++)
    v.push_back(i); //vector 요소 추가

for(int i=0; i<v.size();i++){
    cout << v[i] << " " //모든 값 출력 : 0 1 2 3 4
}

cout << v[2] << endl; //index 2의 값 출력 : 2
cout << v.front() << endl; //처음 요소 출력
cout << v.back() << endl; //마지막 요소 출력


