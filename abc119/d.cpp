#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
typename vector<T>::iterator nearest_left(vector<T>& v, T x) {
    if (v.empty()) return v.end();
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.end()) return --it;
    if (*it == x) return it;
    if (it == v.begin()) return v.end();
    return --it;
}

template<class T>
typename vector<T>::iterator nearest_right(vector<T>& v, T x) {
    if (v.empty()) return v.end();
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.end()) return v.end();
    return it;
}

template<class T>
typename vector<T>::iterator nearest(vector<T>& v, T x) {
    auto lit = nearest_left<T>(v, x);
    auto rit = nearest_right<T>(v, x);
    if (lit == v.end()) {
        return rit;
    }
    if (rit == v.end()) {
        return lit;
    }
    if (x - *(lit) <= *(rit) - x) {
        return lit;
    }
    return rit;
}

int main() {
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    for (int i = 0; i < a; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < b; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        ll result = LONG_LONG_MAX;
        auto sit = nearest_left<ll>(s, x);
        if (sit != s.end()) {
            auto tit = nearest<ll>(t, *sit);
            if (tit != t.end()) {
                result = min(result, abs(x - *sit) + abs(*sit - *tit));
            }
        }
        sit = nearest_right<ll>(s, x);
        if (sit != s.end()) {
            auto tit = nearest<ll>(t, *sit);
            if (tit != t.end()) {
                result = min(result, abs(x - *sit) + abs(*sit - *tit));
            }
        }
        auto tit = nearest_left<ll>(t, x);
        if (tit != t.end()) {
            sit = nearest<ll>(s, *tit);
            if (sit != s.end()) {
                result = min(result, abs(x - *tit) + abs(*tit - *sit));
            }
        }
        tit = nearest_right<ll>(t, x);
        if (tit != t.end()) {
            sit = nearest<ll>(s, *tit);
            if (sit != s.end()) {
                result = min(result, abs(x - *tit) + abs(*tit - *sit));
            }
        }
        cout << result << endl;
    }
}
