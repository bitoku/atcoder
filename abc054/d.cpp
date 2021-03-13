#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Med {
    int a;
    int b;
    int c;
};

int dp[41][401][401] = {};

int main() {
    int n;
    cin >> n;
    vector<Med> med(n);
    int ma, mb;
    cin >> ma >> mb;
    for (int i = 0; i < n; ++i) {
        cin >> med[i].a >> med[i].b >> med[i].c;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 400; ++j) {
            for (int k = 0; k <= 400; ++k) {
                dp[i][j][k] = INT_MAX / 2;
            }
        }
        dp[i][0][0] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 400; ++j) {
            for (int k = 0; k <= 400; ++k) {
                dp[i+1][j][k] = dp[i][j][k];
                if (j - med[i].a < 0 || k - med[i].b < 0) continue;
                dp[i+1][j][k] = min(dp[i][j-med[i].a][k-med[i].b] + med[i].c, dp[i+1][j][k]);
            }
        }
    }
    int result = INT_MAX;
    for (int i = 1; max(i*ma, i*mb) <= 400; ++i) {
        if (dp[n][i*ma][i*mb] == INT_MAX / 2) continue;
        result = min(result, dp[n][i*ma][i*mb]);
    }
    if (result == INT_MAX) cout << -1 << endl;
    else cout << result << endl;
}

//int main() {
//    int n;
//    cin >> n;
//    vector<Med> med(n);
//    int ma, mb;
//    cin >> ma >> mb;
//    for (int i = 0; i < n; ++i) {
//        cin >> med[i].a >> med[i].b >> med[i].c;
//        med[i].a *= mb;
//        med[i].b *= ma;
//    }
//    ll n1 = n / 2;
//    ll n2 = n - n1;
//    map<ll, ll> h1;
//    for (int i = 1; i < (1 << n1); ++i) {
//        Med m = {};
//        for (int j = 0; j < n1; ++j) {
//            if (i & (1 << j)) {
//                m.a += med[j].a;
//                m.b += med[j].b;
//                m.c += med[j].c;
//            }
//        }
//        if (h1.find(m.a - m.b) != h1.end()) {
//            h1[m.a - m.b] = min(h1[m.a - m.b], m.c);
//        } else {
//            h1[m.a - m.b] = m.c;
//        }
//    }
//    map<ll, ll> h2;
//    for (int i = 1; i < (1 << n2); ++i) {
//        Med m = {};
//        for (int j = 0; j < n2; ++j) {
//            if (i & (1 << j)) {
//                m.a += med[j + n1].a;
//                m.b += med[j + n1].b;
//                m.c += med[j + n1].c;
//            }
//        }
//        if (h2.find(m.a - m.b) != h2.end()) {
//            h2[m.a - m.b] = min(h2[m.a - m.b], m.c);
//        } else {
//            h2[m.a - m.b] = m.c;
//        }
//    }
//    ll result = LONG_LONG_MAX;
//    for (const auto& [d, c] : h1) {
//        if (d == 0) {
//            result = min(result, c);
//        }
//        if (h2.find(-d) == h2.end()) continue;
//        result = min(result, c + h2[-d]);
//    }
//    if (h2[0] != 0) {
//        result = min(result, h2[0]);
//    }
//    if (result == LONG_LONG_MAX) cout << -1 << endl;
//    else cout << result << endl;
//}
