#include <stdio.h>
#include <math.h>

double f(double x) {
    // Example function: x^2 - 4
    return x*x - 4;
}

double df(double x) {
    // Derivative of the function: 2x
    return 2*x;
}

double newtonRaphson(double initialGuess, double tol) {
    double x = initialGuess;
    double h = f(x) / df(x);

    while (fabs(h) >= tol) {
        h = f(x) / df(x);
        x = x - h;
    }

    return x;
}

int main() {
    double initialGuess = 1.0;
    double tol = 0.0001;
    double root = newtonRaphson(initialGuess, tol);
    printf("Root found at: %f\n", root);
    return 0;
}
