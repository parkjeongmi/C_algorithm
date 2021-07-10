# cpp  🙏🏻
- Hash
- Queue, Stack
- Sort
- Vector


----
# Hash

* 중복을 허용하지 않는 자료 구조

| 종류               | 라이브러리 내부 구현 |
| ------------------ | -------------------- |
| std::unordered_map | Hash table           |
| std::map           | binary search tree   |



## 1) unordered_map

* 헤더

  ```c++
  #include<unordered_map>
  ```

* 선언

  ```c++
  std::unordered_map<string, int>d;
  //<key의 type, value의 type> name;
  
  cout << d["leo"] << endl; 
  //존재하지 않는 value는 기본 값 -> 0혹은 " "
  
  d["leo"]=3; //"leo" key에 대한 value 업데이트
  cout << d["leo"] << endl;
  ```

* 순회

  ```c++
  for(auto&i:d)
    cout << i.first << "-" << i.second << endl;
  
  //auto를 통해 i의 type은 컴파일러가 추론한 => 여기에서는 순서쌍인 pair
  //i.first = key , i.second = value
  ```

* 예시 : 프로그래머스 - 완주하지 못한 선수

  ```c++
  #include <string>
  #include <vector>
  #include <unordered_map>
  
  using namespace std;
  
  string solution(vector<string> participant, vector<string> completion) {
      string answer = "";
      std::unordered_map<string, int>d;
      for (auto&i : participant) d[i]++;
      for (auto&i : completion) d[i]--;
      for (auto&i : d){
          if (i.second!=0) answer = i.first;
      }
      return answer;
  }
  ```

* 예시 : 프로그래머스 - 위장

  ```c++
  #include <vector>
  #include <unordered_map>
  #include <string>
  using namespace std;
   
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
  ```

  

## 2) Map

* 헤더

  ```c++
  #include <map>
  ```

* 선언

  ```c++
  std::map<string, int> d;
  //<key의 type, value의 type> name
  
  d.insert({"Cam", 300}); //"Cam" key에 대한 value 300 업데이트
  
  if (d.find("Cam") != d.end()){
    cout << "find" << endl;
  }
  else {
    cout << "not find" << endl;
  }
  //데이터를 끝까지 찾지 못했을 경우, iterator는 map.end()를 반환
  
  map<string, int, greater>d;
  //내림차순의 경우 'greater'를 추가
  ```

* 순회

  * 인덱스 기반

    ```c++
    for (auto iter=d.begin(); iter!=d.end(); i++){
      cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
    ```

  * 범위 기반

    ```c++
    d.erase(d.begin()+2); //특정 위치의 요소 삭제d.erase("Cam"); //key 값 기준으로 요소 삭제d.erase(d.begin(),d.end()); //erase 함수로 모든 요소 삭제d.clear(); //clear 함수로 모든 요소 삭제
    ```

* 예시 : 프로그래머스 위장

  ```c++
  #include <string>#include <vector>#include <map>using namespace std;int solution(vector<vector<string>> clothes) {    int answer = 1;    map<string,int> m;    for(auto clo : clothes){        m[clo[1]]+=1;    }    for(auto iter=m.begin();iter!=m.end();iter++){        answer*=iter->second+1;    }    return answer-1;}
  ```

* 예시 : 프로그래머스 베스트 앨범

  ```c++
  #include <map>#include <vector>#include <string>using namespace std;vector<int> solution(vector<string> genres, vector<int> plays){  vector <int> answer;  std::map<string, int> music;  std::map<string, map<int, int>> musicalist;  for(int i=0; i<genres.size(); i++){    music[genres[i]] += plays[i];    musicalist[genres[i]][i] = plays[i];  }    while (music.size()>0){    string genre{};    int max{0};    for(auto mu : music){      if(mu.second > max){        max = mu.second;        genre = mu.first;      }    }        for(int i=0; i<2; i++){      int val=0, ind=-1;      for(auto m1 : musicalist[genre]){        if(val<m1.second){          val = m1.second;          ind = m1.first;        }      }            if (ind==-1)break;      answer.push_back(ind);      musicalist[genre].erase(ind);    }    music.erase(genre);  }  return answer;}
  ```

  * vector에서 push하기

    ```c++
    vector<int> answer;answer.push_back(ind);
    ```

  * vector에서 erase하기

    ```c++
    musicalist[genre].erase(ind);music.erase(genre);//erase(삭제할 요소의 위치)
    ```

  * map 중첩해서 사용하기

    ```c++
    map<string,map<int,int>> musicalist;
    ```

  * 최대 값 구하기

    ```c++
    for(auto mu :music){  int max{0};  string genre{};  if (mu.second > max){    max = mu.second;    genre = mu.first;  }}
    ```
    
 ---
 # 1) Queue

* 선입선출 (First In First Out)
  * front 원소와 back 원소에 접근 가능

* 헤더

  ```c++
  #include <queue>
  ```

