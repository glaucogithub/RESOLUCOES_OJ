
// author: glaucoacassioc
// created on: September 19, 2021 9:38 PM

// Problem: Exercícios para a Minimaratona
// URL: https://neps.academy/br/competition/962/exercise/1698
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
	int n;
	cin >> n;
	cout << "Total de exercicios: " << n * 13 << '\n';
}
