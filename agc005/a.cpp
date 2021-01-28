#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    string t;
    for (char i : s) {
        if (!t.empty() && t.back() == 'S' && i == 'T') {
            t.pop_back();
            continue;
        }
        t.push_back(i);
    }
    cout << t.size() << endl;
}
