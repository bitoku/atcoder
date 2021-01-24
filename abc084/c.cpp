#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Station {
    int cost;
    int start;
    int freq;
};
int main() {
    int n;
    cin >> n;
    vector<Station> stations(n - 1);
    vector<int> costs(n);
    for (auto & station : stations) {
        cin >> station.cost >> station.start >> station.freq;
    }
    for (int i = 0; i < n - 1; ++i) {
        costs[i] = stations[i].start + stations[i].cost;
        for (int j = i + 1; j < n - 1; ++j) {
            if (costs[i] < stations[j].start) {
                costs[i] = stations[j].start;
            } else if (costs[i] % stations[j].freq != 0) {
                costs[i] += stations[j].freq - (costs[i] % stations[j].freq);
            }
            costs[i] += stations[j].cost;
        }
    }
    for (int cost : costs) {
        cout << cost << endl;
    }
}
