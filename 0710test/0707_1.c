//백준 2671 : 잠수함식별
//a가 엔진소리면 "SUBMARINE" 아니면 "NOISE" 출력
//엔진소리 : (100~1~|01)   -> 100~1과 01을 섞음
//a = 10010111

#include <stdio.h>
char fact(char question[]){
    if question() return "SUBMARINE" ;
    else return "NOISE";
}
int main(){
    char a;
    scanf("%d",&a);
    printf(fact(a));
}

// int a[2][9]={
//     {1,0,1,6,7,4,7,7,1},
//     {3,2,3,0,2,5,0,8,5},
// };
// char *x[2]={"NOISE","SUBMARINE"};
// int main()
// {
//     int n=0;
// 	char s[151], *p=s;
    
// 	memset(s,0,151);
// 	scanf("%150[01]",s);
    
//     do{n=a[*p-'0'][n];}while(*(++p)>0&&n>0);
    
//     printf("%s",x[n%3>>1]);
//     return 0;
// }