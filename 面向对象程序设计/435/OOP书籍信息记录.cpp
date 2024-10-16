#include<bits/stdc++.h>
using namespace std;
class Document {
private:
    string name;
public:
    Document(string s) : name(s) {
        cout << "Create Document Class" << endl;
    }
    void print() {
        cout << "Document Name is " << name << endl;
    }
    ~Document() {
        cout << "Delete Document Class" << endl;
    }
};

class Book : public Document {
private:
    int page;
public:
    Book(int p, string s) :page(p), Document(s) {
        cout << "Create Book Class" << endl;
    }
    void Book_print() {
        print();
        cout << "PageCount is " << page << endl;
    }
    ~Book() {
        cout << "Delete Book Class" << endl;
    }
};

int main() {
    string s;
    int n;
    cin >> s >> n;
    Book b(n, s);
    b.Book_print();
    return 0;
}