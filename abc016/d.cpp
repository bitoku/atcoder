#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Point {
    int x;
    int y;
};

bool intersect(Point &a, Point &b, Point &c, Point &d) {
    ll s, t, u, v;
    s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
    t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
    u = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
    v = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
    return s * t < 0 && u * v < 0;
}

int main() {
    Point a{}, b{};
    cin >> a.x >> a.y >> b.x >> b.y;
    int n;
    cin >> n;
    Point c[100];
    cin >> c[0].x >> c[0].y;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        cin >> c[i].x >> c[i].y;
        if (intersect(a, b, c[i-1], c[i])) cnt++;
    }
    if (intersect(a, b, c[0], c[n-1])) cnt++;
    cout << cnt / 2 + 1 << endl;
}
