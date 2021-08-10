#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll H, W;
    cin >> H >> W;
    ll rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    vector<string> s(H + 2);
    s[0] = string(W+2, '#');
    s[H+1] = string(W+2, '#');
    for (int i = 1; i <= H; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    vector<vector<ll>> v[4];
    for (int i = 0; i < 4; ++i) {
        v[i].resize(H + 2, vector<ll>(W+2, -1));
    }
    priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<>> pq;
    pq.push(make_tuple(0ll, 0, rs, cs));
    pq.push(make_tuple(0ll, 1, rs, cs));
    pq.push(make_tuple(0ll, 2, rs, cs));
    pq.push(make_tuple(0ll, 3, rs, cs));
    vector<vector<vector<bool>>> done(4, vector<vector<bool>>(H+2, vector<bool>(W+2)));
    while (!pq.empty()) {
        auto [c, d, h, w] = pq.top(); pq.pop();
        if (h == rt && w == ct) {
            cout << c << endl;
            return 0;
        }
        if (done[d][h][w]) continue;
        done[d][h][w] = true;
        if (s[h-1][w] == '.') {
            ll cc = d == 0 ? c : c + 1;
            if (v[0][h-1][w] == -1 || v[0][h-1][w] > cc) {
                v[0][h-1][w] = cc;
                pq.push(make_tuple(cc, 0, h-1, w));
            }
        }
        if (s[h+1][w] == '.') {
            ll cc = d == 1 ? c : c + 1;
            if (v[1][h+1][w] == -1 || v[1][h+1][w] > cc) {
                v[1][h+1][w] = cc;
                pq.push(make_tuple(cc, 1, h+1, w));
            }
        }
        if (s[h][w-1] == '.') {
            ll cc = d == 2 ? c : c + 1;
            if (v[2][h][w-1] == -1 || v[2][h][w-1] > cc) {
                v[2][h][w-1] = cc;
                pq.push(make_tuple(cc, 2, h, w-1));
            }
        }
        if (s[h][w+1] == '.') {
            ll cc = d == 3 ? c : c + 1;
            if (v[3][h][w+1] == -1 || v[3][h][w+1] > cc) {
                v[3][h][w+1] = cc;
                pq.push(make_tuple(cc, 3, h, w+1));
            }
        }
    }
}