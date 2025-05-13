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
//Top down approach
// vi dp;

// int help(int amount, vi& a, int n) {
//     if (amount == 0) return 0;
//     if (amount < 0) return INT_MAX;
//     if (dp[amount] != INT_MAX) return dp[amount];
//     rep(i, 0, n) {
//         int sub = help(amount - a[i], a, n);
//         if (sub != INT_MAX) dp[amount] = min(dp[amount], sub + 1);
//     }
//     return dp[amount];
// }

// void solve(int testcase) {
//     int n, amount; cin >> n >> amount;
//     vi a(n); f(a);
//     dp.assign(amount + 1, INT_MAX);
//     help(amount, a, n);
//     cout << (dp[amount] == INT_MAX ? -1 : dp[amount]) << "\n";
// }

void solve(int testcase) {
    int n, amount; cin >> n >> amount;
    vi a(n); f(a);
    vi dp(amount + 1, INT_MAX);
    dp[0] = 0;
    rep(i, 1, amount + 1) {
        rep(j, 0, n) {
            if (i - a[j] >= 0 and dp[i - a[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << (dp[amount] == INT_MAX ? -1 : dp[amount]) << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}