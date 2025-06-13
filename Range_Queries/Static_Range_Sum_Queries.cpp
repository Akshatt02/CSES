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
    int n, q; cin >> n >> q;
    vll a(n); f(a);
    vll pre(n + 1, 0);
    rep(i, 0, n) pre[i + 1] = pre[i] + a[i];
    rep(i, 0, q) {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}