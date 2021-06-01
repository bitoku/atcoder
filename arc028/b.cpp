#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        pq.push(make_pair(x, i+1));
    }
    cout << pq.top().second << endl;
    for (int i = k; i < n; ++i) {
        ll x;
        cin >> x;
        if (x < pq.top().first) {
            pq.pop();
            pq.push(make_pair(x, i+1));
        }
        cout << pq.top().second << endl;
    }
}