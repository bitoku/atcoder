#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    a--; b--;
    vector<ll> building(200, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push(make_pair(0, a));
    while (!pq.empty()) {
        auto [t, cnt] = pq.top(); pq.pop();
        if (building[cnt] != -1) continue;
        building[cnt] = t;
        if (cnt < 100) {
            // corridor
            if (cnt > 0 && building[cnt + 99] == -1) {
                pq.push(make_pair(t + x, cnt + 99));
            }
            if (building[cnt + 100] == -1) {
                pq.push(make_pair(t + x, cnt + 100));
            }

            if (cnt < 99 && building[cnt + 1] == -1) {
                pq.push(make_pair(t + y, cnt + 1));
            }
            if (cnt > 0 && building[cnt - 1] == -1) {
                pq.push(make_pair(t + y, cnt - 1));
            }
        }

        if (cnt >= 100) {
            if (cnt < 199 && building[cnt - 99] == -1) {
                pq.push(make_pair(t + x, cnt - 99));
            }
            if (building[cnt - 100] == -1) {
                pq.push(make_pair(t + x, cnt - 100));
            }
            if (cnt < 199 && building[cnt + 1] == -1) {
                pq.push(make_pair(t + y, cnt + 1));
            }
            if (cnt > 100 && building[cnt - 1] == -1) {
                pq.push(make_pair(t + y, cnt - 1));
            }
        }
    }
    cout << building[100 + b] << endl;
}
