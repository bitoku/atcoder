#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> monsters(N);
    for (int i = 0; i < N; ++i) {
        cin >> monsters[i].first >> monsters[i].second;
    }
    sort(monsters.begin(), monsters.end());
    deque<pair<ll, ll>> bombs;
    ll bomb_sum = 0;
    ll result = 0;
    for (const auto [pos, hp] : monsters) {
        if (!bombs.empty()) {
            auto[lim, dam] = bombs.front();
            while (lim < pos) {
                bomb_sum -= dam;
                bombs.pop_front();
                if (bombs.empty()) break;
                lim = bombs.front().first;
                dam = bombs.front().second;
            }
        }
        ll rest = hp - bomb_sum;
        if (rest < 0) continue;
        ll x = (rest + A - 1) / A;
        result += x;
        bomb_sum += x * A;
        bombs.emplace_back(pos + 2 * D, x * A);
    }
    cout << result << endl;
}
