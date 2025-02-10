#include<bits/stdc++.h>
using namespace std;

void gaussJordan(vector<vector<double> >& A, vector<double>& B, vector<double>& X, double e) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        A[i].push_back(B[i]);
    }

    int i = 0;
    int iterationCount = 0;
    while (i < n) {
        iterationCount++;
        double pivot = A[i][i];

        if (pivot == 0) {
            cout << "Pivot element is zero, cannot proceed with Gauss-Jordan elimination." << endl;
            return;
        }

        int j = 0;
        while (j < n + 1) {
            A[i][j] /= pivot;
            j++;
        }

        j = 0;
        while (j < n) {
            if (i != j) {
                double factor = A[j][i];
                int k = 0;
                while (k < n + 1) {
                    A[j][k] -= factor * A[i][k];
                    k++;
                }
            }
            j++;
        }
        i++;
    }

    for (int i = 0; i < n; i++) {
        X[i] = A[i][n];
    }

    cout << "Number of iterations: " << iterationCount << endl;
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
    double e;
    cout << "Enter the tolerance value (e): ";
    cin >> e;

    gaussJordan(A, B, X, e);

    cout << "Solution vector (X):\n";
    for (int i = 0; i < X.size(); i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }

    return 0;
}
