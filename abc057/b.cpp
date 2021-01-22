#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point {
public:
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int _x, int _y): x(_x), y(_y) {}
    Point operator-(const Point&) const;
    int manhattan() const;
};

Point Point::operator-(const Point &p) const {
    return {this->x - p.x, this->y - p.y};
}

int Point::manhattan() const {
    return abs(this->x) + abs(this->y);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> students(n);
    vector<Point> checkpoints(m);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].x >> students[i].y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> checkpoints[i].x >> checkpoints[i].y;
    }
    for (int i = 0; i < n; ++i) {
        int nearest = -1;
        int close_dist = 1000000000;
        for (int j = 0; j < m; ++j) {
            int dist = (students[i] - checkpoints[j]).manhattan();
            if (dist < close_dist) {
                nearest = j;
                close_dist = dist;
            }
        }
        cout << nearest + 1 << endl;
    }
}
