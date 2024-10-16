#include<bits/stdc++.h>
using namespace std;
class Television {
private:
    int mode;
    int volume;
    int channel;
    static int tvNum;
    static int dvdNum;
public:
    Television() {}
    Television(int c) {
        channel = c;
        mode = 1;
        volume = 50;
    }
    void friend control(Television& t, int m, int c, int v,int id);
    static void init(int n) {
        tvNum = n;
        dvdNum = 0;
    }
    static void dvd() {
        dvdNum++;
        tvNum--;
    }
    static void tv() {
        dvdNum--;
        tvNum++;
    }
    void print() {
        if (mode == 1) {
            cout << "TV";
        } else {
            cout << "DVD";
        }
        cout << "模式--频道" << channel << "--音量" << volume << endl;
    }
    static int gettv(){
        return tvNum;
    }
    static int getdvd(){
        return dvdNum;
    }
};
int Television::tvNum = 0;
int Television::dvdNum = 0;

void control(Television& t, int m, int c, int v, int id) {
    if (t.mode != m) {
        if (m == 1) {
            Television::tv();
        } else {
            Television::dvd();
        }
    }
    t.mode = m;
    t.channel = c;
    t.volume += v;
    t.volume = t.volume <= 100 ? t.volume : 0;
    t.volume = t.volume >= 0 ? t.volume : 0;
    cout << "第" << id << "号电视机";
    t.print();
}

int main() {
    int n;
    cin >> n;
    Television::init(n);
    Television* tel = new Television[n];
    for (int i = 0; i < n; i++) {
        tel[i] = Television(i);
    }
    int t;
    cin >> t;
    while (t--) {
        int id, m, c, v;
        cin >> id >> m >> c >> v;
        control(tel[id], m, c, v, id);
    }
    cout << "播放电视的电视机数量为" << Television::gettv() << endl;
    cout << "播放DVD的电视机数量为" << Television::getdvd() << endl;
    return 0;
}