#include<bits/stdc++.h>
using namespace std;

void gaussJordan(vector<vector<double> >& A, vector<double>& B, vector<double>& X, double e) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        A[i].push_back(B[i]);
    }

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < n + 1; j++) {
            A[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = A[j][i];
                for (int k = 0; k < n + 1; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        X[i] = A[i][n];
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (number of variables): ";
    cin >> n;

    vector<vector<double> > A(n, vector<double>(n));
    vector<double> B(n);

    cout << "Enter the augmented matrix (coefficients) row by row:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants (B):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<double> X(n, 0);
    double e = 1e-4;

    gaussJordan(A, B, X, e);

    cout << "Solution vector (X):\n";
    for (int i = 0; i < X.size(); i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }

    return 0;
}
