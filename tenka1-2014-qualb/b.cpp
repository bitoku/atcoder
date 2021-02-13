#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<ll> dp(s.size()+1);
    dp[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + t[j].size() - 1 < s.size() && s.substr(i, t[j].size()) == t[j]) {
                dp[i+t[j].size()] = (dp[i+t[j].size()] + dp[i]) % mod;
            }
        }
    }
    cout << dp[s.size()] << endl;
}
