#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < n; ++i) {
        m[s[i]]++;
    }
    int result = 0;
    if (m['R'] % 2 == 1) result++;
    if (m['G'] % 2 == 1) result++;
    if (m['B'] % 2 == 1) result++;
    cout << result << endl;
}
