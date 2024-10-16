#include<stdio.h>
int main(){
    int a,b;
    int arr1[1000],arr2[1000],arr3[2000];
    scanf("%d",&a);
    for(int i=0; i<a; i++){
        scanf("%d",&arr1[i]);
        getchar();
    }
    scanf("%d",&b);
    for(int i=0; i<b; i++){
        scanf("%d",&arr2[i]);
        getchar();
    }
    // printf("????");
    int ina=0,inb=0,inc=0;
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            if(arr1[i]>arr1[j]){
                arr1[i]^=arr1[j];
                arr1[j]^=arr1[i];
                arr1[i]^=arr1[j];
            }
        }
    }
    for(int i=0; i<b; i++){
        for(int j=0; j<b; j++){
            if(arr2[i]>arr2[j]){
                arr2[i]^=arr2[j];
                arr2[j]^=arr2[i];
                arr2[i]^=arr2[j];
            }
        }
    }
    while(ina<a||inb<b){
        if(ina<a&&inb<b){
            if(arr1[ina]>arr2[inb]){
                arr3[inc]=arr1[ina];
                ina++;
            }else if(arr2[inb]>arr1[ina]){
                arr3[inc]=arr2[inb];
                inb++;
            }else{
                while(arr1[ina]==arr1[++ina]);
                while(arr2[inb]==arr2[++inb]); 
                inc--;
            }
            inc++;
        }else if(ina<a){
            arr3[inc]=arr1[ina];
            ina++;
            inc++;
        }else{
            arr3[inc]=arr2[inb];
            inb++;
            inc++;
        }
    }
    if(inc==0){
        printf("NULL");
        return 0;
    }
    for(int i=0; i<inc; i++){
        printf("%d",arr3[i]);
        if(i!=inc-1) printf(" ");
    }
    return 0;
}