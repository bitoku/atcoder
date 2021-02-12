#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> l(n+1, 0);
    vector<int> r(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l[i+1] = gcd(l[i], a[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        r[i] = gcd(r[i+1], a[i]);
    }

    int m = 0;
    for (int i = 0; i < n; ++i) {
        m = max(m, gcd(l[i], r[i+1]));
    }
    cout << m << endl;
}
