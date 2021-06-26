#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ld eps = 1e-6;

struct Point {
    ld x;
    ld y;
};

ld length(Point& p, Point& q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<Point> s(n);
    vector<Point> t(n);
    Point sg = {};
    Point tg = {};
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].y;
        sg.x += s[i].x;
        sg.y += s[i].y;
        s[i].x *= n;
        s[i].y *= n;
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i].x >> t[i].y;
        tg.x += t[i].x;
        tg.y += t[i].y;
        t[i].x *= n;
        t[i].y *= n;
    }
    for (int i = 0; i < n; ++i) {
        s[i].x -= sg.x;
        s[i].y -= sg.y;
        t[i].x -= tg.x;
        t[i].y -= tg.y;
    }
    // s[0]がt[i]に一致する
    Point p = s[0];
    // s[0]が重心と一致するときs[1]
    if (abs(p.x) < eps && abs(p.y) < eps) {
        p = s[1];
    }
    for (int i = 0; i < n; ++i) {
        auto q = t[i];
        ld angle = atan2(q.y, q.x) - atan2(p.y, p.x);
        bool match = true;
        for (int j = 0; j < n; ++j) {
            Point r = {s[j].x * cos(angle) - s[j].y * sin(angle), s[j].x * sin(angle) + s[j].y * cos(angle)};
            bool find = false;
            for (int k = 0; k < n; ++k) {
                if (abs(r.x - t[k].x) < eps && abs(r.y - t[k].y) < eps) find = true;
            }
            match &= find;
        }
        if (match) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}