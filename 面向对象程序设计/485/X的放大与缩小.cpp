#include<bits/stdc++.h>
using namespace std;
class CXGraph {
private:
    int n;
public:
    CXGraph(int n) {
        this->n = n;
    }
    CXGraph operator++(int) {
        CXGraph temp = *this;
        if (this->n < 20) {
            this->n += 2;
        }

        return temp;
    }
    friend ostream& operator<<(ostream& os, const CXGraph& xGraph);
    CXGraph& operator++() {
        if (this->n < 20) {
            this->n += 2;
        }
        return *this;
    }
    CXGraph operator--(int) {
        CXGraph temp = *this;
        if(this->n > 1) {
            this->n -= 2;
        }
        return temp;
    }
    CXGraph& operator--() {
        if(this->n > 1) {
            this->n -= 2;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const CXGraph& xGraph) {
    for (int i = 0; i < (xGraph.n + 1) / 2; i++) {
        for (int j = 0; j < i; j++) {
            os << " ";
        }
        for (int j = 0; j < xGraph.n - 2 * i; j++) {
            os << "X";
        }
        // for (int j = 0; j < i; j++) {
        //     cout << ".";
        // }
        os << endl;
    }
    for (int i = (xGraph.n - 1) / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            os << " ";
        }
        for (int j = 0; j < xGraph.n - 2 * i; j++) {
            os << "X";
        }
        // for (int j = 0; j < i; j++) {
        //     os << ".";
        // }
        os << endl;
    }
    return os;
}

int main() {
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--) {
        cin >> command;
        if (command == "show++") {
            cout << xGraph++ << endl;
        }
        if (command == "++show") {
            cout << ++xGraph << endl;
        }
        if (command == "show--") {
            cout << xGraph-- << endl;
        }
        if (command == "--show") {
            cout << --xGraph << endl;
        }
        if (command == "show") {
            cout << xGraph << endl;
        }
    }
    return 0;
}

