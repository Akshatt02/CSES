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

template <typename T = long long>
class sparse_table_min {
    int n, k;
    vector<vector<T>> sp;
public:
    sparse_table_min(vector<T> &a) { // assuming a is 0-indexed
        n = a.size();
        assert(n > 0);
        k = 32 - __builtin_clz(n); // k = __lg(n) + 1 = log2(n) + 1 = 32 - __builtin_clz(n) - 1 + 1
        sp.assign(n, vector<T> (k, -1));
        for (int i = n - 1; i >= 0; i--) {
            sp[i][0] = a[i];
            for (int j = 1; i + (1 << j) - 1 < n; j++) {
                sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r) { // assuming l, r are 0-indexed
        assert(l >= 0 && l < n && r >= 0 && r < n && l <= r);
        int tmp = 32 - __builtin_clz(r - l + 1) - 1;
        return min(sp[l][tmp], sp[r - (1 << tmp) + 1][tmp]);
    }
};

void solve(int testcase) {
    int n, q; cin >> n >> q;
    vi a(n); f(a);
    sparse_table_min<int> st(a);
    rep(i, 0, q) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << st.query(l, r) << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}