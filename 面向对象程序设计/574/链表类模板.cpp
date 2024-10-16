#include<bits/stdc++.h>
using namespace std;
class CNode

{

public:

int data;

CNode *next;

};

class CIntList

{

private:

CNode *head;

public:

CIntList();

void append(int a); //加到链表最后

void insert(int a, int n); //在第n个结点后加

void remove(int n); //移除第n个结点

int get(int n); //返回第n个结点的数据

void set(int a, int n); //将第n个节点的数据改成a

void print();

~CIntList();

};