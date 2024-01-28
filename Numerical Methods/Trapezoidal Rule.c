#include <stdio.h>
#include <math.h>

double f(double x) {
    // Example function: x^3 - x^2 + 2
    return pow(x, 3) - pow(x, 2) + 2;
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        s += 2 * f(a + i * h);
    }

    return (h / 2) * s;
}

int main() {
    double a = 1;
    double b = 2;
    int n = 6;
    double result = trapezoidalRule(a, b, n);
    printf("Result of the integral: %f\n", result);
    return 0;
}
