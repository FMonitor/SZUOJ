#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0);
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //一行输出，无换行
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
};
//完成以下类定义的填空
/********** Write your code here! **********/
RMB::RMB(double a) {
    // cout <<"????" << a << endl;
    a *= 100;
    yuan = (int)a / 100;
    jiao = (int)a%100 / 10;
    fen = (int)a%10;
}
RMB::RMB(int a, int b, int c) {
    yuan = a;
    jiao = b;
    fen = c;
}
bool RMB::operator > (RMB& a) {
    if (this->yuan == a.yuan) {
        if(this->jiao == a.jiao) {
            return this->fen > a.fen;
        } else {
            return this->jiao > a.jiao;
        }
    }
    return this->yuan > a.yuan;
}
ostream& operator <<(ostream& os, RMB& r)
{
    os<<r.yuan<<"yuan"<<r.jiao<<"jiao"<<r.fen<<"fen";
    return os;
}
istream & operator >>(istream &is, RMB &r)
{
    is>>r.yuan>>r.jiao>>r.fen;
    return is;
}
RMB operator + (RMB& a, RMB& b) {
    int fen = a.fen + b.fen;
    int jiao = a.jiao + b.jiao;
    int yuan = a.yuan + b.yuan;
    if(fen >= 10) {
        jiao += fen / 10;
        fen %= 10;
    }
    if(jiao >= 10) {
        yuan += jiao / 10;
        jiao %= 10;
    }
    RMB result(yuan, jiao, fen);
    return result;
}


/*******************************************/
//主函数
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//输入一个浮点数，例如1.23 
		RMB r1(val_yuan); //例如上一行输入1.23，则生成对象r1是1元2角3分 
		RMB r2;
		cin>>r2;	//输入一行三个整数参数，按元、角、分输入 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 =r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}
