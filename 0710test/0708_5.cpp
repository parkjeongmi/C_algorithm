#include <iostream>
using namespace std;

int main(void){
    int n,first;
    int ans=0;
    int count = 0;
    cin >> n;
    ans = n;
    while (1){
        count++;
        first = (ans%10 + ans/10)%10;
        ans = 10*(ans%10) + first;
        if (ans == n){
            break;
        }
    }
    cout << count << endl;
    return 0;
}

// int main(){
//     int n,temp1,temp2;
//     int temp=-1;
//     int count = 0;
//     cin >> n;
//     temp = n;
//     while(1){
//         temp1=(temp%10)*10;
//         temp2=((temp%10)+(temp/10))%10;
//         temp=temp1+temp2;
//         count++;
//         if (temp==n){
//             break;
//         }
//     }
//     cout << count << endl;
// }


