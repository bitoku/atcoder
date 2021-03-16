#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t;
    for (char c : s) {
        if (!t.empty() && t.back() == c) continue;
        t.push_back(c);
    }
    cout << t.size() << endl;
}
