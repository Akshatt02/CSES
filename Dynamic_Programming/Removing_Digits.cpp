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
vi dp;

int help(int n) {
    if (n < 10) return dp[n] = 1;
    if (dp[n] != -1) return dp[n];
    int dig = -1;
    int num = n;
    while (num > 0) {
        int rem = num % 10;
        dig = max(rem, dig);
        num /= 10;
    }
    dp[n] = help(n - dig) + 1;
    return dp[n];
}

void solve(int testcase) {
    int n; cin >> n;
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