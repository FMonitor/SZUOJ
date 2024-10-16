#include<bits/stdc++.h>
using namespace std;
template <class T>
void mysort(T* arr,int len) {
    sort(arr, arr + len);
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char type;
        cin >> type >> n;
        if (type == 'C') {
            char arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            for (int i = 0; i < n; i++) {
                std::cout << arr[i];
                std::cout << " ";
            }
        } else if (type == 'I') {
            int arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            for (int i = 0; i < n; i++) {
                std::cout << arr[i];
                std::cout << " ";
            }
        } else if (type == 'D') {
            double arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            for (int i = 0; i < n; i++) {
                std::cout << arr[i];
                std::cout << " ";
            }
        } else if (type == 'S') {
            string arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            mysort(arr, n);
            for (int i = 0; i < n; i++) {
                std::cout << arr[i];
                std::cout << " ";
            }
        }
        if(t!=0)std::cout << endl;
    }
    return 0;
}

