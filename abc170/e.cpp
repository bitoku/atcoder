#include <bits/stdc++.h>
using namespace std;

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    while (it != a.end()) {
        it++;
        cout << delimiter << *it;
    }
    cout << endl;
}

template < class T, class S >
S max_elem(const T& iterable, S initial) {
    if (iterable.empty()) return initial;
    auto it = iterable.rbegin();
    return *it;
}

template < class T, class S >
S min_elem(const T& iterable, S initial) {
    if (iterable.empty()) return initial;
    auto it = iterable.begin();
    return *it;
}


int main() {
    int N, Q;
    cin >> N >> Q;
    vector<multiset<long long>> kinder(2*100000 + 1);
    vector<long long> child_rate(N);
    vector<int> child_kinder(N);
    multiset<long long> kinder_max;
    for (int i = 0; i < N; ++i) {
        cin >> child_rate[i] >> child_kinder[i];
        kinder[child_kinder[i]].insert(child_rate[i]);
    }
    for (int i = 0; i < kinder.size(); ++i) {
        int x = max_elem(kinder[i], -1);
        if (x == -1) continue;
        kinder_max.insert(x);
    }
    for (int i = 0; i < Q; ++i) {
        int c, d;
        cin >> c >> d;
        c--;

        int old_kinder = child_kinder[c];
        int new_kinder = d;
        long long rate = child_rate[c];
        long long old_kinder_rate = max_elem(kinder[old_kinder], -1);
        long long new_kinder_rate = max_elem(kinder[new_kinder], -1);

        // 退園
        auto oldit = kinder[old_kinder].find(rate);
        if (oldit != kinder[old_kinder].end()) {
            kinder[old_kinder].erase(oldit);
        }

        auto oldrateit = kinder_max.find(old_kinder_rate);
        if (oldrateit != kinder_max.end()) {
            kinder_max.erase(oldrateit);
        }

        int x = max_elem(kinder[old_kinder], -1);
        if (x != -1) {
            kinder_max.insert(x);
        }

        // 入園
        kinder[new_kinder].insert(rate);

        auto newrateit = kinder_max.find(new_kinder_rate);
        if (newrateit != kinder_max.end()) {
            kinder_max.erase(newrateit);
        }
        kinder_max.insert(max_elem(kinder[new_kinder], -1));
        child_kinder[c] = new_kinder;

        cout << min_elem(kinder_max, 0) << endl;
    }
}
