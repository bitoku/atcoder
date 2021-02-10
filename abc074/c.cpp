#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

class Fraction {
    public:
        int dividend;
        int divisor;

        bool operator<(const Fraction& f) const {
            ll left_dividend = dividend * f.divisor;
            ll right_dividend = f.dividend * divisor;
            return left_dividend < right_dividend;
        }
};

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int water, sugar;
    Fraction m = {0, 100 * a};
    for (int i = 0; i <= f / (100 * a); ++i) {
        int rest = f - 100 * a * i;
        for (int j = 0; j <= rest / (100 * b); ++j) {
            if (i == 0 && j == 0) continue;
            water = i * a * 100 + j * b * 100;
            int max_sugar = min(water / 100 * e, f - (100 * a * i) - (100 * b * j));
            for (int k = 0; k <= max_sugar / c; ++k) {
                sugar = k * c + (max_sugar - k * c) / d * d;
//                cout << i << ' ' << j << ' ' << k << ' ' << (max_sugar - k * c) / d << ' ' << water + sugar << ' ' << sugar << endl;
                Fraction frac = {sugar, water + sugar};
                if (m < frac) {
                    m = frac;
                }
            }
        }
    }
    cout << m.divisor << ' ' << m.dividend << endl;
}
