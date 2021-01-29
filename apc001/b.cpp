#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    ll asum = 0;
    ll bsum = 0;
    ll add_required_a = 0;
    ll add_required_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        asum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        bsum += b[i];
        if (b[i] > a[i]) {
            add_required_a += (b[i] - a[i]) / 2;
            if ((b[i] - a[i]) % 2 == 1) {
                add_required_b++;
            }
        } else {
            add_required_b += a[i] - b[i];
        }
    }
    ll diff = bsum - asum;
    if (diff < 0 || max(add_required_a, add_required_b) > diff) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
