#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll h, w;
    cin >> h >> w;
    vector<string> a(h+2);
    for (int i = 1; i <= h; ++i) {
        cin >> a[i];
        a[i] = "#" + a[i] + "#";
    }
    a[0] = string(w+2, '#');
    a[h+1] = string(w+2, '#');
    for (int i = 1; i <= h; ++i) {
        bool on = false;
        for (int j = 1; j <= w; ++j) {
            if (a[i][j] == '>') {
                on = true;
                continue;
            }
            if (a[i][j] != '.' && a[i][j] != '!') {
                on = false;
                continue;
            }
            if (on) {
                a[i][j] = '!';
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        bool on = false;
        for (int j = w; j >= 1; --j) {
            if (a[i][j] == '<') {
                on = true;
                continue;
            }
            if (a[i][j] != '.' && a[i][j] != '!') {
                on = false;
                continue;
            }
            if (on) {
                a[i][j] = '!';
            }
        }
    }
    for (int i = 1; i <= w; ++i) {
        bool on = false;
        for (int j = 1; j <= h; ++j) {
            if (a[j][i] == 'v') {
                on = true;
                continue;
            }
            if (a[j][i] != '.' && a[j][i] != '!') {
                on = false;
                continue;
            }
            if (on) {
                a[j][i] = '!';
            }
        }
    }
    for (int i = 1; i <= w; ++i) {
        bool on = false;
        for (int j = h; j >= 1; --j) {
            if (a[j][i] == '^') {
                on = true;
                continue;
            }
            if (a[j][i] != '.' && a[j][i] != '!') {
                on = false;
                continue;
            }
            if (on) {
                a[j][i] = '!';
            }
        }
    }

    vector<vector<ll>> v(h+2, vector<ll>(w+2));
    pair<int, int> start, goal;
    for (int i = 0; i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            v[i][j] = INT_MAX;
            if (a[i][j] == 'S') {
                start = make_pair(i, j);
                v[i][j] = 0;
            }
            if (a[i][j] == 'G') goal = make_pair(i, j);
        }
    }
    deque<pair<pair<int, int>, int>> dq;
    dq.emplace_back(start, 0);
    while (!dq.empty()) {
        auto [current, cost] = dq.front();
        dq.pop_front();
        auto [x, y] = current;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto [dx, dy]: dir) {
            if (a[x+dx][y+dy] == '.') {
                if (v[x+dx][y+dy] != INT_MAX) continue;
                v[x+dx][y+dy] = cost+1;
                dq.emplace_back(make_pair(x+dx, y+dy), cost+1);
            }
            if (a[x+dx][y+dy] == 'G') {
                cout << cost+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}