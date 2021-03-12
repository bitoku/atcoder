#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> b(n+2, string(m+2, '0'));
    vector<vector<int>> a(n+2, vector<int>(m+2, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] = '0' + b[i] + '0';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = b[i][j] - '0';
            if (x == 0) continue;
            x -= a[i][j-1];
            x -= a[i-1][j];
            x -= a[i][j+1];
            x -= a[i+1][j];
            if (x > 0) {
                a[i+1][j] = x;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
