
// author: glaucoacassioc
// created on: September 18, 2021 3:04 PM

// Problem: Flipper
// URL: https://neps.academy/br/competition/975/exercise/1736
// Time Limit: 1000 ms
// Memory Limit: 256 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool its_H, its_V;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int mat[2][2] = {1, 2, 3, 4};
	for (char ch : s) {
		if (ch == 'H') {
			its_H = !its_H;
		} else {
			its_V = !its_V;
		}
		if (its_H) {
			its_H = !its_H;
			swap(mat[0][0], mat[1][0]);
			swap(mat[0][1], mat[1][1]);
		}
		if (its_V) {
			its_V = !its_V;
			swap(mat[0][0], mat[0][1]);
			swap(mat[1][0], mat[1][1]);
		}
	}
	cout << mat[0][0] << " " << mat[0][1] << '\n';
	cout << mat[1][0] << " " << mat[1][1] << '\n';
}
