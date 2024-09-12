#include<stdio.h>
#include<math.h>
//#define f(x) 3* x + sin (x) - exp (x);
double f(double x){
  return 3*x+sin(x)-exp(x);
}
void bisection(double a,double b,double tol, int max_iter){
  if(f(a) * f(b) >=0){
    printf("Error: f(a) and f(b) different signs.\n");
    return;
  }
  double c;
  int iter = 0;
  while ((b-a)/2> tol&&iter< max_iter){
    c= (a+b)/2;
if(f(c)==0.0){
  printf("Root found: %lf\n",c);
  return;
}
if(f(a)*f(c)<0){
  b=c;
}else{
  a=c;

}
iter++;
  }
printf("Approximate root: %lf\n",c);
printf("Number of iterations: %d\n",iter);
}
int main(){
double  a, b, tol;
int max_iter;

printf("Enter the interval [a,b]:");
scanf("%lf %lf",&a,&b);
printf("enter tolerence:");
scanf("%lf",&tol);
printf("Enter maximum iterations:");
scanf("%lf",&max_iter);
  
bisection(a,b,tol,max_iter);
return 0;
}

