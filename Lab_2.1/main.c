#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
 double x, y;

 printf("Enter x:");
 scanf("%lf", &x);

 if (x >= -100 && x < -50)
    y = -x;
  else if (x >= 50 && x < 100)
    y = x;
  else if (x >= 200 && x < 1000 )
    y = log10(x)+1;
  else
    y = 0.0;

 system("cls");
 printf("x = %lf", x);
 printf("\ny = %lf", y);

 return 0;
}
