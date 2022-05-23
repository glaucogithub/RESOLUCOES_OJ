
// author: glaucoacassioc
// created on: February 03, 2022 1:13 PM

// Problem: NAJLG - longest common subsequence
// URL: https://www.spoj.com/K50CL/problems/NAJLG/
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

#define MAXN 1010

string s1, s2;
int n, m, test, memo[MAXN][MAXN];

int lcs(int i, int j) {
	if (i == n || j == m) {
		return 0;
	}
	if (memo[i][j] != -1) {
		return memo[i][j];
	}
	if (s1[i] == s2[j]) {
		memo[i][j] = 1 + lcs(i + 1, j + 1);
	} else {
		memo[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
	}
	return memo[i][j];
}

void run_case() {
	cin >> s1 >> s2;
	n = (int)s1.size();
	m = (int)s2.size();
	memset(memo, -1, sizeof memo);
	cout << "Case " << ++test << ": " << lcs(0, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	int T = 1;
	cin >> T;
	while (T-- > 0) {
		run_case();
	}
}


