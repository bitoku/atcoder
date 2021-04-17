#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    if (n == 2) {
        cout << 1 << endl << 2 << endl << 3 << endl;
        return 0;
    }
    if (x == 2) {
        for (int i = 5; i <= 2 * n - 1; ++i) {
            cout << i << endl;
            if (i - 5 == n - 3) {
                cout << 4 << endl << 1 << endl << 2 << endl << 3 << endl;
            }
        }
        return 0;
    }
    vector<int> a;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if (x - 2 <= i && i <= x + 1) continue;
        a.push_back(i);
    }
    for (int i = 0; i < 2 * n - 5; ++i) {
        cout << a[i] << endl;
        if (i == n - 3) {
            cout << x - 2 << endl << x << endl << x + 1 << endl << x - 1 << endl;
        }
    }
}
