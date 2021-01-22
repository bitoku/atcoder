#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct city {
    int x;
    int y;
    int population;
};

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

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

int xydist(int x, const set<int>& line) {
    auto it = line.lower_bound(x);
    if (it == line.end()) return x - (*(--it));
    if (*it == x) return 0;
    if (it == line.begin()) return (*it) - x;
    int a = (*it) - x;
    int b = x - (*(--it));
    return min(a, b);
}

int main() {
    int N;
    cin >> N;
    vector<city> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].x >> v[i].y >> v[i].population;
    }
    ll first = 0;
    for (int i = 0; i < N; ++i) {
        first += min(abs(v[i].x), abs(v[i].y)) * v[i].population;
    }
    cout << first << endl;
    for (int K = 1; K <= N; ++K) {
        ll ans = first;
        // K = 1..=15
        foreach_comb(N, K, [&](int *indexes) {
            // bit の最大値 0 = y, 1 = x
            const int limit = mod_pow(2, K, INT32_MAX);
            for (int j = 0; j < limit; ++j) {
                set<int> xline;
                set<int> yline;
                xline.insert(0);
                yline.insert(0);
                bitset<15> bit = bitset<15>(j);

                for (int i = 0; i < K; ++i) {
                    auto& p = v[indexes[i]];
                    if (bit[i]) xline.insert(p.x);
                    else yline.insert(p.y);
                }

                ll temp = 0;
                for (int i = 0; i < N; ++i) {
                    temp += min(xydist(v[i].x, xline), xydist(v[i].y, yline)) * v[i].population;
                }
                ans = min(temp, ans);
            }
        });
        cout << ans << endl;
    }
}
