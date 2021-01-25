#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Point {
    int x;
    int y;
};

struct State {
    bool inv;
    char xy;
    ll p;
};

int main() {
    int n, m;
    cin >> n;
    vector<Point> point(n);
    for (int i = 0; i < n; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    cin >> m;
    vector<State> x_states(m+1);
    vector<State> y_states(m+1);
    x_states[0].xy = 'x';
    y_states[0].xy = 'y';
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            x_states[i] = y_states[i-1];
            y_states[i] = x_states[i-1];
            y_states[i].inv = !y_states[i].inv;
            y_states[i].p = -y_states[i].p;
        } else if (op == 2) {
            y_states[i] = x_states[i-1];
            x_states[i] = y_states[i-1];
            x_states[i].inv = !x_states[i].inv;
            x_states[i].p = -x_states[i].p;
        } else if (op == 3) {
            int pp;
            cin >> pp;
            x_states[i] = x_states[i-1];
            x_states[i].inv = !x_states[i].inv;
            x_states[i].p = -x_states[i].p + 2 * pp;
            y_states[i] = y_states[i-1];
        } else if (op == 4) {
            int pp;
            cin >> pp;
            y_states[i] = y_states[i-1];
            y_states[i].inv = !y_states[i].inv;
            y_states[i].p = -y_states[i].p + 2 * pp;
            x_states[i] = x_states[i-1];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        Point qq = point[b-1];
        ll x, y;
        if (x_states[a].xy == 'x') {
            if (x_states[a].inv) {
                x = -qq.x + x_states[a].p;
            } else {
                x = qq.x + x_states[a].p;
            }
        } else if (x_states[a].xy == 'y') {
            if (x_states[a].inv) {
                x = -qq.y + x_states[a].p;
            } else {
                x = qq.y + x_states[a].p;
            }
        }
        if (y_states[a].xy == 'x') {
            if (y_states[a].inv) {
                y = -qq.x + y_states[a].p;
            } else {
                y = qq.x + y_states[a].p;
            }
        } else if (y_states[a].xy == 'y') {
            if (y_states[a].inv) {
                y = -qq.y + y_states[a].p;
            } else {
                y = qq.y + y_states[a].p;
            }
        }
        cout << x << ' ' << y << endl;
    }
}
