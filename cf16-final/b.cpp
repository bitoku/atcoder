#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int x = 1;
    while ((1 + x) * x / 2 < n) {
        x++;
    }
    int skip = (1 + x) * x / 2 - n;
    for (int i = 1; i <= x; ++i) {
        if (i == skip) continue;
        cout << i << endl;
    }
}

//int main() {
//    int n;
//    cin >> n;
//    vector<int> dp(n+1);
//    dp[1] = 1;
//    dp[2] = 2;
//    int m = 2;
//    for (int i = 3; i <= n; ++i) {
//        if (dp[i - m] >= m) {
//            dp[i] = m + 1;
//        } else {
//            dp[i] = m;
//        }
//        m = dp[i];
//    }
//    int x = dp[n];
//    while (n > 0) {
//        cout << x << endl;
//        n = n - x;
//        x = dp[n];
//    }
//}
