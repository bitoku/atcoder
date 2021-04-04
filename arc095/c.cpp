#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> sorted(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        sorted[i] = x[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
        if (x[i] <= sorted[n / 2 - 1]) {
            cout << sorted[n / 2] << endl;
        } else {
            cout << sorted[n / 2 - 1] << endl;
        }
    }
}
