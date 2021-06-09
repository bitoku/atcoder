#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n + 1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }
    for (int i = 0; i <= n; ++i) {
        s[i] = ((s[i] - i) % k + k) % k;
    }
    map<ll, ll> m;
    ll result = 0;
    for (int i = 0; i <= n && i < k; ++i) {
        result += m[s[i]];
        m[s[i]]++;
    }
    for (int i = k; i <= n; ++i) {
        m[s[i - k]]--;
        result += m[s[i]];
        m[s[i]]++;
    }
    cout << result << endl;
}