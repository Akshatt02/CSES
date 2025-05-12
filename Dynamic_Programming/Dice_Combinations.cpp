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
int n;
vi dp;

int help(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    rep(i, 1, 7) {
        dp[n] = (dp[n] + help(n - i)) % MOD;
    }
    return dp[n];
}

void solve(int testcase) {
    cin >> n;
    dp.assign(n + 1, -1);
    help(n);
    cout << dp[n] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}