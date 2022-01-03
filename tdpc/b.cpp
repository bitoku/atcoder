#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll dp[1001][1001];

int main() {
    int A, B;
    cin >> A >> B;
    vector<ll> a(A), b(B);
    vector<vector<ll>> sum(A+1, vector<ll>(B+1));
    for (int i = 0; i < A; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int j = 1; j <= B; ++j) {
        sum[0][j] = sum[0][j-1] + b[j-1];
    }
    for (int i = 1; i <= A; ++i) {
        sum[i][0] = sum[i-1][0] + a[i-1];
        for (int j = 1; j <= B; ++j) {
            sum[i][j] = sum[i][j-1] + b[j-1];
        }
    }
    for (int x = 1; x <= A + B; ++x) {
        for (int i = max(0, x-B); i <= min(x, A); ++i) {
            int j = x - i;
            if (i == 0) dp[i][j] = (sum[i][j-1] - dp[i][j-1]) + b[j-1];
            else if (j == 0) dp[i][j] = (sum[i-1][j] - dp[i-1][j]) + a[i-1];
            else dp[i][j] = max((sum[i][j-1] - dp[i][j-1]) + b[j-1], (sum[i-1][j] - dp[i-1][j]) + a[i-1]);
        }
    }
    cout << dp[A][B] << endl;
}