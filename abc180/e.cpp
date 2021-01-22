#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 100000000000000ll;
ll dp[200000][17];
int N;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

struct point{
    int x;
    int y;
    int z;
};

ll cost(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + max(0, a.z - b.z);
}

point points[17];

ll rec(int S, int v) {
    if (S == 0) {
        if (v == 0) {
            return 0;
        } else {
            return INF;
        }
    }
    if ((S & (1 << v)) == 0) {
        return INF;
    }

    ll &ret = dp[S][v];
    if (ret != 0) return ret;

    ret = INF;
    for (int i = 0; i < N; ++i) {
        chmin(ret, rec(S ^ (1 << v), i) + cost(points[i], points[v]));
    }
    return ret;
}

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    cin >> N;
    ll lmt = mod_pow(2, N, INT_MAX);
    for (int i = 0; i < lmt; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    cout << rec((1 << N) - 1, 0) << endl;
}
