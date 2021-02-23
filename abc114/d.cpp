#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

void factorial(map<int, int>& fact, int n) {
    if (n == 0 || n == 1) return;
    int nn = n;
    while (nn % 2 == 0) {
        nn /= 2;
        fact[2]++;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (nn % i == 0) {
            nn /= i;
            fact[i]++;
        }
    }
    if (nn > 1) {
        fact[nn]++;
    }
}

int rec(const map<int, int>& fact, map<int, int>::iterator it, int mul) {
    if (it == fact.end()) {
        if (mul == 1) return 1;
        else return 0;
    }
    int result = 0;
    for (int i = 0; i <= (*it).second; ++i) {
        if (mul % (i + 1) != 0) continue;
        result += rec(fact, ++it, mul / (i+1));
        --it;
    }
    return result;
}

//int main() {
//    int n;
//    cin >> n;
//    map<int, int> fact;
//    for (int i = 1; i <= n; ++i) {
//        factorial(fact, i);
//    }
//    cout << rec(fact, fact.begin(), 75) << endl;
//}

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
        if (x >= 74) x75++;
        if (x >= 24) x25++;
        if (x >= 14) x15++;
        if (x >= 4) x5++;
        if (x >= 2) x3++;
    }
    cnt += x75;
    cnt += x25 * (x3 - 1);
    cnt += x15 * (x5 - 1);
    cnt += (x5 * (x5-1)) / 2 * (x3 - 2);
    cout << cnt << endl;
}
