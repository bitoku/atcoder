#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    iota(c.begin(), c.end(), 1);
    ll cnt = 0;
    ll A = 0, B = 0;
    do {
        cnt++;
        if (equal(a.begin(), a.end(), c.begin(), c.end())) A = cnt;
        if (equal(b.begin(), b.end(), c.begin(), c.end())) B = cnt;
    } while (next_permutation(c.begin(), c.end()));
    cout << abs(A - B) << endl;
}
