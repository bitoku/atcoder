#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    // x_1, x_2, x_3, ... x_n
    // sum[i = 1 -> n - 1]( sum[j = i + 1 -> n] (|x_i - x_j|))
    // sum[i = 1 -> n - 1]( sum[j = i + 1 -> n] (x_j - x_i))
    // sum[i = 1 -> n - 1]( sum[j = i + 1 -> n] (x_j) - (n - i) * (x_i))
    // sum[i = 1 -> n - 1]( s[n] - s[i] - (n - i) * (x_i))
    // (n - 1) * s[n] - sum[i = 1 -> n - 1](s[i]) - sum[i = 1 -> n - 1](n * x_i - i * x_i))
    // (n - 1) * s[n] - n * s[n-1] + sum[i = 1 -> n - 1](i * x_i - s[i])
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = x[i] + s[i];
    }
    ll result = (n - 1) * s[n] - n * s[n-1];
    for (int i = 1; i <= n - 1; ++i) {
        result += i * x[i-1] - s[i];
    }
    cout << result << endl;
}
