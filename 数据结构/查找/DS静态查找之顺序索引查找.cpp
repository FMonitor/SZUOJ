#include<bits/stdc++.h>
using namespace std;

struct block {
    int key;
    int start;
    int end;
};
vector<block> a;
vector<int> arr;
void printblock() {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].key << " " << a[i].start << " " << a[i].end << endl;
    }
}
void search(int target) {
    int times = 0;
    int section_l;
    int section_r;
    for (int i = 1; i < a.size(); i++) {
        times++;
        if (target <= a[i].key) {
            section_l = a[i].start;
            section_r = a[i].end;
            break;
        }
    }
    for(int i=section_l;i<=section_r;i++){
        times++;
        if(target==arr[i]){
            cout << i+1 << "-" << times << endl;
            return;
        }
    }
    cout << "error" << endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int index_cnt;
    cin >> index_cnt;
    a.push_back({0, -1});
    for (int i = 0,j=0; i < index_cnt; i++) {
        int key;
        cin >> key;
        int start = j;
        int end;
        while(arr[j]<=key){
            j++;
        }
        end = j - 1;
        a.push_back({key, start, end});
    }
    
    int t;
    cin >> t;
    while (t--) {
        int target;
        cin >> target;
        // cout << target << " ";
        search(target);
    }
    // printblock();
    return 0;
}