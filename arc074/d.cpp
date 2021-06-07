#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, greater<>> pq;
    vector<ll> frontsum(1);
    for (int i = 0; i < n; ++i) {
        pq.push(a[i]);
        frontsum[0] += a[i];
    }
    for (int i = n; i < 3 * n; ++i) {
        frontsum.push_back(frontsum.back());
        pq.push(a[i]);
        frontsum.back() += a[i] - pq.top();
        pq.pop();
    }
    vector<ll> backsum(1);
    priority_queue<ll> pp;
    for (int i = 3 * n - 1; i >= 2 * n; --i) {
        pp.push(a[i]);
        backsum[0] += a[i];
    }
    for (int i = 2 * n - 1; i >= 0; --i) {
        backsum.push_back(backsum.back());
        pp.push(a[i]);
        backsum.back() += a[i] - pp.top();
        pp.pop();
    }
    ll result = LONG_LONG_MIN;
    for (int i = 0; i <= n; ++i) {
        result = max(result, frontsum[i] - backsum[n - i]);
    }
    cout << result << endl;
}