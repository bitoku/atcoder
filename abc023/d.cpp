#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

bool check(const vector<pair<int, int>>& balloon, ll border) {
    vector<ll> t;
    for (auto b: balloon) {
        if (border < b.first) {
            return false;
        }
        t.push_back((border - b.first) / b.second);
    }
    sort(t.begin(), t.end());
    for (int i=0;i<t.size();i++) {
        if (t[i] < i) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    ll right = LLONG_MAX;
    ll left = 0;
    vector<pair<int, int>> balloon;
    cin >> n;
    for (int i=0;i<n;i++) {
        ll h, s;
        cin >> h >> s;
        balloon.push_back(make_pair(h, s));
    }
    while (right - left > 1) {
        ll x = (right + left) / 2;
        if (check(balloon, x)) {
            right = x;
        } else {
            left = x;
        }
    }
    cout << right << endl;

    return 0;
}
