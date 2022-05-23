
// author: glaucoacassioc
// created on: May 09, 2022 10:25 PM

// Problem: Critical Edges
// URL: https://www.spoj.com/problems/EC_P/
// Time Limit: 100 ms
// Memory Limit: 1536 MB

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


int n, m, tc, timer;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> tin, low;
set<pair<int, int>> st;

void dfs(int u, int p = -1) {
	visited[u] = true;
	low[u] = tin[u] = timer++;
	for (auto v : adj[u]) {
		if (v == p) {
			continue;
		}
		if (visited[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) {
				st.insert(make_pair(u, v));
			}
		}
	}
}

void find_bridges() {
	timer = 0;
	visited.assign(n + 1, false);
	tin.assign(n + 1, 0);
	low.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

void run_case() {
	cin >> n >> m;
	adj.assign(n + 1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	find_bridges();
	if ((int)st.size() > 0) {
		cout << (int)st.size() << '\n';
		for (auto &[u, v] : st) {
			cout << u << " " << v << '\n';
		}
	} else {
		cout << "Sin bloqueos" << '\n';
	}
	st.clear();
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	int T = 1;
	cin >> T;
	while (T-- > 0) {
		cout << "Caso #" << ++tc << '\n';
		run_case();
	}
}


