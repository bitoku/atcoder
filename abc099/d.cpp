#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, C;
    cin >> n >> C;
    int c[500][500];
    ll d[30][30];
    ll ccnt[3][30];
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
            c[i][j]--;
            ccnt[(i + j) % 3][c[i][j]]++;
        }
    }
    ll loss[3][30] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                loss[i][j] += ccnt[i][k] * d[k][j];
            }
        }
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                if (i == j || j == k || k == i) continue;
                result = min(result, loss[0][i] + loss[1][j] + loss[2][k]);
            }
        }
    }
    cout << result << endl;
}
