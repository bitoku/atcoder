#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Point {
    ld x;
    ld y;
};

int main() {
    ld x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    ld result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ld s = ((x - p[j].x) * (p[i].x - p[j].x) + (y - p[j].y) * (p[i].y - p[j].y)) / ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
        if (0 <= s && s <= 1) {
            ld tx = s * p[i].x + (1 - s) * p[j].x;
            ld ty = s * p[i].y + (1 - s) * p[j].y;
            result = min(sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty)), result);
        } else {
            result = min({sqrt((x - p[i].x) * (x - p[i].x) + (y - p[i].y) * (y - p[i].y)),
                          sqrt((x - p[j].x) * (x - p[j].x) + (y - p[j].y) * (y - p[j].y)),
                          result});
        }
    }
    cout << setprecision(12) << result << endl;
}