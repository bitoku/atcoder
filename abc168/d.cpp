#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    map<int, vector<int>> route;
    map<int, int> sign;
    set<int> done;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> next;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        route[a].push_back(b);
        route[b].push_back(a);
    }
    next.push(make_pair(0, 1));
    done.insert(1);
    while (done.size() < n) {
        pair<int, int> state = next.top();
        next.pop();
        int current = state.second;
        int cnt = state.first+1;

        for (auto i: route[current]) {
            if (sign[i] != 0) {
                continue;
            }
            sign[i] = current;
            next.push(make_pair(cnt, i));
            done.insert(i);
        }
        cnt++;
    }

    cout << "Yes" << endl;
    for (int i=2; i<=n; i++) {
        cout << sign[i] << endl;
    }

    return 0;
}
