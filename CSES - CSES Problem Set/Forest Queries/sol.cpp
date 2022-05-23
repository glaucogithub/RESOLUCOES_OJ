
// author: glaucoacassioc
// created on: November 04, 2021 5:38 PM

// Problem: Forest Queries
// URL: https://cses.fi/problemset/task/1652
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MAXN = 1010;
vector<vector<int>> v(MAXN, vector<int>(MAXN)), dp(MAXN, vector<int>(MAXN));

void build(int n, int m) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = v[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}
}

int query(int x1, int y1, int x2, int y2) {
	return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}

void run_case() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			v[i][j] = (c == '*');
		}
	}
	build(n, n);
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query(x1, y1, x2, y2) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	int T = 1;
	// cin >> T;
	while (T-- > 0) {
		run_case();
	}
}
