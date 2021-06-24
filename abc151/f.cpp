#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ld eps = 1e-9;

// TODO: solve without editorial

struct Point {
    ld x;
    ld y;
};

template<class Condition>
ld binsearch(ld ng, ld ok, Condition func) {
    while (abs(ok - ng) > eps) {
        ld mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }
    auto func = [&](ld r) {
        vector<Point> inter;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ld k = sqrt((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y));
                ld cos = (v[j].x - v[i].x) / k;
                ld sin = (v[j].y - v[i].y) / k;
                Point norm = {-sin, cos};
                Point m = {(v[i].x + v[j].x) / 2, (v[i].y + v[j].y) / 2};
                ld l = sqrt(r * r - (k / 2) * (k / 2));
                inter.push_back({m.x + l * norm.x, m.y + l * norm.y});
                inter.push_back({m.x - l * norm.x, m.y - l * norm.y});
            }
        }
        for (auto& p: inter) {
            if (all_of(v.begin(), v.end(), [&](Point& q) { return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) <= r * r + eps;})) {
                return true;
            }
        }
        return false;
    };
    cout << setprecision(12) << binsearch(0, 2000, func) << endl;
}