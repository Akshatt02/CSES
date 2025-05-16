#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using ii = pair<int, int>;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define f(a) for (auto& x:a) cin >> x;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(x...) 42
#endif

// Global Variable Declaration


void solve(int testcase) {
    ll y, x; cin >> y >> x;
    ll mx = max(x, y);
    if (mx & 1) {
        if (x == mx) cout << mx * mx - y + 1;
        else cout << (mx - 1) * (mx - 1) + x;
    }
    else {
        if (y == mx) cout << mx * mx - x + 1;
        else cout << (mx - 1) * (mx - 1) + y;
    }
    cout << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    cin >> _t;
    while(_t--) solve(_t);
}