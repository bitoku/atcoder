#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    set<string> sub;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; j <= k; ++j) {
            sub.insert(s.substr(i, j));
        }
    }
    auto it = sub.begin();
    for (int i = 0; i < k-1; ++i) {
        it++;
    }
    cout << *it << endl;
}
