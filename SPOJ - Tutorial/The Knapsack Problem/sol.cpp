
// author: glaucoacassioc
// created on: February 01, 2022 8:06 PM

// Problem: The Knapsack Problem
// URL: https://www.spoj.com/problems/KNAPSACK/
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

#define MAXN 2050
#define INF 1000000000

int capacidade, n, valor[MAXN], tam[MAXN], memo[MAXN][MAXN];

int f(int idx, int cap) {
	if (cap < 0) {
		return -INF;
	}
	if (idx > n) {
		return 0;
	}
	if (memo[idx][cap] != -1) {
		return memo[idx][cap];
	}
	return memo[idx][cap] = max(f(idx + 1, cap), f(idx + 1, cap - tam[idx]) + valor[idx]);
}

// Funcao pra recuperar o caminho na DP da mochila

// vector<pair<int, int> > ans;
// void recover(int idx, int cap) {
// 	if (idx > n) {
// 		return;
// 	}
// 	int pega = f(idx + 1, cap - tam[idx]) + valor[idx];
// 	int nao_pega = f(idx + 1, cap);
// 	if (pega >= nao_pega) {
// 		ans.push_back({idx, valor[idx]});
// 		recover(idx + 1, cap - tam[idx]);
// 	} else {
// 		recover(idx + 1, cap);
// 	}
// }

void run_case() {
	cin >> capacidade >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> tam[i] >> valor[i];
	}
	memset(memo, -1, sizeof memo);
	cout << f(1, capacidade) << '\n';

	// cout << "----------------------------------------------" << endl;
	// recover(1, capacidade);
	// for (auto it : ans) {
	// 	cout << "Indice -> " << it.first << " com valor " << it.second << '\n';
	// }
	// cout << endl;
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


