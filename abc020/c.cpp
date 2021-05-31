#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll H, W, t;
    cin >> H >> W >> t;
    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s[i];
    }
    ll sh, sw, gh, gw;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (s[i][j] == 'S') {
                sh = i;
                sw = j;
            }
            if (s[i][j] == 'G') {
                gh = i;
                gw = j;
            }
        }
    }
    auto func = [&](ll x) {
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
        pq.push(make_tuple(0, sh, sw));
        vector<vector<ll>> dist(H, vector<ll>(W, -1));
        while (!pq.empty()) {
            auto [c, h, w] = pq.top(); pq.pop();
            if (dist[h][w] != -1) continue;
            dist[h][w] = c;
            if (h == gh && w == gw) break;
            if (h + 1 < H && dist[h+1][w] == -1) {
                ll cost = c;
                if (s[h+1][w] == '#') cost += x;
                else cost += 1;
                pq.push(make_tuple(cost, h+1, w));
            }
            if (h - 1 >= 0 && dist[h-1][w] == -1) {
                ll cost = c;
                if (s[h-1][w] == '#') cost += x;
                else cost += 1;
                pq.push(make_tuple(cost, h-1, w));
            }
            if (w + 1 < W && dist[h][w+1] == -1) {
                ll cost = c;
                if (s[h][w+1] == '#') cost += x;
                else cost += 1;
                pq.push(make_tuple(cost, h, w+1));
            }
            if (w - 1 >= 0 && dist[h][w-1] == -1) {
                ll cost = c;
                if (s[h][w-1] == '#') cost += x;
                else cost += 1;
                pq.push(make_tuple(cost, h, w-1));
            }
        }
        if (dist[gh][gw] == -1) return false;
        return dist[gh][gw] <= t;
    };
    cout << binsearch(INT_MAX, 1, func) << endl;
}