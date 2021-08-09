#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

// TODO: 08/09

template< typename Monoid, typename OperatorMonoid>
struct LazySegmentTree {
    int n, size, height;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h,
                    const Monoid &M1, const OperatorMonoid OM0)
            : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
        size = 1;
        height = 0;
        while(size < n) {
            size <<= 1;
            height++;
        }
        data.assign(2 * size, M1);
        lazy.assign(2 * size, OM0);
    }

    void set(int k, const Monoid &x) {
        data[k + size] = x;
    }

    void build() {
        for(int k = size - 1; k > 0; --k) {
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if(lazy[k] != OM0) {
            lazy[2 * k] = h(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = apply(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid apply(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while(k >>= 1) data[k] = f(apply(2 * k), apply(2 * k + 1));
    }

    inline void thrust(int k) {
        for(int i = height; i > 0; --i) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        if(a >= b) return;
        thrust(a += size);
        thrust(b += size - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), ++l;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        if(a >= b) return M1;
        thrust(a += size);
        thrust(b += size - 1);
        Monoid L = M1, R = M1;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, apply(l++));
            if(r & 1) R = f(apply(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> one(n+1), ten(n+1);
    one[0] = 0; ten[0] = 1;
    for (int i = 0; i < n; ++i) {
        ten[i+1] = ten[i] * 10 % mod;
        one[i+1] = (ten[i] + one[i]) % mod;
    }
    LazySegmentTree<pair<ll, ll>, ll> lst(
            n,
            [&](pair<ll, ll> x, pair<ll, ll> y) {
                return make_pair((x.first * ten[y.second] % mod + y.first) % mod, x.second + y.second);
            },
            [&](pair<ll, ll> x, ll y) {
                if (y == 0) return x;
                return make_pair(y * one[x.second] % mod, x.second);
            },
            [&](ll x, ll y) {
                return y;
            },
            make_pair(0, 0),
            0
    );
    for (int i = 0; i < n; ++i) {
        lst.set(i, make_pair(1, 1));
    }
    lst.build();
    for (int i = 0; i < q; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        lst.update(l, r, d);
        cout << lst.query(0, n).first << endl;
    }
}
