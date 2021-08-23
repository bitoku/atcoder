#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/23

int main() {
    ll n;
    cin >> n;
    vector<ld> T(40001, INT_MAX);
    vector<int> t(n+1);
    vector<ld> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        t[i] *= 2;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int tt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = tt-1; j >= 0; --j) {
            T[j] = min(T[j], v[i] + (ld)(tt - j) / 2);
        }
        for (int j = tt; j <= tt+t[i]; ++j) {
            T[j] = min(T[j], v[i]);
        }
        for (int j = tt + t[i] + 1; j <= 40001; ++j) {
            T[j] = min(T[j], v[i] + (ld)(j - tt - t[i]) / 2);
        }
        tt += t[i];
    }
    for (int i = 0; i <= tt; ++i) {
        T[i] = min(T[i], (ld)i / 2);
        T[tt - i] = min(T[tt - i], (ld)i / 2);
    }
    ld result = 0;
    for (int i = 0; i < tt; ++i) {
        result += (T[i] + T[i+1]) / 4;
    }
    cout << setprecision(16) << result << endl;
}