#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> p[i];
    }
    vector<int> sum1(n+1), sum2(n+2);
    for (int i = 0; i < n; ++i) {
        if (c[i] == 1) {
            sum1[i+1] = sum1[i] + p[i];
            sum2[i+1] = sum2[i];
        } else {
            sum1[i+1] = sum1[i];
            sum2[i+1] = sum2[i] + p[i];
        }
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sum1[r+1] - sum1[l] << ' ' << sum2[r+1] - sum2[l] << endl;
    }
}