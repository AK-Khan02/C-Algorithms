#include <stdio.h>
#include <math.h>

double f(double x) {
    // Example function: x^3 - x - 2
    return pow(x, 3) - x - 2;
}

double bisectionMethod(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Incorrect initial interval [a,b]\n");
        return 0;
    }

    double c = a;
    while ((b-a) >= tol) {
        c = (a+b)/2;

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a = 1, b = 2, tol = 0.001;
    double root = bisectionMethod(a, b, tol);
    printf("Root found at: %f\n", root);
    return 0;
}
