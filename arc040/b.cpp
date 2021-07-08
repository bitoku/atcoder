#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    ll result = 0;
    int last = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '.') {
            last = max(last, max(0, i - r + 1));
            result++;
            for (int j = 0; j < r && i - j >= 0; ++j) {
                s[i-j] = 'o';
            }
        }
    }
    cout << result + last << endl;
}