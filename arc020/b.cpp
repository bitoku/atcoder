#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i == j) continue;
            ll temp = 0;
            for (int k = 0; k < n; ++k) {
                if (k % 2 == 0 && a[k] == i) continue;
                if (k % 2 == 1 && a[k] == j) continue;
                temp += c;
            }
            result = min(result, temp);
        }
    }
    cout << result << endl;
}