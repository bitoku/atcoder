#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
void printVector(vector<T> &a) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<set<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    vector<set<int>> tree2 = tree;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(make_pair(tree[i].size(), i));
    }
    vector<bool> done(n);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        auto x = pq.top(); pq.pop();
        int j = x.second;
        while (done[j]) {
            x = pq.top(); pq.pop();
            j = x.second;
        }
        result[j] = c[i];
        for (const auto k : tree[j]) {
            tree[k].erase(j);
            pq.push(make_pair(tree[k].size(), k));
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (const auto x : tree2[i]) {
            ans += min(result[i], result[x]);
        }
    }
    cout << ans / 2 << endl;
    printVector(result);
}
