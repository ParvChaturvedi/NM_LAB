#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return sqrt(x) - cos(x);
}

double bis(double a, double b, double tol, int max_iter) {
    double c;

    if (f(a) * f(b) > 0) {
        cout << "Bisection method cannot be applied as the function has the same signs at a and b." << endl;
        return NAN;
    }

    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0) {
            break;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {
    double a, b, tol;
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance: ";
    cin >> tol;

    int max_iter = 20;
    double root = bis(a, b, tol, max_iter);

    if ((root)) {
        cout << "The root of the equation is approximately: " << setprecision(8) << root << endl;
    }

    return 0;
}
