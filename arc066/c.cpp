#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll result = 1;
    if (n % 2 == 1) {
        if (a[0] != 0) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = 1; i < n; i += 2) {
            if (a[i] == i+1 && a[i+1] == i+1) {
                result = (result << 1) % mod;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        for (int i = 0; i < n; i += 2) {
            if (a[i] == i+1 && a[i+1] == i+1) {
                result = (result << 1) % mod;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << result << endl;
}
