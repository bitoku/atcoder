#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template< typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int size, height;
    vector<Monoid> seg;
    vector<OperatorMonoid> lazy;

    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid& OM0) :
    f(f), g(g), h(h), M1(M1), OM0(OM0) {
        size = 1;
        height = 0;
        while (size < n) {
            size <<= 1;
            height++;
        }
        seg.assign(2 * size, M1);
        lazy.assign(2 * size, OM0);
    }

    void set(int k, const Monoid &x) {
        seg[k + size] = x;
    }

    void build() {
        for (int k = size - 1; k > 0; --k) {
            seg[k] = f(seg[2 * k], seg[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if (lazy[k] != OM0) {
            lazy[2 * k] = h(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        }
        seg[k] = reflect(k);
        lazy[k] = OM0;
    }

    inline Monoid reflect(int k) {
        return lazy[k] == OM0 ? seg[k] : g(seg[k], lazy[k]);
    }

    inline void recalc(int k) {
        while (k >>= 1) seg[k] = f(reflect(2 * k), reflect(2 * k + 1));
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; --i) propagate(k >> i);
    }

    // 0-indexed
    // [a, b)
    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += size);
        thrust(b += size - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    // 0-indexed
    // [a, b)
    Monoid query(int a, int b) {
        thrust(a += size);
        thrust(b += size - 1);
        Monoid L = M1, R = M1;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, reflect(l++));
            if (r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return query(k, k + 1);
    }
};

int main() {
    ll w, n;
    cin >> w >> n;
    auto mx = [](ll a, ll b) {return max(a, b);};
    LazySegmentTree<ll> lst(w, mx, mx, mx, 0, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        ll k = lst.query(l, r);
        cout << k + 1 << endl;
        lst.update(l, r, k + 1);
    }
}