* 선언

  ```c++
  queue<int>q;
  //<queue 원소의 type> name;
  ```

* 함수

  | 기본 함수     | 설명                               | 사용                         |
  | ------------- | ---------------------------------- | ---------------------------- |
  | push(element) | 큐에 원소를 추가(맨 뒤)            | q.push(1)                    |
  | pop()         | 큐에 있는 원소 삭제(맨 앞)         | q.pop()                      |
  | front()       | 큐 맨 앞 원소 반환                 | int a = q.front()            |
  | back()        | 큐 맨 뒤 원소 반환                 | int b = q.back()             |
  | empty()       | 비어있으면 true, 아니면 false 반환 | while(!q.empty())            |
  | size()        | 사이즈 반환                        | for(int i=0; i<q.size();i++) |

* 예시 : 프로그래머스 - 기능개발

  ```c++
  #include<queue>
  #include<queue>
  #include<vector>
  using namespace std;
  
  vector<int>solution(vector<int>progresses, vector<int>speeds){
    vector<int> answer;
    queue<int> rest;
    for(int i=0; i<progresses.size(); i++){
      int re = 100-progresses[i];
      if (re%speeds[i]!=0) re += speeds[i]; //예외처리(테스트케이스 11)
  		rest.push(re/speeds[i]);    
    }
    
    while(!rest.empty()){
      int count = 1;
      int now = rest.front();
      rest.pop();
      while(rest.size()>=1){
        if (rest.front<=now){
          rest.pop();
          count++;
        }
        else break;
      }
      answer.push_back(count); //answer는 vector이기 때문에 push_back 사용
    }
    return answer;
  }
  ```



# 1-2) priority_queue

* 헤더

  ```c++
  #include <queue>
  ```

* 선언

  ```c++
  priority_queue<int> pq;
  //<type> 변수명 : 선언한 자료형 변수들을 내림차순에 따라 정렬
  
  priority)queue<int, container, 비교함수>pq;
  //<type, container, 비교함수> 변수명 : 비교함수에 따라 정렬
  ```

* 함수

  | 기본 함수 | 설명                     | 사용             |
  | --------- | ------------------------ | ---------------- |
  | top()     | 맨 앞에 있는 원소를 반환 | int s = pq.top() |

* 예시 : 프로그래머스 - 프린터

  ```c++
  #include <string>
  #include <vector>
  #include <queue>
  using namespace std;
  
  int solution(vector<int> priorities, int location){
    int answer = 0;
    queue<pair<int,int>> que //pair 클래스를 통해 두 객체를 하나로 객체로 묶음 
    priority_queue<int> que2; //priority_queue선언
    for(int i=0; i<priorities.size(); i++){
      que.push(make_pair(i,priorities[i])); //pair를 만들어주는 make_pair함수
      que2.push(priorities[i]);
    }
    while(!que.empty()){
      int f = que.front().first;
      int s = que.front().second;
      if (s==que2.top()){
        if (f==location){
          return answer+1;
        }
        else{
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
  ```

* 예시 : 프로그래머스 - 더 맵게

  ```c++
  #include <queue>
  #include <string>
  using namespace std;
  
  int solution(vector<int> scoville, int K){
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto&i :scoville){
      q.push(i);
    }
    while(1){
      int min1 = q.top();
      q.pop();
      if(min1>=K) break;
      else if(q.empty){
        answer -=1;
        break;
      }
      int min2 = q.top();
      q.pop();
      q.push(min1+2*min2);
      answer++;
    }
    return answer;
  }
  ```

  

* 예시 : 오름차순

  ```c++
  #include <iostream>
  #include <queue>
  using namespace std;
  
  int main(void){
    priority_queue<int,vector<int>,greater<int>>pq; //비교함수에 greater<int>를 넣어줌
    pq.push(5);
    pq.push(1);
    pq.push(7);
    for(int i=0; i<3; i++){
      cout << pq.top() << '';
      pq.pop();
    }
  }
  //1 5 7
  ```

  



# 2) Stack

* 선입후출 (First In Last Out)

* 헤더

  ```c++
  #include <stack>
  ```

* 선언

  ```c++
  stack<int> s;//stack<type> name;stack<int> s2({1,2,3,4,5});s2.top() //5가 나옴
  ```

  ---
  # Sort

* 헤더

```c++
#include <algorithm>
```

* 선언

```c++
sort(start, end) //[start, end) 범위의 인자를 오름차순으로 정렬
sort(start, end, compare) //compare 기준으로 정렬
sort(start, end, greater<자료형>()) //[start, end) 범위의 인자를 내림차순으로 정렬
```

* 예시(내림차순) : 프로그래머스 H-Index

  ```c++
  #include <algorithm>
  #include <string>
  #include <vector>
  
  using namespace std;
  
  int solution(vector<int> citations){
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>()); //greater<int>()
    if(!citations[0]) return 0;
    for(int i=0; i<citations.size(); i++){
      if(citations[i]>i) answer++;
      else break;
    }
    return answer;
  }
  ```



