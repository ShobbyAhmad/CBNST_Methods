#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Input from the user
    float arr[n][n + 1];
    printf("\nEnter the values in the augmented matrix (including the constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%f", &arr[i][j]);
        }
    }
    // Applying Gauss-Jordan Elimination
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        if (arr[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j][i] != 0) {
                    // Swap rows i and j
                    for (int k = 0; k < n + 1; k++) {
                        float temp = arr[i][k];
                        arr[i][k] = arr[j][k];
                        arr[j][k] = temp;
                    }
                    break;
                }
            }
        }

        // Making the diagonal element 1 and making the rest of the elements in the column 0
        float diag = arr[i][i];
        for (int j = 0; j < n + 1; j++) {
            arr[i][j] /= diag;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                float ratio = arr[j][i];
                for (int k = 0; k < n + 1; k++) {
                    arr[j][k] -= ratio * arr[i][k];
                }
            }
        }
    }
    printf("\nReduced Row Echelon Form (RREF) is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%0.2f\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nRESULT:\n");
    for (int i = 0; i < n; i++) {
        printf("The value of x%d = %0.2f\n", i, arr[i][n]);
    }

    return 0;
}
