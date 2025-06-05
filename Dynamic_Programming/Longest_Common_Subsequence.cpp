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
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    f(a) f(b)
    vector<vi> dp(n + 1, vi(m + 1));
    rep(i, 0, n + 1) dp[i][0] = 0;
    rep(j, 0, m + 1) dp[0][j] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << "\n";
    int i = n, j = m;
    vi lcs;
    while (i > 0 and j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    for (auto& x:lcs) cout << x << " ";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}