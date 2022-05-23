
// author: glaucoacassioc
// created on: February 09, 2022 6:49 PM

// Problem: Promoções
// URL: https://www.beecrowd.com.br/judge/pt/problems/view/2776?origem=1
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
#define MAXN 1010
int n, m, memo[MAXN][2 * MAXN], valor[MAXN], peso[MAXN];

int f(int idx, int cap) {
	// No enunciado, ele fala que você precisa vender TODAS as latas
	// Se você já atingiu a capacidade 0, significa que você já vendeu todas
	// Então você pode simplesmente retornar 0
	// Mas, caso você caia no outro if, significa que você chegou no final, mas a sua capacidade não é zero
	// Então ainda tem latinhas sobrando
	// Então você retorna -INF para falar que essa configuração é inválida
	if (idx == n) {
		if (cap == 0) {
			return 0;
		} else {
			return -INF;
		}
	}
	if (memo[idx][cap] != -1) {
		return memo[idx][cap];
	}
	// Essa é uma variante da mochila e é feita assim voce nao pega
	// e verifica se o peso é maior que a capacidade, se for entao voce tira o maximo entre os 3.
	// Knapsack Unbounded (Mochila ilimitada).
	memo[idx][cap] = f(idx + 1, cap);
	if (peso[idx] <= cap) {
		memo[idx][cap] = max({f(idx + 1, cap), f(idx + 1, cap - peso[idx]) + valor[idx], f(idx, cap - peso[idx]) + valor[idx]});
	}
	return memo[idx][cap];
}

void run_case() {
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			cin >> peso[i] >> valor[i];
		}
		memset(memo, -1, sizeof memo);
		cout << f(0, m) << '\n';
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


