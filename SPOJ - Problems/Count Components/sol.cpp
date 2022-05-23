
// author: glaucoacassioc
// created on: January 05, 2022 10:57 PM

// Problem: Count Components
// URL: https://www.spoj.com/problems/CCOMPS/
// Time Limit: 1000 ms
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

const int MAXN = 100010;

int n, m, x, y, ans;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

void dfs(int v) {
	used[v] = true ;
	comp.push_back(v);
	for (size_t i = 0; i < (int) g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	for (int i = 1; i <= n ; ++i)
		used[i] = false;
	for (int i = 1; i <= n ; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			++ans;
			// cout << "Componentes:";
			// for (size_t j = 0; j < comp.size(); ++j)
			// 	cout << " " << comp[j];
			// cout << endl;
		}
	}
	cout << ans << '\n';
}

void run_case() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	find_comps();
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
