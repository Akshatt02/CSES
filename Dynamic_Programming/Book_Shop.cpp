#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
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

//Bruh again Top-down gave TLE :(
// vector<vi> dp;
// int n, price;
// vi a, b;

// int help(int i, int p) {
//     if (i == 0 or p == 0) return 0;
//     if (dp[i][p] != -1) return dp[i][p];
//     if (p >= a[i - 1]) dp[i][p] = max(help(i - 1, p), help(i - 1, p - a[i - 1]) + b[i - 1]);
//     else dp[i][p] = help(i - 1, p);
//     return dp[i][p];
// }

// void solve(int testcase) {
//     cin >> n >> price;
//     a.resize(n); b.resize(n);
//     f(a); f(b);
//     dp.assign(n + 1, vi(price + 1, -1));
//     help(n, price);
//     cout << dp[n][price] << "\n";
// }

void solve(int testcase) {
    int n, p; cin >> n >> p;
    vi a(n), b(n);
    f(a); f(b);
    vector<vi> dp(n + 1, vi(p + 1, -1));
    rep(i, 0, n + 1) dp[i][0] = 0;
    rep(i, 0, p + 1) dp[0][i] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, p + 1) {
            if (j >= a[i - 1]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + b[i - 1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][p] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}