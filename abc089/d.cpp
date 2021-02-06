#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Point {
    int x;
    int y;
};

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<Point> ps(h * w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int a;
            cin >> a;
            a--;
            ps[a] = {j, i};
        }
    }
    vector<ll> dist(h * w);
    for (int i = d; i < h * w; ++i) {
        dist[i] = abs(ps[i].x - ps[i-d].x) + abs(ps[i].y - ps[i-d].y) + dist[i-d];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << dist[r] - dist[l] << endl;
    }
}
