 #include <stdio.h>
#include <math.h>


#define f(x) ((x)*(x)*(x) - 3*(x) + 1) // Example: f(x) = x^3 - 3x + 1

int main() {
    float x0, x1, x2, f0, f1, f2, error;
    int step = 1;

    printf("Enter the first initial guess (x0): ");
    scanf("%f", &x0);
    printf("Enter the second initial guess (x1): ");
    scanf("%f", &x1);
    printf("Enter the tolerance error: ");
    scanf("%f", &error);

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0.0) {
        printf("Initial guesses do not enclose the root.\n");
        return -1; 
    }

    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\tx2\t\tf(x2)\n");
    printf("------------------------------------------------------------------------\n");
  
    do {
        // Secant formula: x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2); 

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, f0, x1, f1, x2, f2);

        if (fabs(f2) < error) {
            break;
        }

        step++;
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }
    } while (fabs(f2) > error); 

    printf("\nThe root of the equation is: %.6f\n", x2);

    return 0;
}
