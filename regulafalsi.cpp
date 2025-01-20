#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return cos(x) - x * exp(x);
}

int main() {
    double a, b, c, error;
    int iter = 0, maxIter;
    double tolerance;

    cout << "Enter the lower bound of the interval (a): ";
    cin >> a;
    cout << "Enter the upper bound of the interval (b): ";
    cin >> b;

    cout << "Enter the tolerance";
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    if (f(a) * f(b) >= 0) {
        cout << "The method requires that f(a) and f(b) have opposite signs." << endl;
        return 1;
    }

    while (iter < maxIter) {
        c = b - f(b) * (b - a) / (f(b) - f(a));
        error = fabs(f(c));

        if (error < tolerance) {
            break;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iter++;
    }

    cout << "Root: " << c << endl;
    cout << "Iterations: " << iter << endl;
    cout << "Error: " << error << endl;

    return 0;
}
