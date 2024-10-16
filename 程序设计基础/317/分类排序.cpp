#include<bits/stdc++.h>
using namespace std;
int arr[10],n,cmp;
void out(){
    for(int i=0; i<10; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return ;
}
void bubble(){
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(arr[i]>arr[j]) std::swap(arr[i],arr[j]);
        }
    }
    // out();
}
int main(){
    std::cin >> n;
    while(n--){
        for(int i=0; i<10; i++) std::cin >> arr[i];
        std::cin >> cmp;
        if(cmp%2==1){
            for(int i=0; i<10; i++){
                if(cmp==arr[i]){
                    bubble();
                    for(int j=0; j<10; j++){
                        if(cmp==arr[j]) continue;
                        std::cout << arr[j] <<" ";
                    }
                    std::cout << std::endl;
                    goto B;
                }
            }
        }
        else if(cmp%2==0){
            for(int i=0; i<10; i++){
                if(arr[i]==cmp) goto A;
            }
            bubble();
            bool flag=0;
            for(int i=9; i>=0; i--){
                if(arr[i]<cmp && flag==0){
                    flag=1;
                    std:: cout << cmp <<" ";
                }
                std::cout <<arr[i]<<" ";
            }
            std::cout << std::endl;
            goto B;
        }
        A:bubble();
        for(int i=9; i>=0; i--){
            if(arr[i]%2){
                std::cout <<arr[i]<<" ";
            }
        }
        for(int i=9; i>=0; i--){
            if(arr[i]%2==0){
                std::cout <<arr[i]<<" ";
            }
        }
        if(n!=1)std::cout << std::endl;
        B:cmp=0;
    }
    return 0;


}