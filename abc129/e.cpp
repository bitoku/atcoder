#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

ll dp[2][100010];

int main() {
    string l;
    cin >> l;
    reverse(l.begin(), l.end());
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 0; i < l.size(); ++i) {
        dp[1][i+1] = 3 * dp[1][i] % mod;
        if (l[i] == '0') {
            dp[0][i+1] = dp[0][i] % mod;
        } else {
            dp[0][i+1] = (2 * dp[0][i] + dp[1][i]) % mod;
        }
    }
    cout << dp[0][l.size()] << endl;
}
