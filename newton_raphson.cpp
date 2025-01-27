#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    //return x * exp(x) - 1;
    return x - 0.8 - 0.2 * sin(x);
}

double f_prime(double x) {
    //return exp(x) * (x + 1);
    return 1 - 0.2 * cos(x);
}

int main() {
    double x0, tolerance;
    int maxIterations;

    cout << "Enter initial guess (x0): ";
    cin >> x0;

    cout << "Enter error tolerance: ";
    cin >> tolerance;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;

    double x = x0;
    int iteration = 0;

    while (iteration < maxIterations) {
        double fx = f(x);
        double fx_prime = f_prime(x);

        double x_new = x - fx / fx_prime;

        if (fabs(x_new - x) < tolerance) {
            cout << "Root found: " << x_new << endl;
            cout << "Iterations: " << iteration + 1 << endl;
            cout << "Error: " << fabs(x_new - x) << endl;
            break;
        }

        x = x_new;
        iteration++;
    }

    if (iteration == maxIterations) {
        cout << "Solution did not converge within the maximum number of iterations." << endl;
    }

    return 0;
}
