
// author: glaucoacassjoc
// created on: September 19, 2021 11:07 PM

// Problem: Número Secreto
// URL: https://neps.academy/br/competition/963/exercise/1705
// Time Limit: 1000 ms
// Memory Limit: 256 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	double mat[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}
	//soma da linha
	double soma_linha = 0;
	for (int j = 0; j < m; ++j) {
		soma_linha += mat[x][j];
	}
	//soma da coluna
	double soma_coluna = 0;
	for (int i = 0; i < n; ++i) {
		soma_coluna += mat[i][y];
	}
	cout << fixed << setprecision(2) << (soma_linha + soma_coluna - mat[x][y]) / (n + m - 1) << '\n';
}
