#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity" << endl;
        return 0;
    }
    if (t1 * a1 + t2 * a2 > t1 * b1 + t2 * b2) {
        swap(a1, b1);
        swap(a2, b2);
    }
    // 1回もすれ違わない
    if (t1 * a1 < t1 * b1) {
        cout << 0 << endl;
        return 0;
    }

    // 1周でできる差
    ll d = (t1 * b1 + t2 * b2) - (t1 * a1 + t2 * a2);
    // t1 * a1 > t1 * b1 + n * d
    // t1 * a1 - t1 * b1 > n * d
    ll n = (t1 * a1 - t1 * b1) / d;
    ll result = 0;
    if (n * d == (t1 * a1 - t1 * b1)) {
        result--;
    }
    result += n * 2 + 1;
    cout << result << endl;
}