#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int domestic_inversion = 0;
    int foreign_inversion = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) {
                domestic_inversion++;
                foreign_inversion++;
            } else if (a[j] > a[i]) {
                foreign_inversion++;
            }
        }
    }
    ll d = (domestic_inversion * k) % mod;
    ll f = (((k * (k - 1) / 2) % mod) * foreign_inversion) % mod;
    cout << (d + f) % mod << endl;
}
