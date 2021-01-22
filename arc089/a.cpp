#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point {
public:
int x;
int y;
Point(): x(0), y(0) {}
Point(int _x, int _y): x(_x), y(_y) {}
Point operator-(const Point& rhs) const;
int manhattan() const;
};

Point Point::operator-(const Point &rhs) const {
    return {this->x - rhs.x, this->y - rhs.y};
}

int Point::manhattan() const {
    return abs(this->x) + abs(this->y);
}

int main() {
    int n;
    cin >> n;
    vector<Point> ps(n+1);
    bool can_travel = true;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        int before_t = t;
        cin >> t >> ps[i].x >> ps[i].y;
        if (!can_travel) continue;
        int dist = (ps[i-1] - ps[i]).manhattan();
        if (dist <= (t - before_t) && dist % 2 == (t - before_t) % 2) {
            continue;
        }
        can_travel = false;
    }
    if (can_travel) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
