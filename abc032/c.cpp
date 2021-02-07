#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    bool zero = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) zero = true;
    }
    if (zero) {
        cout << n << endl;
        return 0;
    }
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    int left = 0;
    int result = 0;
    ll temp = 1;
    for (int right = 0; right < n; ++right) {
        temp *= a[right];
        while (temp > k) {
            temp /= a[left];
            left++;
        }
        result = max(result, right - left + 1);
    }
    cout << result << endl;
}
