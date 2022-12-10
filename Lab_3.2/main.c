#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double times;
double f(double x);
double method_hord(double x1, double x2, double eps, int N, int variant);
double method_of_halving(double x1, double x2, double eps, int N, int variant);

int main() {

  double Time;
  int Method;
  double x1, x2, root;
  double eps=0.000001;
  int variant;
  int N=200;

  do{
        system("cls");
        printf("\n display results on each iteration?");
        printf("\n Yes-0");
        printf("\n No-1");
        printf("\n variant=");
        scanf("%d", &variant);
    } while(variant != 0 && variant != 1);

    do{
        system("cls");
        printf("\n x1=");
        scanf("%lf", &x1);
        printf("\n x2=");
        scanf("%lf", &x2);
        break;
    }
    while(f(x1)>0 && f(x2)>0 || f(x1)<0 && f(x2)<0);

    do{
        system("cls");
        printf("\n   1 - method hord");
        printf("\n   2 - method of halving");
        printf("\n Enter method:\n");
        scanf("%d", &Method);
    }
    while(Method != 1 && Method != 2);

   Time = clock();
    if (Method == 1)
  {
      root = method_hord(x1, x2, eps, N, variant);
      system("cls");
    printf("\n x = %lf  f(x) = %lf", root, f(root));
  }
    else
  {
      root = method_of_halving(x1, x2, eps, N, variant);
      system("cls");
    printf("\n x = %lf  f(x) = %lf", root, f(root));
  }
printf("\n Times = %f Sec\n\n", ((clock() - Time)-times)/1000);
    return 0;
}
double f(double x)
{
    return -4 * pow(x,3) - 3 * pow(x,2) + 2 * pow(x,2) - 5 * x - 25;

}

double method_hord(double x1, double x2, double eps, int N, int variant)
{
double xi;
double t1, t2;
int n = 1;
int vibor;
int r = 1;
times = 0;

do {
    xi = (f(x2)*x1-f(x1)*x2) / (f(x2)-f(x1));
    if(f(xi)>0 && f(x1)>0 || f(xi)<0 && f(x1)<0)
    {
     x1 = xi;
    }
    else
    {
     x2 = xi;
    }
    if (variant == 0)
    {
        printf("\n n = %d  xi = %lf  f(xi) = %lf", n, xi, f(xi));
    }
    n++;
    if (N==n)
    {
        t1 = clock();
        do {
        printf("\n   1 - continue with the same number of iterations;");
        printf("\n   2 - execute the program to the end until the roots are found equation;");
        printf("\n   3 - exit the program, displaying the received message before exiting intermediate calculation result;");
        printf("\n Enter vash vibor:\n");
        scanf("%d", &vibor);
        }while(vibor != 1 && vibor != 2 && vibor != 3);
        t2 = clock() - t1;
        times = times + t2;
        if(vibor==1)
        {
            N = n+200;
        }
        else if(vibor==3)
        {
            r = 2;
        }
    }
   }while(fabs(f(xi) > eps) && r == 1);
return xi;
}


double method_of_halving(double x1, double x2, double eps, int N, int variant)
{
double xi;
double t1, t2;
int n = 1;
int vibor;
int r = 1;
times=0;

do {
    xi = (x1+x2)/2;
    if(f(xi)>0 && f(x1)<0 || f(xi)<0 && f(x1)>0)
    {
     x2 = xi;
    }
    else
    {
     x1 = xi;
    }
    if (variant == 0)
    {
        printf("\n n = %d  xi = %lf  f(xi) = %lf", n, xi, f(xi));
    }
    n++;
    if (N==n)
    {
        t1 = clock();
        do {
        printf("\n   1 - continue with the same number of iterations;");
        printf("\n   2 - execute the program to the end until the roots are found equation;");
        printf("\n   3 - exit the program, displaying the received message before exiting intermediate calculation result;");
        printf("\n Enter vash vibor:\n");
        scanf("%d", &vibor);
        }while(vibor != 1 && vibor != 2 && vibor != 3);
        t2 = clock() - t1;
        times = times + t2;
        if(vibor==1)
        {
            N = n+200;
        }
        else if(vibor==3)
        {
            r = 2;
        }
    }
   }while((x2 - x1) >= eps && r == 1);
return xi;
}
