
// author: glaucoacassioc
// created on: February 20, 2022 10:49 PM

// Problem: Static Range Minimum Queries
// URL: https://cses.fi/problemset/task/1647
// Time Limit: 1000 ms
// Memory Limit: 512 MB

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF 0x3f3f3f3f
const int MAXN = 2020000;
int n, a[MAXN], t[4 * MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return INF;
	}
	if (tl >= l && tr <= r) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return min(query(v * 2, tl, tm, l, r), query(v * 2 + 1, tm + 1, tr, l, r));
}

void run_case() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (q-- > 0) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	int T = 1;
	// cin >> T;
	while (T-- > 0) {
		run_case();
	}
}


