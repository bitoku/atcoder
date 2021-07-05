#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<ll> a(26);
    for (char c : s) {
        a[c - 'a']++;
    }
    ll oddCnt = 0;
    ll evenSum = 0;
    for (auto x: a) {
        if (x % 2 == 1) oddCnt++;
        evenSum += x / 2 * 2;
    }
    if (oddCnt == 0) {
        cout << s.size() << endl;
        return 0;
    }
    cout << (evenSum - (evenSum % (2 * oddCnt))) / oddCnt + 1 << endl;
}