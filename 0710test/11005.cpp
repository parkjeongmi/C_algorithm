#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, B;
    cin >> N >> B;
    string s;
    while(N!=0){
        int r = N%B;
        if (r < 10){
            s += (char)(r+'0');
        }
        else {
            s += (char)(r-10 + 'A');
        }
        N = N/B;
    }
    reverse(s.begin(), s.end());
    cout << s;
}