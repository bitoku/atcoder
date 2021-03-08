#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        ll temp = 0;
        for (int j = 0; j < n - i; ++j) {
            if (s[j] == s[i+j]) temp++;
            else {
                result = max(result, min(temp, (ll)i));
                temp = 0;
            }
        }
        result = max(result, min(temp, (ll)i));
    }
    cout << result << endl;
}
