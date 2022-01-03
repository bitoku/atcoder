#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool dp[10001];

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        for (int j = 10000 - p[i]; j >= 0; --j) {
            dp[j+p[i]] |= dp[j];
        }
    }
    ll cnt = 0;
    for (int i = 0; i <= 10000; ++i) {
        if (dp[i]) cnt++;
    }
    cout << cnt << endl;
}