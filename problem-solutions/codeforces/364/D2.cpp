#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

int main(){
	int n, l, v1, v2, k, g;
	double left, right, mid;
	double ti, tv, ta, d;
	double tb, tp;

	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);

	g = n / k;

	if (n % k){
		g++; // numero de viagens
	}

	left = 0.0;
	right = l;

	while (true){
		mid = (left + right) / 2.0;

		d = mid;

		ti = (d / v2); // Tempo de ir de onibus
		tv = (d - ti * v1) / (v1 + v2); // Tempo de voltar
		ta = (l - d) / v1; // Tempo de andar

		tb = g * ti + (g - 1) * tv;
		tp = ti + ta;

		if (abs(tb - tp) < eps){
			printf("%.8lf\n", tp);
			break;
		}
		else if (tb > tp){
			right = mid;
		}
		else{
			left = mid;
		}
	}

	return 0;
}
