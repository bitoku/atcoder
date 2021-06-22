#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Tree {
    int parent;
    vector<int> children;
};

pair<ll, ll> dfs(vector<Tree>& tree, int cur) {
    vector<pair<ll, ll>> even, odd;
    for (int next: tree[cur].children) {
        auto p = dfs(tree, next);
        if ((p.first + p.second) % 2 == 0) {
            even.push_back(p);
        } else {
            odd.push_back(p);
        }
    }
    // 根をとったほう、違うほう
    pair<ll, ll> result = make_pair(1, 0);
    sort(even.begin(), even.end(), [](auto p, auto q) { return p.second - p.first > q.second - q.first; });
    sort(odd.begin(), odd.end(), [](auto p, auto q) { return p.second - p.first > q.second - q.first; });
    int i = 0;
    for (i = 0; i < even.size(); i++) {
        auto p = even[i];
        if (p.second < p.first) break;
        result.first += p.first;
        result.second += p.second;
    }
    for (int j = 0; j < odd.size(); ++j) {
        auto p = odd[j];
        if (j % 2 == 0) {
            result.first += p.first;
            result.second += p.second;
        } else {
            result.first += p.second;
            result.second += p.first;
        }
    }
    for (; i < even.size(); ++i) {
        auto p = even[i];
        if (odd.size() % 2 == 0) {
            result.first += p.first;
            result.second += p.second;
        } else {
            result.first += p.second;
            result.second += p.first;
        }
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    vector<Tree> tree(n);
    for (int i = 1; i < n; ++i) {
        cin >> tree[i].parent;
        tree[i].parent--;
        tree[tree[i].parent].children.push_back(i);
    }
    cout << dfs(tree, 0).first << endl;
}
