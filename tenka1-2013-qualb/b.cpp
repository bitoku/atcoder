#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll q, l;
    cin >> q >> l;
    vector<pair<ll, ll>> stack;
    vector<ll> size = {0};
    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
        if (query == "Push") {
            ll n, m;
            cin >> n >> m;
            stack.emplace_back(m, n);
            size.push_back(n + size.back());
            if (size.back() > l) {
                cout << "FULL" << endl;
                return 0;
            }
        } else if (query == "Pop") {
            ll n;
            cin >> n;
            ll rest = size.back() - n;
            if (rest < 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            pair<ll, ll> tmp;
            while (size.back() > rest) {
                size.pop_back();
                tmp = stack.back(); stack.pop_back();
            }
            if (rest - size.back() == 0) continue;
            tmp.second = rest - size.back();
            size.push_back(rest);
            stack.push_back(tmp);
        } else if (query == "Top") {
            if (stack.empty()) {
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << stack.back().first << endl;
        } else if (query == "Size") {
            cout << size.back() << endl;
        }
    }
    cout << "SAFE" << endl;
}
