#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    for (char &c : s) {
        if (c == 'a') continue;
        if ('z' - c + 1 <= k) {
            k -= 'z' - c + 1;
            c = 'a';
        }
    }
    if (k > 0) {
        s[s.size() - 1] = ((s[s.size() - 1] - 'a') + k) % 26 + 'a';
    }
    cout << s << endl;
}
