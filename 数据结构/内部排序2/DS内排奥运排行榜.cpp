#include<bits/stdc++.h>
using namespace std;

struct country {
    int gold;
    int total;
    double avgold;
    double avgtot;

}c[448];

bool gold(country a, country b) {
    if (a.gold > b.gold) {
        return 1;
    }
    return 0;
}

bool total(country a, country b) {
    if (a.total > b.total) {
        return 1;
    }
    return 0;
}

bool avgold(country a, country b) {
    if (a.avgold > b.avgold) {
        return 1;
    }
    return 0;
}

bool avgtot(country a, country b) {
    if (a.avgtot > b.avgtot) {
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int gold, total, popu;
        cin >> gold >> total >> popu;
        c[i].gold = gold;
        c[i + 224].gold = gold;
        c[i].total = total;
        c[i + 224].total = total;
        c[i].avgold = double(gold) / popu;
        c[i + 224].avgold = c[i].avgold;
        c[i].avgtot = double(total) / popu;
        c[i + 224].avgtot = c[i].avgtot;
    }
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        int lvl = 0, method = 1;
        sort(c, c + n, gold);
        for (int j = 0; j < n; j++) {

            if (c[j].gold == c[query + 224].gold) {
                lvl = j + 1;
            }
        }
        sort(c, c + n, total);
        for (int j = 0; j < n; j++) {
            if (c[j].gold == c[query + 224].gold && lvl > j + 1) {
                lvl = j + 1, method = 2;
            }
        }
        sort(c, c + n, avgold);
        for (int j = 0; j < n; j++) {
            if (c[j].gold == c[query + 224].gold && lvl > j + 1) {
                lvl = j + 1, method = 3;
            }
        }
        sort(c, c + n, avgtot);
        for (int j = 0; j < n; j++) {
            if (c[j].gold == c[query + 224].gold && lvl > j + 1) {
                lvl = j + 1, method = 4;
            }
        }

        cout << lvl << ":" << method;
        if (i != m - 1)cout << " ";
    }
    return 0;
}