#include <stdio.h>
#include <math.h>

double f(double x) {
    // Example function: x^4 - 2x + 1
    return pow(x, 4) - 2*x + 1;
}

double simpsonsRule(double a, double b, int n) {
    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        s += 4 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        s += 2 * f(a + i * h);
    }

    return s * h / 3;
}

int main() {
    double a = 0;
    double b = 1;
    int n = 6; // Should be even
    double result = simpsonsRule(a, b, n);
    printf("Result of the integral: %f\n", result);
    return 0;
}
