#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> d(n+1);
    vector<ll> rd(n+1);
    for (int i = 0; i < n; ++i) {
        ll v;
        cin >> d[i+1] >> v;
        a[i] = v;
        b[n - i - 1] = v;
    }
    for (int i = 0; i < n; ++i) {
        rd[n - i] = c - d[i + 1];
    }
    vector<ll> aa(n + 1);
    vector<ll> bb(n + 1);
    for (int i = 0; i < n; ++i) {
        aa[i+1] = a[i] + aa[i];
        bb[i+1] = b[i] + bb[i];
    }
    vector<ll> maa(n+1);
    vector<ll> mbb(n+1);
    for (int i = 0; i < n; ++i) {
        maa[i+1] = max(maa[i], aa[i+1] - d[i+1]);
        mbb[i+1] = max(mbb[i], bb[i+1] - rd[i+1]);
    }
    ll result = 0;
    for (int i = 0; i <= n; ++i) {
        result = max(aa[i] - 2 * d[i] + mbb[n - i], result);
        result = max(bb[i] - 2 * rd[i] + maa[n - i], result);
    }
    cout << result << endl;

}