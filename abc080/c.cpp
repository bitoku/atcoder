#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int f[100][5][2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 2; ++k) {
                cin >> f[i][j][k];
            }
        }
    }
    int p[100][11];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> p[i][j];
        }
    }
    int pattern_max = 1024;
    ll result = LONG_LONG_MIN;
    for (int pat = 1; pat < pattern_max; ++pat) {
        bitset<10> pattern(pat);
        ll temp = 0;
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int t = 0; t < 10; ++t) {
                if (pattern[t] && f[i][t / 2][t % 2] == 1) c++;
            }
            temp += p[i][c];
        }
        result = max(result, temp);
    }
    cout << result << endl;
}
