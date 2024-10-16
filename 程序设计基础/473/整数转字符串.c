#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 10
//请补充itostr函数的实现
void itostr(int num, char str[])
{
    if(num==0){
        str[0]='0',str[1]='\0';
        return ;
    }
    if(num<0){
        str[0]='-';
        str[(int)(log10(-num))+2]='\0'; 
        if(abs(num/10))
            itostr(num/10,str);
        str[(int)(log10(-num))+1] = abs(num%10)+'0';
    }
    if(num>0){
        str[(int)(log10(num)+1)]='\0';
        if(num/10)
            itostr(num/10,str);
        str[(int)(log10(num))]=num%10+'0';
    }
}
int main()
{
    int t,num;
    char str[SIZE];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &num);
        itostr(num,str);
        printf("%s\n",str);
    }
}