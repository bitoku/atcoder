#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll dp[51][2501];

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k = 0; k <= 2500; ++k) {
                if (x[i] + k <= 2500) {
                    dp[j + 1][x[i] + k] += dp[j][k];
                }
            }
        }
    }
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        result += dp[i][a * i];
    }
    cout << result << endl;
}
