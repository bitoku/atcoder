#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

ll dp[1000001][2];

int main() {
    string s;
    cin >> s;
    vector<ll> n(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        n[i] = s[s.size() - i - 1] - '0';
    }
    ll result = 0;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 0; i < n.size(); ++i) {
        dp[i+1][0] = min(dp[i][0] + n[i], dp[i][1] + 10 - n[i]);
        dp[i+1][1] = min(dp[i][0] + n[i] + 1, dp[i][1] + 10 - n[i] - 1);
    }
    cout << dp[n.size()][0] << endl;
}
