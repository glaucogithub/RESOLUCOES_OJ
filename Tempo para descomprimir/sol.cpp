
// author: glaucoacassioc
// created on: September 18, 2021 2:40 PM

// Problem: Tempo para descomprimir
// URL: https://neps.academy/br/competition/975/exercise/1734
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
	cin.ignore();
	while (n--) {
		int x;
		char op;
		cin >> x >> op;
		for (int i = 0; i < x; ++i) {
			cout << op;
		}
		cout << '\n';
	}
}
