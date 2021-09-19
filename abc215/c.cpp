#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ll k;
    cin >> k;
    for (int i = 0; i < k-1; ++i) {
        next_permutation(s.begin(), s.end());
    }
    cout << s << endl;
}