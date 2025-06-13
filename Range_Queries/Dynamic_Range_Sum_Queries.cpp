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
class fenwick_tree {
    int n;
    vector<T> fenwick;
public:
    fenwick_tree(vector<T> &a) {
        assert(a.size() > 0);
        n = a.size();
        fenwick.assign(n + 1, 0);
        for (int i = 0; i < n; i++) increase(i, a[i]);
    }
    void increase(int i, T val) {
        assert(i >= 0 && i < n);
        i++;
        while (i <= n) {
            fenwick[i] += val;
            i += (i & (-i));
        }
    }
    T prefix_sum(int i) {
        assert(i >= 0 && i < n);
        i++;
        T sum = 0;
        while (i >= 1) {
            sum += fenwick[i];
            i -= (i & (-i));
        }
        return sum;
    }
    T range_sum(int l, int r) {
        return prefix_sum(r) - (l > 0 ? prefix_sum(l - 1) : 0);
    }
};

void solve(int testcase) {
    int n, q; cin >> n >> q;
    vll a(n); f(a);
    fenwick_tree ft(a);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int pos, val; cin >> pos >> val;
            ft.increase(pos - 1, val - a[pos - 1]);
            a[pos - 1] = val;
        } else {
            int l, r; cin >> l >> r;
            cout << ft.range_sum(l - 1, r - 1) << "\n";
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    rep(i, 0, _t) solve(i + 1);
}