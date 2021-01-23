#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    bool even = true;
    ll result = 0;
    ll minimum = 1000000001;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) even = !even;
        result += abs(a[i]);
        minimum = min(minimum, abs(a[i]));
    }
    if (even) {
        cout << result << endl;
    } else {
        cout << result - 2 * minimum << endl;
    }
}
