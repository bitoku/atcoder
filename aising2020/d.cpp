#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

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

class Mod {
public:
    int n;
    int f[200000] = {0};
    explicit Mod(int _n): n(_n) {
        if (n == 1) {
            f[0] = 0;
        } else {
            f[0] = 1;
        }
        for (int i = 1; i < 200000; ++i) {
            f[i] = 2 * f[i-1] % n;
        }
    }
    int r(const bitset<200000>& bit) {
        int result = 0;
        for (int i = 0; i < 200000; ++i) {
            if(bit[i]) result = (result + f[i]) % n;
        }
        return result;
    }
};


int main() {
    int n;
    cin >> n;
    bitset<200000> bit;
    cin >> bit;
    int p = bit.count();
    Mod rpm(p-1 > 0 ? p - 1 : 1);
    Mod rpM(p+1);

    int xm = rpm.r(bit);
    int xM = rpM.r(bit);
    for (int i = n-1; i >= 0; --i) {
        int k;
        if (p == 1 && bit[i]) {
            cout << 0 << endl;
            continue;
        }
        if (bit[i]) {
            k = (p - 1 + xm - rpm.f[i]) % (p - 1);
        } else {
            k = (xM + rpM.f[i]) % (p + 1);
        }
        int cnt = 1;
        while (k > 0) {
            k = k % __builtin_popcount(k);
            cnt++;
        }
        cout << cnt << endl;
    }
}
