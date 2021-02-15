#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// 1-indexed
template< typename Monoid >
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int size;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2 * size, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + size] = x;
    }

    void build() {
        for (int k = size - 1; k > 0; --k) {
            seg[k] = f(seg[2 * k], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += size;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k], seg[2 * k + 1]);
        }
    }

    // [a, b)
    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + size];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> dp(n+1);
    SegmentTree<int> sg(300010, [](int a, int b) { return max(a, b);}, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]++;
        int x = sg.query(max(a[i]-k, 1), min(a[i]+k+1, 300005));
        sg.update(a[i], x+1);
    }
    cout << sg.query(1, 300010) << endl;
}
