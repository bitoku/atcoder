#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> s(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        s[i] += s[i];
        s[n + i] = s[i];
    }
    vector<vector<int>> t(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                if (s[i][j+k] != s[i+k][j]) break;
                cnt++;
            }
            t[i][j] = cnt;
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok = true;
            for (int k = 0; k < n; ++k) {
                if (t[(i+k) % n][(j+k) % n] < n - k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result++;
            }
        }
    }
    cout << result << endl;
}
