#include<bits/stdc++.h>
using namespace std;
class Proc {
private:
    int pid;
    string username;
    char auth;
    int time;
    static int totalRtime;
    static int totalWtime;
    static int maxWtime;
    static int maxRcount;
public:
    Proc(){}
    Proc(int p, string n, char a, int t) {
        pid = p;
        username = n;
        auth = a;
        time = t;
    }
    void display() {
        cout << "PID-" << pid << " User-" << username << " as a ";
        if (auth == 'R') {
            cout << "reader used time-" << time << endl;
        } else {
            cout << "writer used time-" << time << endl;
        }
    }
    static void count(Proc p[], int n) {
        for (int i = 0; i < n; i++) {
            if (p[i].auth == 'R') {
                totalRtime += p[i].time;
            } else {
                totalWtime += p[i].time;
            }
        }
    }
    static int getcount(char t) {
        if (t == 'R') {
            return totalRtime;
        } else {
            return totalWtime;
        }
    }
    static int Mcount(Proc p[], int n) {
        for (int i = 0; i < n; i++) {
            if (p[i].auth == 'W' && maxWtime < p[i].time ) {
                maxWtime = p[i].time;
            }
        }
        return maxWtime;
    }
    static int Ncount(Proc p[], int n) {
        int length = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].auth == 'R') {
                length++;
                continue;
            }
            maxRcount = max(maxRcount, length);
            length = 0;
        }
        return maxRcount;
    }
};
int Proc::totalRtime = 0;
int Proc::totalWtime = 0;
int Proc::maxRcount = 0;
int Proc::maxWtime = 0;
int main() {
    freopen("out.txt", "w", stdout);
    int pid;
    string name;
    char auth;
    int t;
    Proc p[10000];
    int i = 0;
    while (i+1) {
        cin >> pid;
        if (pid == 0) break;;
        cin >> name >> auth >> t;
        p[i] = Proc(pid, name, auth, t);
        p[i].display();
        i++;
    }
    cout << endl;
    Proc::count(p,i);
    cout << "Total readers' time-" << Proc::getcount('R') << " with maximum " << Proc::Ncount(p, i) << " readers at the same time\n";
    cout << "Total writers' time-" << Proc::getcount('W') << " with maximum writing time "<<Proc::Mcount(p,i)<<endl;
}