## + sort(start, end, compare)

* compare() 함수를 sort()의 세 번째 인자 값으로 넣으면, 해당 함수의 반환 값에 맞게 정렬이 동작

* 예시

  ```c++
  #include <iostream>
  #include <algorithm>
  using namespace std;
  
  bool compare(int a, int b){
    return a>b;
  }
  
  int main(void){
    int a[10] = {9,3,5,4,1}
    sort(a, a+10, compare); //위의 compare에 따라 정렬함
    for(int i=0;i<10;i++){
      cout << a[i] << ' ';
    }
  }
  ```

* 예시 : 프로그래머스 - 가장 큰 수

  ```c++
  #include <string>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  bool compare(int a, int b){
    string first = to_string(a) + to_string(b);
    string second = to_string(b) + to_string(a);
    return first > second;
  }
  string solution(vector<int> numbers){
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(auto&i:numbers){
      answer+=to_string(i);
    }
    return answer[0]=='0' ? "0" : answer; // a ? b : c -> a이면 b이고, 아니면 c
  }
  ```

  

* 특정한 변수 기준으로 정렬

  ```c++
  #include <iosteram>
  #include <algorithm>
  using namespace std;
  
  class Student{
    public :
    string name;
    int score;
    Student(string name, int score){
      this-> name = name;
      this-> score = score;
    }
    bool operator < (Student &student){
      return this->score < student.score;
    }
    
  };
  
  bool compare(int a, int b){
    return a>b;
  }
  
  int main(void){
    Student students[] = {
      Student("나동빈", 90);
      Student("나동반", 80);
      Student("나동번", 70);
    };
    sort(students, students+3);
    for(int i=0; i<5; i++){
      cout << students[i].name << ' ';
    }
  }
  ```

  

## + Appendix

* string::substr(시작인덱스, 문자열 길이)

  ```c++
  s1 = s.substr(2,3) //2번 인덱스부터 문자열 3개
  ```

* string::substr(시작인덱스)

  ```c++
  s2 = s.substr(1) //1번 인덱스부터 문자열 끝까지
  ```

* 예시

  ```c++
  if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
  //1) phone_book의 i번째 원소와
  //2) i+1번째 원소를 0부터 phone_book[i]의 사이즈만큼의 길이로 자른 것
  //1)과 2)가 같다면!
  ```
---
# Vector

## 핵심

| 종류         | 함수               | 설명                                      |
| ------------ | ------------------ | ----------------------------------------- |
| 추가 및 삭제 | push_back(element) | 벡터 제일 뒤에 원소 추가                  |
|              | pop_back()         | 벡터 제일 뒤에 원소 삭제                  |
| 조회         | [i]                | i번째 원소 반환                           |
|              | at(i)              | i번째 원소 반환                           |
|              | front()            | 첫번째 원소 반환                          |
|              | back()             | 마지막 원소 반환                          |
| 기타         | empty()            | 벡터가 비어있으면 true, 아니면 false 반환 |
|              | size()             | 벡터 원소들의 수 반환                     |



## 헤더파일 & 선언

```c++
#include <vector>
```

```c++
//vector <자료형> 벡터명;
vector <int> v1;
vector <char> v2;
vector <string> v3;
```

```c++
//int
vector <int> v1;
vector <int> v2(10);

vector <int> v3(7,5);
vector <int> v4{0,1,2,3};
vector <int> v5(v2);

//char
vector <char> v1;
vector <char> v2{'a','b','c'};
vector <char> v3(10);

//string
vector <string> v1{"ab", "xyx"};
vector <string> v1 = {"ab", "xyx"};
```



## 멤버함수

* v.size()

  v의 원소의 개수를 반환

* v.empty()

  v가 비어있으면 true(1), 비어있지 않으면 false(0) 반환

* v.front()

  v의 첫번째 원소 반환

* v.back()

  v의 마지막 원소 반환

* v.at(i) 

  v의 i번째 원소 // v[i]와 같음

* v.clear()

  v의 모든 원소 제거

* **v.push_back(5)**

  **v의 맨 뒤에 원소 '5'를 추가**

* **v.pop_back()**

  **v의 맨 뒤에 원소 꺼내기**

* v.insert(i,5)

  v의 i번째 위치에서 원소 '5'를 추가

* v.erase(i)

  v의 i번째 원소 삭제 (v의 size가 1만큼 줄어듬)

* v1.swap(v2)

  v1과 v2를 swap

### iterator

* v.begin()

  beginning iterator를 반환

* v.end()

  end iterator를 반환





## 기타

### sort

* sort(arr,arr+n);
* sort(v.begin(),v.end());
* sort(v.begin(),v.end(),compare); //사용자 정의 함수 사용
* sort(v.begin(), v.end(), greater<자료형>()); //내림차순
* sort(v.begin(),v.end(),less<자료형>());
  



    
