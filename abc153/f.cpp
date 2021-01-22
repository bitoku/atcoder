#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<int, ll>> monster(N);
    vector<ll> damage(N);
    for (int i = 0; i < N; ++i) {
        int x;
        ll h;
        cin >> x >> h;
        monster[i] = make_pair(x, h);
    }
    ll ans = 0;
    sort(monster.begin(), monster.end());
    ll d = 0;
    for (int i = 0; i < N; ++i) {
        d -= damage[i];
        int x = monster[i].first;
        ll h = monster[i].second;
        h -= d;
        ll nbomb;
        if (h % A == 0) nbomb = h / A;
        else nbomb = h / A + 1;
        ans += nbomb;
        d += nbomb * A;
        if (i + 2 * D + 1 < N) damage[i + 2 * D + 1] += nbomb * A;
    }
    cout << ans << endl;
}
