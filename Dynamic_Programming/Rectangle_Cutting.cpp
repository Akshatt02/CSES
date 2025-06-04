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
vector<vi> dp;
int a, b;

int help(int i, int j) {
    if (i <= 0 or j <= 0) return 0;
    if (i == j) return dp[i][j] = 0;
    if (dp[i][j] != INT_MAX) return dp[i][j];
    rep(k, 1, i) dp[i][j] = min(dp[i][j], help(k, j) + help(i - k, j) + 1);
    rep(l, 1, j) dp[i][j] = min(dp[i][j], help(i, l) + help(i, j - l) + 1);
    return dp[i][j];
}

void solve(int testcase) {
    cin >> a >> b;
    dp.assign(a + 1, vi (b + 1, INT_MAX));
    help(a, b);
    cout << dp[a][b] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}