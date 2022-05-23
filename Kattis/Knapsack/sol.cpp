
// author: glaucoacassioc
// created on: February 06, 2022 7:32 PM

// Problem: Knapsack
// URL: https://open.kattis.com/problems/knapsack
// Time Limit: 2000 ms
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
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF 0x3f3f3f3f
#define MAXN 2100

int c, n, valor[MAXN], peso[MAXN], memo[MAXN][MAXN];

int f(int idx, int cap) {
	if (cap < 0) {
		return -INF;
	}
	if (idx == n) {
		return 0;
	}
	if (memo[idx][cap] != -1) {
		return memo[idx][cap];
	}
	return memo[idx][cap] = max(f(idx + 1, cap),
	                            f(idx + 1, cap - peso[idx]) + valor[idx]);
}

vector<int> ans;
void recover(int idx, int cap) {
	if (idx == n) {
		return;
	}
	int pega = f(idx + 1, cap - peso[idx]) + valor[idx];
	int nao_pega = f(idx + 1, cap);
	if (pega >= nao_pega) {
		ans.push_back(idx);
		recover(idx + 1, cap - peso[idx]);
	} else {
		recover(idx + 1, cap);
	}
}

void run_case() {
	while (cin >> c >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> valor[i] >> peso[i];
		}
		memset(memo, -1, sizeof memo);
		recover(0, c);
		cout << (int)ans.size() << '\n';
		for (auto i : ans) {
			cout << i << " ";
		}
		cout << '\n';
		ans.clear();
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


