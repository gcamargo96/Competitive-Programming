#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int n, m, q, d;
bool verifica_morreu (int gas, int pessoa) {
	if (gas - d <= pessoa and gas + d >= pessoa) return true;
	return false;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &q, &d);
	vector <int> pessoas;
	set <int> gases;
	pessoas.pb(0);
	for (int i = 1; i < n; i++) {
		int x; scanf("%d", &x);
		pessoas.pb(x);
	}
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		gases.insert(x);
	}

	int resposta = n;
	set<int>::iterator it;
	for (int i = 0; i < n; i++) {
		it = gases.lower_bound(pessoas[i] - d);
		if (verifica_morreu (*it, pessoas[i])) continue ;
		it = gases.lower_bound(pessoas[i] + d);
		if (it != gases.end() and verifica_morreu (*it, pessoas[i])) continue;
		resposta--;
	}
	printf("%d\n", resposta);
	for (int i = 0; i < q; i++) {
		int right, left;
		int gas, novo; scanf("%d %d", &gas, &novo);
		gases.erase(gas);
		it = gases.lower_bound (gas);
		if (it == gases.begin()) {
			left = gas - d;
		} else {
			it--;
			left = max (*it + d + 1, gas - d);
		}
		it = gases.lower_bound (gas);
		if (it == gases.end()) {
			right = gas + d;
		} else {
			right = min (gas + d, *it - d - 1);
		}
//		printf("left %d right %d\n", left, right);
		if (left <= right) {
			int y = lower_bound (pessoas.begin (), pessoas.end(), right+1) - pessoas.begin();
			int x = lower_bound (pessoas.begin(), pessoas.end(), left) - pessoas.begin();
	//		printf("y %d x %d\n", y, x);
			resposta -= (y - x);
		}
		
		it = gases.lower_bound (novo);
		if (it == gases.begin()) {
			left = novo - d;
		} else {
			it--;
			left = max (*it + d + 1, novo - d);
		}
		it = gases.lower_bound (novo);
		if (it == gases.end()) {
			right = novo + d;
		} else {
			right = min (novo + d, *it - d - 1);
		}
//		printf("left %d right %d\n", left, right);

		if (left <= right) {
			int y = lower_bound (pessoas.begin(), pessoas.end(), right+1) - pessoas.begin();
			int x = lower_bound (pessoas.begin(), pessoas.end(), left) - pessoas.begin();
//			printf("y %d x %d\n", y, x);
			resposta += (y - x);
		}
		printf("%d\n", resposta);
		gases.insert(novo);

	}
	return 0;
}