
// author: glaucoacassioc
// created on: October 12, 2021 8:32 PM

// Problem: Competição
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1514
// Time Limit: 1000 ms
// Memory Limit: 1024 MB

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

//OK
bool rule_one(int n, int m, vector<vector<int> > mat) {
	for (int i = 0; i < n; ++i) {
		int sum_line = 0;
		for (int j = 0; j < m; ++j) {
			sum_line += mat[i][j];
		}
		if (sum_line == m) {
			return false;
		}
	}
	return true;
}

//OK
bool rule_two(int n, int m, vector<vector<int> > mat) {
	int cnt_col = 0;
	for (int i = 0; i < m; ++i) {
		int sum_col = 0;
		for (int j = 0; j < n; ++j) {
			sum_col += mat[j][i];
		}
		if (sum_col > 0) {
			cnt_col++;
		}
	}
	if (cnt_col == m) {
		return true;
	} else {
		return false;
	}
}

//OK
bool rule_three(int n, int m, vector<vector<int> > mat) {
	for (int i = 0; i < m; ++i) {
		int sum_col = 0;
		for (int j = 0; j < n; ++j) {
			sum_col += mat[j][i];
		}
		if (sum_col == n) {
			return false;
		}
	}
	return true;
}

//OK
bool rule_four(int n, int m, vector<vector<int> > mat) {
	int cnt_line = 0;
	for (int i = 0; i < n; ++i) {
		int sum_line = 0;
		for (int j = 0; j < m; ++j) {
			sum_line += mat[i][j];
		}
		if (sum_line > 0) {
			cnt_line++;
		}
	}
	if (cnt_line  == n) {
		return true;
	} else {
		return false;
	}
}

void run_case() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		vector<vector<int> > mat(n + 1, vector<int>(m + 1));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mat[i][j];
			}
		}
		int ans = 0;
		if (rule_one(n, m, mat)) {
			// cout << "Regra 1" << '\n';
			ans++;
		}
		if (rule_two(n, m, mat)) {
			// cout << "Regra 2" << '\n';
			ans++;
		}
		if (rule_three(n, m, mat)) {
			// cout << "Regra 3" << '\n';
			ans++;
		}
		if (rule_four(n, m, mat)) {
			// cout << "Regra 4" << '\n';
			ans++;
		}
		cout << ans << '\n';
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
