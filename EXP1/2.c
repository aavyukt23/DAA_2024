#include <stdio.h>
#include <math.h>

// Function to find the roots of a quadratic equation
void find_roots_of_quadratic_equation(int a, int b, int c) {
    // Calculate the discriminant
    float discriminant = b * b - 4 * a * c;
    
    // Case 1: Real and different roots (discriminant > 0)
    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different: %.2f and %.2f\n", root1, root2);
    }
    // Case 2: Real and same roots (discriminant == 0)
    else if (discriminant == 0) {
        float root = -b / (2 * a);
        printf("Roots are real and same: %.2f\n", root);
    }
    // Case 3: Complex roots (discriminant < 0)
    else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

int main() {
    int a, b, c;
    
    // Input the coefficients of the quadratic equation
    printf("Enter the coefficients a, b, and c of the quadratic equation ax^2 + bx + c = 0: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Call the function to find the roots
    find_roots_of_quadratic_equation(a, b, c);
    
    return 0;
}
