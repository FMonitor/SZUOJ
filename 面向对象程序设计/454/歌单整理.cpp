#include<bits/stdc++.h>
using namespace std;
class Song {
private:
    string singer;
    string title;
    int length;
public:
    Song() {
        cout << "constructor" << endl;
    }
    Song(string s, string t, int l) :singer(s), title(t), length(l) {
        cout << "constructor" << endl;
    }
    void sets(string s, string t, int l) {
        singer = s;
        title = t;
        length = l;
    }
    int getlen() {
        return length;
    }
    void print() {
        cout << singer << "'s song-" << title << " lasts for " << length << " minutes" << endl;
    }
    ~Song() {
        cout << "destructor" << endl;
    }
};
int Select(Song s[], int n) {
    int maxl = s[0].getlen();
    int it = 0;
    for (int i = 1; i < n; i++) {
        if (maxl < s[i].getlen()) {
            maxl = s[i].getlen();
            it = i;
        }
    }
    return it;
}

int main() {
    int n;
    cin >> n;
    Song s[n];
    for (int i = 0; i < n; i++) {
        string singer, t;
        int l;
        cin >> singer >> t >> l;
        s[i].sets(singer, t, l);
    }
    s[Select(s,n)].print();
    return 0;
}