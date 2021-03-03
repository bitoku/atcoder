#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool minus = false;
    ll result1 = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (!minus && sum <= 0) {
            result1 += -sum + 1;
            sum += -sum + 1;
        } else if (minus && sum >= 0) {
            result1 += sum + 1;
            sum += - sum - 1;
        }
        minus = !minus;
    }

    minus = true;
    ll result2 = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (!minus && sum <= 0) {
            result2 += -sum + 1;
            sum += -sum + 1;
        } else if (minus && sum >= 0) {
            result2 += sum + 1;
            sum += - sum - 1;
        }
        minus = !minus;
    }
    cout << min(result1, result2) << endl;
}
