//백준 10872
#include <stdio.h>

//재귀
int fact(int num){
    if (num>1) return num*fact(num-1);
    else return 1;
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%d", fact(N));
    return 0;
}

//for문
int main(void){
    int fac;
    int answer = 1;
    scanf("%d", &fac);
    for (int i=fac; i>0; i--){
        answer=answer*i;
    }
    printf("%d",answer);
    return 0;
}