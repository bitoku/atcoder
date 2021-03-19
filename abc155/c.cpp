#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }
    vector<string> longs;
    int lenmax = 0;
    for (const auto& [s, x] : m) {
        if (x > lenmax) {
            longs.clear();
            lenmax = x;
            longs.push_back(s);
        } else if (x == lenmax) {
            longs.push_back(s);
        }
    }
    for (const auto& s : longs) {
        cout << s << endl;
    }
}
