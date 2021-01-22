#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    vector<int> b(N + 1);
    for (int i = N; i >= 1; i--) {
        int s = 0;
        for (int j = 2; i * j <= N; ++j) {
            s += b[i * j];
        }
        if (s % 2 == a[i]) continue;
        b[i] = 1;
    }
    vector<int> c;
    for (int i = 1; i <= N; ++i) {
        if (b[i] == 1) c.push_back(i);
    }
    cout << c.size() << endl;
    printIter(c, " ");
}
