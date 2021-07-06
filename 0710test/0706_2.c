//백준 11005 진법 변환2

//N을 B로 나눈 나머지 기록 -> 거꾸로 출력
//더 이상 나눌 수 없을 때 까지 나누기

#include <stdio.h>

int main(){
    int N, B, cnt;
    char ans[100];
    scanf("%d %d", &N, &B);
    cnt = 0;

    while(N!=0){
        if (N%B < 10)
            ans[cnt++] = (N%B) +'0';
        else ans[cnt++] = (N%B) - 10 + 'A';
        N = N / B;
    }

    for (int i=cnt-1; i>=0; i--)
        printf("%c", ans[i]);
    printf("\n");
    return 0;

}