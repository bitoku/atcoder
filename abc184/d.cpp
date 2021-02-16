#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    double prob[101][101][101];
    cin >> a >> b >> c;
    prob[a][b][c] = 1;
    for (int i = a; i <= 100; ++i) {
        for (int j = b; j <= 100; ++j) {
            for (int k = c; k <= 100; ++k) {
                if (i == a && j == b && k == c) continue;
                prob[i][j][k] = 0;
                if (i > 0 && j < 100 && k < 100) {
                    prob[i][j][k] += prob[i-1][j][k] * (i - 1);
                }
                if (i < 100 && j > 0 && k < 100) {
                    prob[i][j][k] += prob[i][j-1][k] * (j - 1);
                }
                if (i < 100 && j < 100 && k > 0) {
                    prob[i][j][k] += prob[i][j][k-1] * (k - 1);
                }
                prob[i][j][k] /= (i + j + k - 1);
            }
        }
    }
    double exp = 0;
    for (int i = b; i < 100; ++i) {
        for (int j = c; j < 100; ++j) {
//            printf("100 %d %d %lf %d\n", i, j, prob[100][i][j], 100 + i + j - a - b - c);
            exp += prob[100][i][j] * (100 + i + j - a - b - c);
        }
    }
    for (int i = a; i < 100; ++i) {
        for (int j = c; j < 100; ++j) {
//            printf("%d 100 %d %lf %d\n", i, j, prob[i][100][j], 100 + i + j - a - b - c);
            exp += prob[i][100][j] * (100 + i + j - a - b - c);
        }
    }
    for (int i = a; i < 100; ++i) {
        for (int j = b; j < 100; ++j) {
//            printf("%d %d 100 %lf %d\n", i, j, prob[i][j][100], 100 + i + j - a - b - c);
            exp += prob[i][j][100] * (100 + i + j - a - b - c);
        }
    }
    cout << setprecision(15) << exp << endl;
}
