#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll s, t;
    cin >> s >> t;
    ll result = 0;
    for (int a = 0; a <= s; ++a) {
        for (int b = 0; a + b <= s; ++b) {
            for (int c = 0; a + b + c <= s; ++c) {
                if (a * b * c <= t) result++;
            }
        }
    }
    cout << result << endl;
}