
// author: glaucoacassioc
// created on: September 19, 2021 9:39 PM

// Problem: Fila da Vacina
// URL: https://neps.academy/br/competition/962/exercise/1702
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
	for (int i = 3; i <= n; i += 3) {
		if (i & 1 && i % 3 == 0) {
			cout << i << '\n';
		}
	}
}
