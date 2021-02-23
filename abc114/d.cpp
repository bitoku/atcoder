#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

void factorial(map<int, int>& fact, int n) {
    if (n == 0 || n == 1) return;
    int lim = (int)sqrt(n) + 10;
    while (n % 2 == 0) {
        n /= 2;
        fact[2]++;
    }
    for (int i = 3; i <= lim; i += 2) {
        while (n % i == 0) {
            n /= i;
            fact[i]++;
        }
    }
    if (n > 1) {
        fact[n]++;
    }
}

int main() {
    int n;
    cin >> n;
    map<int, int> fact;
    for (int i = 1; i <= n; ++i) {
        factorial(fact, i);
    }
    ll cnt = 0;
    ll x75=0, x25=0, x15=0, x5=0, x3=0;
    for (const auto p : fact) {
        int x = p.second;
        if (x >= 74) {
            x75++;
        } else if (x >= 24) {
            x25++;
        } else if (x >= 14) {
            x15++;
        } else if (x >= 4) {
            x5++;
        } else if (x >= 2) {
            x3++;
        }
    }
    cnt += x75;
    x25 += x75;
    cnt += x25 * (x25 + x15 + x5 + x3 - 1);
    x15 += x25;
    cnt += x15 * (x15 + x5 - 1);
    x5 += x15;
    cnt += (x5 * (x5-1)) / 2 * (x5 + x3 - 2);
    cout << cnt << endl;
}
