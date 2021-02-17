#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    deque<int> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
    }
    for (int i = 0; i < n && trees.front() == trees.back(); ++i) {
        trees.push_back(trees.front());
        trees.pop_front();
    }
    if (trees.front() == trees.back()) {
        cout << -1 << endl;
        return 0;
    }
    int before = -1;
    int max_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (trees[i] == before) {
            cnt++;
        } else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
            before = trees[i];
        }
    }
    max_cnt = max(max_cnt, cnt);
    cout << (max_cnt + 1) / 2 << endl;
}
