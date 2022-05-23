
// author: glaucoacassioc
// created on: September 19, 2021 9:39 PM

// Problem: Olimpíada dos códigos
// URL: https://neps.academy/br/competition/962/exercise/1703
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
	vector<int> v(9);
	for (int i = 0; i < 9; ++i) {
		cin >> v[i];
	}
	int p1 = v[0] * 5 + v[1] * 3 + v[2] * 2;
	int p2 = v[3] * 5 + v[4] * 3 + v[5] * 2;
	int p3 = v[6] * 5 + v[7] * 3 + v[8] * 2;
	if (p1 != p2 && p1 != p3 && p2 != p3) {
		cout << "Teremos uma cerimonia" << '\n';
	} else {
		cout << "Algo deu errado" << '\n';
	}
}
