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
    vector<vector<int>> ab(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<>> pq;
    vector<int> result;
    vector<bool> done(n);
    pq.push(0);
    while (!pq.empty()) {
        int i = pq.top(); pq.pop();
        if (done[i]) continue;
        result.push_back(i+1);
        done[i] = true;
        for (const auto j : ab[i]) {
            if (done[j]) continue;
            pq.push(j);
        }
    }
    printVector(result);
}
