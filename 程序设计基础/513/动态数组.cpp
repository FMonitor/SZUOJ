#include<stdio.h>

void INT_type(int arr[],int size){
    double sum=0;
    for(int i=0; i<size; i++){
        sum+=*(arr+i);
    }
    printf("%g\n",sum/size);
    return;
}
void CHAR_type(char arr[],int size){
    char A='A';
    for(int i=0; i<size; i++){
        A= A>*(arr+i) ? A : *(arr+i);
    }
    printf("%c\n",A);
    return;
}
void DOUBLE_type(double arr[],int size){
    double minx=100000;
    for(int i=0; i<size; i++){
        minx=minx < *(arr+i) ? minx : *(arr+i);
    }
    printf("%g\n",minx);
    return;
}
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char a;
        int size;
        scanf("%c %d\n",&a,&size);
        // printf("!%c %d!\n",a,size)/;
        if(a=='I'){
            int *p = new int[size];
            for(int i=0; i<size; i++){
                if(i!=size-1) scanf("%d ",p+i);
                else scanf("%d\n",p+i);
            }
            INT_type(p,size);
        }else if(a=='C'){
            char *p = new char[size];
            for(int i=0; i<size; i++){
                if(i!=size-1) scanf("%c ",p+i);
                else scanf("%c\n",p+i);
            }
            CHAR_type(p,size);
        }else if(a=='F'){
            double *p = new double[size];
            for(int i=0; i<size; i++){
                if(i!=size-1) scanf("%lf ",p+i);
                else scanf("%lf",p+i);
            }
            DOUBLE_type(p,size);
            // printf("?????\n");
        }
    }
    return 0;
}