
// author: glaucoacassioc
// created on: January 22, 2022 6:14 AM

// Problem: Building Teams
// URL: https://cses.fi/problemset/task/1668
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

void run_case() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bool is_bipartite = true;
	vector<int> color(n + 1, -1);
	queue<int> q;
	for (int s = 1; s <= n; ++s) {
		if (color[s] == -1) {
			color[s] = 0;
			q.push(s);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto& v : g[u]) {
					if (color[v] == -1) {
						color[v] = color[u] ^ 1;
						q.push(v);
					} else  {
						is_bipartite &= color[v] != color[u];
					}
				}
			}
		}
	}
	if (is_bipartite) {
		for (int i = 1; i <= n; ++i) {
			cout << color[i] + 1 << " ";
		}
		cout << '\n';
	} else {
		cout << "IMPOSSIBLE" << '\n';
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


