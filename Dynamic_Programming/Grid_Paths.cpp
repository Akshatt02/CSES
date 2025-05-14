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
const int MOD = 1e9 + 7;

void solve(int testcase) {
    ll n; cin >> n;
    vector<string> a(n);
    f(a);
    vector<vll> dp(n, vll(n));
    bool f = 0;
    rep(i, 0, n) {
        if (a[0][i] == '*') f = 1;
        if (f) dp[0][i] = 0;
        else dp[0][i] = 1;
    }
    f = 0;
    rep(i, 0, n) {
        if (a[i][0] == '*') f = 1;
        if (f) dp[i][0] = 0;
        else dp[i][0] = 1;
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (a[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    dbg(dp);
    cout << dp[n - 1][n - 1] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}