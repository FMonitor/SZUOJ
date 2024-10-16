#include<stdio.h>
#include<math.h>
int n;
double a, b, c;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
         scanf("%lf %lf %lf", &a, &b, &c);
        if(a+b>c&&a+c>b&&b+c>a)
        {
            if(fabs(a*a+b*b-c*c)<0.001||fabs(a*a+c*c-b*b)<0.001||fabs(b*b+c*c-a*a)<0.001)
            {
                if(a==b||a==c||b==c)
                {
                    printf("isosceles right triangle, ");
                }
                else
                {
                    printf("right triangle, ");
                }
            }
            else if((a==b&&a!=c)||(a==c&&a!=b)||(c==b&&a!=c))
            {
                printf("isosceles triangle, ");
            }
            else if(a==b&&a==c&&b==c)
            {
                printf("equilateral triangle, ");
            }
            else
            {
                printf("general triangle, ");
            }
        }
        else
        {
            printf("no triangle\n");
            continue;
        }
        double p = (a + b + c) / 2;
        printf("%.1lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    }
    return 0;
}