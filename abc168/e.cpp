#include <iostream>
#include <set>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if(a < b) return gcd(b, a);
    long long r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long n;
    map<long long, pair<long long, pair<long long, long long>>> status;
    map<long long, set<long long>> match;
    multiset<pair<long long, pair<long long, long long>>> statusset;
    cin >> n;

    for (long long i=0; i<n; i++) {
        long long a, b, g;
        long long sign = 1;
        cin >> a >> b;
        if (a < 0) {
            a = -a;
            sign *= -1;
        }
        if (b < 0) {
            b = -b;
            sign *= -1;
        }
        g = gcd(a, b);
        a = a / g;
        b = b / g;
        status[i] = make_pair(sign, make_pair(a, b));
        cout << sign << ' ' <<  a << ' ' << b << endl;
        statusset.insert(make_pair(sign, make_pair(a, b)));
    }

    long long result = 0;
    for (long long i=0; i<n; i++) {
        long long sign = status[i].first;
        long long a = status[i].second.first;
        long long b = status[i].second.second;
        unsigned long cnt = (statusset.size()) - statusset.count(make_pair(-sign, make_pair(b, a))) - 1;
        cout << cnt << endl;
        result = (result + modpow(2, cnt, MOD)) % MOD;
        statusset.erase(status[i]);
    }

    cout << result << endl;
    return 0;
}
