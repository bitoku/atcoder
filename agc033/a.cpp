#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> cost(h, vector<int>(w, 10000));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j > 0 && a[i][j] == '.') {
                cost[i][j] = min(cost[i][j - 1] + 1, cost[i][j]);
            } else if (a[i][j] == '#') {
                cost[i][j] = 0;
            }
        }
        for (int j = w - 1; j >= 0; --j) {
            if (j < w - 1 && a[i][j] == '.') {
                cost[i][j] = min(cost[i][j + 1] + 1, cost[i][j]);
            } else if (a[i][j] == '#') {
                cost[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            if (i > 0 && a[i][j] == '.') {
                cost[i][j] = min(cost[i - 1][j] + 1, cost[i][j]);
            } else if (a[i][j] == '#') {
                cost[i][j] = 0;
            }
        }
        for (int i = h - 1; i >= 0; --i) {
            if (i < h - 1 && a[i][j] == '.') {
                cost[i][j] = min(cost[i + 1][j] + 1, cost[i][j]);
            } else if (a[i][j] == '#') {
                cost[i][j] = 0;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            result = max(result, cost[i][j]);
        }
    }
    cout << result << endl;
}
