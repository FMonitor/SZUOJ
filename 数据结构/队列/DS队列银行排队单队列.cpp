#include <bits/stdc++.h>
using namespace std;

struct client {
    double arrivetime;
    double processtime;
    double start;
    double end;
    double waittime;
    int vip;
    int skip;
}cl[1001];

struct windows {
    int count;
    int avaliable;
    double end;
}win[11];

int main() {
    memset(cl, 0, sizeof(cl));
    memset(win, 0, sizeof(win));
    int n, k, arrivetime, processtime, vip;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arrivetime >> processtime >> vip;
        if (processtime > 60) processtime = 60;
        cl[i].arrivetime = arrivetime;
        cl[i].processtime = processtime;
        cl[i].vip = vip;
    }
    int v;
    cin >> k >> v;
    for (int i = 0;i < k;i++) win[i].avaliable = 1;
    int count = 0;
    int m=0;
    while (1) {
        if (count == n) break;
        for (int i = 0;i < k;i++) {
            if (win[i].end == m) {
                win[i].avaliable = 1;
            }
        }
        if (win[v].avaliable == 1) {
            for (int i = 0;cl[i].arrivetime <= m && i < n;i++) {
                if (cl[i].skip == 1) continue;
                if (cl[i].vip == 1) {
                    cl[i].skip = 1;
                    cl[i].start = m;
                    cl[i].end = cl[i].start + cl[i].processtime;
                    cl[i].waittime = cl[i].start - cl[i].arrivetime;
                    win[v].avaliable = 0;
                    win[v].end = m + cl[i].processtime;
                    count++;
                    win[v].count++;
                    break;
                }
            }
        }
        for (int i = 0;i < k;i++) {
            if (win[i].avaliable == 1) {
                for (int j = 0;j < n && cl[j].arrivetime <= m;j++) {
                    if (cl[j].skip == 1) continue;
                    cl[j].start = m;
                    cl[j].end = cl[j].start + cl[j].processtime;
                    cl[j].skip = 1;
                    cl[j].waittime = cl[j].start - cl[j].arrivetime;
                    win[i].avaliable = 0;
                    win[i].count++;
                    win[i].end = m + cl[j].processtime;
                    count++;
                    break;
                }
            }
        }
        m++;
    }
    double sum = 0;
    int maxwaittime = -1, last = -1;
    for (int i = 0;i < n;i++) {
        sum += cl[i].waittime;
        if (cl[i].waittime > maxwaittime) {
            maxwaittime = cl[i].waittime;
        }
        if (cl[i].end > last) {
            last = cl[i].end;
        }
    }
    cout << fixed<<setprecision(1)<< sum / n<<" "<< maxwaittime<<" " <<last<<endl;
    for (int i = 0;i < k;i++) {
        cout << win[i].count;
        if (i != k - 1) cout << " ";
    }
    return 0;
}
