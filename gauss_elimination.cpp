#include <bits/stdc++.h>
using namespace std;

void swapRows(vector<vector<double> >& augmentedMatrix, int row1, int row2) {
    for (int i = 0; i < augmentedMatrix[0].size(); ++i) {
        swap(augmentedMatrix[row1][i], augmentedMatrix[row2][i]);
    }
}

void gaussElimination(vector<vector<double> >& augmentedMatrix, vector<double>& result) {
    int n = augmentedMatrix.size();

    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(augmentedMatrix[k][i]) > abs(augmentedMatrix[maxRow][i])) {
                maxRow = k;
            }
        }
        if (i != maxRow) {
            swapRows(augmentedMatrix, i, maxRow);
        }

        for (int j = i + 1; j < n; ++j) {
            double factor = augmentedMatrix[j][i] / augmentedMatrix[i][i];
            for (int k = i; k < n + 1; ++k) {
                augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
            }
        }
    }

    result.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        result[i] = augmentedMatrix[i][n] / augmentedMatrix[i][i];
        for (int j = i - 1; j >= 0; --j) {
            augmentedMatrix[j][n] -= augmentedMatrix[j][i] * result[i];
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of variables (equations): ";
    cin >> n;

    vector<vector<double> > augmentedMatrix(n, vector<double>(n + 1));
    vector<double> result(n);

    cout << "Enter the augmented matrix (including the right-hand side values):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cin >> augmentedMatrix[i][j];
        }
    }

    gaussElimination(augmentedMatrix, result);

    cout << "Solution: \n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }

    return 0;
}


