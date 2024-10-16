#include<stdio.h>
void func(int a);
int main(){
    int a;
    scanf("%d",&a);
    func(a);
    printf("\n");
    return 0;
}
void func(int a){
    if(a==-1){
        return;
    }
    char n;
    n=getchar();
    func(a-1);
    printf("%c",n);
}