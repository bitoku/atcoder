#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int x, y;
    string w;
    cin >> x >> y >> w;
    x--; y--;
    vector<string> c(9);
    for (int i = 0; i < 9; ++i) {
        cin >> c[i];
    }
    stringstream result;
    if (w == "R") result << c[y][x] << c[y][min(16-x-1, x+1)] << c[y][min(16-x-2, x+2)] << c[y][min(16-x-3, x+3)];
    else if (w == "L") result << c[y][x] << c[y][max(x-1, -x+1)] << c[y][max(x-2, -x+2)] << c[y][max(x-3, -x+3)];
    else if (w == "D") result << c[y][x] << c[min(16-y-1, y+1)][x] << c[min(16-y-2, y+2)][x] << c[min(16-y-3, y+3)][x];
    else if (w == "U") result << c[y][x] << c[max(y-1, -y+1)][x] << c[max(y-2, -y+2)][x] << c[max(y-3, -y+3)][x];
    else if (w == "RU") result << c[y][x] << c[max(y-1, -y+1)][min(16-x-1, x+1)] << c[max(y-2, -y+2)][min(16-x-2, x+2)] << c[max(y-3, -y+3)][min(16-x-3, x+3)];
    else if (w == "RD") result << c[y][x] << c[min(16-y-1, y+1)][min(16-x-1, x+1)] << c[min(16-y-2, y+2)][min(16-x-2, x+2)] << c[min(16-y-3, y+3)][min(16-x-3, x+3)];
    else if (w == "LU") result << c[y][x] << c[max(y-1, -y+1)][max(x-1, -x+1)] << c[max(y-2, -y+2)][max(x-2, -x+2)] << c[max(y-3, -y+3)][max(x-3, -x+3)];
    else if (w == "LD") result << c[y][x] << c[min(16-y-1, y+1)][max(x-1, -x+1)] << c[min(16-y-2, y+2)][max(x-2, -x+2)] << c[min(16-y-3, y+3)][max(x-3, -x+3)];
    cout << result.str() << endl;
}