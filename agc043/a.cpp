#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
void printVector(vector<T> &a, string delimiter) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << delimiter << a[i];
    }
    cout << endl;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> ss(h);
    vector<vector<int>> cost(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        cin >> ss[i];
    }
    for (int i = 1; i < w; ++i) {
        cost[0][i] = cost[0][i-1];
        if (ss[0][i] == '#' && ss[0][i-1] == '.') {
            cost[0][i]++;
        }
    }
    for (int i = 1; i < h; ++i) {
        cost[i][0] = cost[i-1][0];
        if (ss[i][0] == '#' && ss[i-1][0] == '.') {
            cost[i][0]++;
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            int down = ss[i][j] == '#' && ss[i-1][j] == '.' ? cost[i-1][j] + 1 : cost[i-1][j];
            int right = ss[i][j] == '#' && ss[i][j-1] == '.' ? cost[i][j-1] + 1 : cost[i][j-1];
            cost[i][j] = min(down, right);
        }
    }
    if (ss[0][0] == '#') {
        cout << cost[h-1][w-1]+1 << endl;
    } else {
        cout << cost[h-1][w-1] << endl;
    }
}
