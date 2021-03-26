#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Random {
    mt19937 mt;

    Random() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int operator()(int a, int b) {
        uniform_int_distribution<int> dist(a, b-1);
        return dist(mt);
    }
    int operator()(int b) {
        return (*this)(0, b);
    }
};

struct Point {
    int x;
    int y;
};

int main() {
    int n = 100;
    vector<Point> p(n+1);
    Random rand;
    for (int i = 1; i <= n; ++i) {
        p[i].x = rand(i, 1500 - i + 1);
        p[i].y = rand(i, 1500 - i + 1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) < (i + j) * (i + j)) {
                cnt++;
            }
        }
    }
    while (cnt > 0) {
        int i = rand(1, n+1);
        int nx = rand(i, 1500 - i + 1);
        int ny = rand(i, 1500 - i + 1);
        int temp = cnt;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) < (i + j) * (i + j)) {
                temp--;
            }
            if ((nx - p[j].x) * (nx - p[j].x) + (ny - p[j].y) * (ny - p[j].y) < (i + j) * (i + j)) {
                temp++;
            }
        }
        if (temp > cnt) continue;
        p[i].x = nx;
        p[i].y = ny;
        cnt = temp;
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i].x << ' ' << p[i].y << endl;
    }
}
