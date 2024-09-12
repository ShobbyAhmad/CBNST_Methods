#include<stdio.h>
#include<math.h>
//#define f(x) 2* x -(logx/log(10)-7)
double f(double x){
  return  2* x -(log(x) / log(10)- 7);
}
double diff(double x){
  return  1 / (2* x  * log(10));
}
double xformf(double x){
  return  ((log(x)) / log(10)+ 7) / 2;
}
int steps =0;
void calliterative(double x, float allowerror){
  x= xformf(x);
  steps++;
  printf("%d iteration and the value of x is : %f : %f\n",steps,x);
  if(fabs(f(x))<=allowerror)
  return ;
  calliterative(x,allowerror);
}

int main(){
double x, allowerror;

printf("Enter the initial value:");
scanf("%lf",&x);

if(diff(x) < 1){
    printf("input is satisfying the condiition.\n");
    printf("\nEnter the allowed error :" );
    printf("%f", &allowerror);
    printf("\n");

  calliterative(x, allowerror);
}else
    printf("oops invalid input!!!");

    return 0;

}
