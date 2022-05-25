
// author: glaucoacassioc
// created on: May 25, 2022 1:32 AM

// Problem: Cifra de César
// URL: https://www.beecrowd.com.br/judge/pt/problems/view/1253
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

SOLUCAO:

Essa questao voce tem que observar que ela comeca no final da string.
E o pulo que ele dar é: - K + 26(quantidade de letras no alfabeto (contando a partir de 0).
Como comecei do final, a string vai estar ao reverso por isso usei o reverse().
Por ex.: O segundo caso, a letra 'A' se for pular 10 devia estar no 'K'
mas estar no Q(que é 16, 6 posicoes a frente do K que é 10). Entao isso no leva que o pulo vai ser
o -K + 26 = -10 + 26 => 16(O valor pedido do Q)..

*/

void run_case() {
	int k;
	string str, res = "";
	cin >> str >> k;
	for (int i = (int)str.length() - 1; i >= 0; --i) {
		res += char(int(str[i] - k + 26 - 65) % 26 + 65);
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';
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


