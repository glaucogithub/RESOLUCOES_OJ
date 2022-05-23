
// author: glaucoacassioc
// created on: September 19, 2021 9:38 PM

// Problem: Cardápio
// URL: https://neps.academy/br/competition/962/exercise/1700
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
	double cod, qtde;
	vector<pair<double, double> > v = {{1.0, 6.90}, {2.0, 7.30}, {3.0, 4.50}, {4.0, 5.70}};
	cin >> cod >> qtde;
	for (int i = 0; i < (int)v.size(); ++i) {
		if (cod == v[i].first) {
			cout << fixed << setprecision(2) << "O valor total da compra e R$ " << qtde * v[i].second << '\n';
			break;
		}
	}
}
