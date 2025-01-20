#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x + 3*x*x -1;
}

int main() {
    double x0, x1, x2, error;
    int iter = 0, maxIter;
    double tolerance;

    cout << "Enter the first initial guess (x0): ";
    cin >> x0;
    cout << "Enter the second initial guess (x1): ";
    cin >> x1;

    cout << "Enter the tolerance: ";
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    while (iter < maxIter) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        error = fabs(f(x2));

        if (error < tolerance) {
            break;
        }

        x0 = x1;
        x1 = x2;

        iter++;
    }

    cout << "Root: " << x2 << endl;
    cout << "Iterations: " << iter << endl;
    cout << "Error: " << error << endl;

    return 0;
}

