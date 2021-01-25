#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string a(ty-sy, 'U');
    string b(tx-sx, 'R');
    string c(ty-sy, 'D');
    string d(tx-sx, 'L');
    string e(ty-sy+1, 'U');
    string f(tx-sx+1, 'R');
    string g(ty-sy+1, 'D');
    string h(tx-sx+1, 'L');
    cout << a
    << b
    << c
    << d
    << 'L'
    << e
    << f
    << 'D'
    << 'R'
    << g
    << h
    << 'U' << endl;
}
