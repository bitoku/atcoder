#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> valmap(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < h; ++i) {
        int left = 0;
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '.' && (j == 0 || s[i][j-1] == '#')) {
                left = j;
            }
            if (s[i][j] == '#') {
                if (j - 1 > 0 && s[i][j-1] == '.') {
                    for (int k = left; k < j; ++k) valmap[i][k] += j - left;
                }
            }
        }
        if (s[i][w-1] == '.') {
            for (int k = left; k < w; ++k) valmap[i][k] += w - left;
        }
    }
    for (int i = 0; i < w; ++i) {
        int left = 0;
        for (int j = 0; j < h; ++j) {
            if (s[j][i] == '.' && (j == 0 || s[j-1][i] == '#')) {
                left = j;
            }
            if (s[j][i] == '#') {
                if (j - 1 > 0 && s[j-1][i] == '.') {
                    for (int k = left; k < j; ++k) valmap[k][i] += j - left;
                }
            }
        }
        if (s[h-1][i] == '.') {
            for (int k = left; k < h; ++k) valmap[k][i] += h - left;
        }
    }
    int m = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            m = max(m, valmap[i][j]);
        }
    }
    cout << m - 1 << endl;
}
