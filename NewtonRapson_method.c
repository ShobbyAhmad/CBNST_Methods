#include<stdio.h>
#include<math.h>

#define f(x) x*x*x-3*x
#define g(x) 3*x*x-3

int main(){
  float x0,x1,f0,f1,g0,err;
  int step=1;
  printf("enter the value of x0:\n");
  scanf("%f",&x0);

  printf("enter tolerence error:\n");
  scanf("%f",&err);

  printf("\nsteps\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

do{

  g0= g(x0);
  f0 = f(x0);

  x1 = x0-f0/g0;
  f1 = f(x1);
  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
  x0=x1;
  step++;

}while(fabs(f1) > err);

  printf("\nRoot is: %f",x1);
  return 0;
}
