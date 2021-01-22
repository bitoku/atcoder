#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    vector<vector<int>> b;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> s;
    for (int i=0;i<n;i++) {
        vector<int> aa;
        for (int j=0;j<n;j++) {
            int aaa;
            cin >> aaa;
            aa.push_back(aaa);
            s.push(make_tuple(aaa, i, j));
        }
        a.push_back(aa);
    }
    b = a;
    for (int k=0;k<n;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (b[i][j] > b[i][k] + b[k][j]) {
                    b[i][j] = b[i][k] + b[k][j];
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    long long result = 0;
    while (!s.empty()) {
        auto x = s.top();
        s.pop();
        int i = get<1>(x);
        int j = get<2>(x);
        bool shortcut = false;
        for (int k=0;k<n;k++) {
            if (k == i || k == j) {
                continue;
            }
            if (b[i][j] == b[i][k] + b[k][j]) {
                shortcut = true;
            }
        }
        if (!shortcut) {
            result += b[i][j];
        }
    }

    std::cout << result / 2 << std::endl;
    return 0;
}
