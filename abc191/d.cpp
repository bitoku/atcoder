#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve

ll upper_sqrt(ll n) {
    ll left = 0, right = min(n, (ll)sqrt(LONG_LONG_MAX));
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll db = mid * mid;
        if (db <= n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

ll floor(ll n, ll m) {
    return n - (n % m + m) % m;
}

ll ceil(ll n, ll m) {
    return n + (m - n % m) % m;
}

int main() {
    string sx, sy, sr;
    ll x, y, r;
    cin >> sx >> sy >> sr;
    bool is_float = false;
    int keta = 0;
    for (char c : sx) {
        if (c == '.') {
            is_float = true;
            continue;
        }
        if (is_float) {
            keta++;
        }
        x = x * 10 + (c - '0');
    }
    for (int i = 0; i < 4 - keta; ++i) {
        x *= 10;
    }

    keta = 0;
    is_float = false;
    for (char c : sy) {
        if (c == '.') {
            is_float = true;
            continue;
        }
        if (is_float) {
            keta++;
        }
        y = y * 10 + (c - '0');
    }
    for (int i = 0; i < 4 - keta; ++i) {
        y *= 10;
    }

    keta = 0;
    is_float = false;
    for (char c : sr) {
        if (c == '.') {
            is_float = true;
            continue;
        }
        if (is_float) {
            keta++;
        }
        r = r * 10 + (c - '0');
    }
    for (int i = 0; i < 4 - keta; ++i) {
        r *= 10;
    }
    ll X = ceil(x - r, 10000);
    ll result = 0;
    for (; X <= x + r; X += 10000) {
        ll Ydiff = upper_sqrt(r * r - (X - x) * (X - x)) - 1;
        ll Ymax = floor(y + Ydiff, 10000);
        ll Ymin = ceil(y - Ydiff, 10000);
        result += (Ymax - Ymin) / 10000 + 1;
    }
    cout << result << endl;
}
