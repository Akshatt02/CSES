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

//Top down approach got TLE :(
// vector<vi> dp;

// int help(int i, int amount, int n, vi& a) {
//     if (amount == 0) return 1;
//     if (i == n or amount < 0) return 0;
//     if (dp[i][amount] != -1) return dp[i][amount];
//     int take = help(i, amount - a[i], n, a);
//     int skip = help(i + 1, amount, n, a);
//     dp[i][amount] = (take + skip) % MOD;
//     return dp[i][amount];
// }

// void solve(int testcase) {
//     int n, amount; cin >> n >> amount;
//     vi a(n); f(a);
//     dp.assign(n + 1, vi(amount + 1, -1));
//     help(0, amount, n, a);
//     cout << dp[0][amount] << "\n";
// }

void solve(int testcase) {
    int n, amount; cin >> n >> amount;
    vi a(n); f(a);
    vi dp(amount + 1, 0);
    dp[0] = 1;
    rep(i, 0, n) {
        rep(j, a[i], amount + 1) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << dp[amount] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}