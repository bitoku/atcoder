#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> m;
    x--;
    y--;
    int thre1 = x + (y - x) / 2 + 1;
    int thre2 = x + (y - x) / 2;
    for(int i=0; i < n; i++) {
        for(int j=i+1; j < n; j++) {
            int k = min(j - i, abs(i - x) + abs(j - y) + 1);
            m[k]++;
        }
    }
    for (int i=1; i<n; i++) {
        cout << m[i] << endl;
    }
    return 0;
}
