#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1000000007;

bool base(int n, int m, const string& s) {
    ull result = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (result > ULONG_LONG_MAX / n) return false;
        result *= n;
        if (result > ULONG_LONG_MAX - s[i] - '0') return false;
        result += s[i] - '0';
        if (result > m) return false;
    }
    return true;
}

int main() {
    string x;
    cin >> x;
    int d = 0;
    for (char c : x) {
        d = max(d, c - '0');
    }
    ull m;
    cin >> m;
    int cnt = 0;
    for (int i = d+1;; ++i) {
        if (base(i, m, x)) {
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt << endl;
}
