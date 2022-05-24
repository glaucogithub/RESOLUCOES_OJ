
// author: glaucoacassioc
// created on: May 23, 2022 4:35 PM

// Problem: Etruscan Warriors Never Play Chess
// URL: https://vjudge.net/problem/UVA-11614
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
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/*

SOLUCAO DO PROBLEMA:

Formula da soma dos N numeros naturais consecutivos:
S = n * (n + 1)/2

O valor da soma é o n dado na questao.
Desenvolvendo a funcao...
n^2 + n = 2 * S
n^2 + n + (-2 * S) = 0

Valor de A = 1, B = 1 e C = (-2 * S)

Usando a equacao quadratica ax^2 + bx + c = 0
Calculamos o DELTA = b * b - 4 * a * c

Nos sabemos que X = (-b (+ -) sqrt(DELTA) ) / 2 * a
Aqui eu uso o valor + porque sempre o DELTA é positivo

Entao a ans = (-b + sqrt(b * b - 4 * a * c)) / 2 * a
Substituindo os valores de A, B e C vamos ter a seguinte formula...

ans = (-1 + sqrt(1 - 4 * 1 * (-2 * S))) / 2 * 1
ans = (-1 + sqrt(1 - 4 * (-2 * S))) / 2
ans = (-1 + sqrt(1 - (-8 * S))) / 2

Entao a resposta é essa formula
ans = (-1 + sqrt(1 + 8 * S)) / 2

Obs.: A entrada é feita como double pra usar a funcao sqrt, depois na saida convertemos pra long long

*/
void run_case() {
	double n;
	cin >> n;
	cout << (long long)(-1 + sqrt(1 + 8 * n)) / 2 << '\n';
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


