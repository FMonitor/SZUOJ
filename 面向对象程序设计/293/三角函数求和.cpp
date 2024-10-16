#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
/********** Write your code here! **********/
double sigma(double (*f)(double), double a, double b)
{
    double sum=0;
        for(double i = a; i <= b; i+=0.1)
            sum += (*f)(i);
    return sum;
}



/*******************************************/
int main()
{
	char s[20];
	double a, b;
	while (cin >> s >> a >> b)
	{
		if (!strcmp(s,"sin"))
			cout << sigma(sin, a, b) << endl;
		else if (!strcmp(s,"cos"))
			cout << sigma(cos, a, b) << endl;
		else 
			cout << sigma(tan, a, b) << endl;
	}
	return 0;
}