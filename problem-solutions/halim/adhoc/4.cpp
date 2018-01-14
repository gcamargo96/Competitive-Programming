#include <bits/stdc++.h>
using namespace std;

double dep[105];

int main(void){
	int m, n;
	double d, a;
	// valor inicial do carro: imprestimo + downpayment

	while(scanf("%d%lf%lf%d", &m, &d, &a, &n) != EOF){
		if(m < 0) break;
		memset(dep, 0, sizeof(dep));

		int mes;
		double tax;
		double val = a;
		for(int i = 0; i < n; i++){
			scanf("%d%lf", &mes, &tax);
			dep[mes] = tax;
		}

		for(int i = 1; i <= m; i++){
			if(dep[i] == 0){
				dep[i] = dep[i-1];
			}
		}
		//for(int i = 0; i <= m; i++) cout << dep[i] << endl;
		double car = a+d;
		//printf("amount: %lf / car: %lf\n", a, car);

		int res = -1;
		car -= car*dep[0];
		if(car > val){
			res = 0;
		}
		//printf("amount: %lf / car: %lf\n", a, car);
		if(res == -1){
			for(int i = 1; i <= m; i++){
				val -= (a/m);
				car -= car*dep[i];
				//printf("amount: %lf / car: %lf\n", a, car);
				if(car > val){
					res = i;
					break;
				}
			}
		}

		if(res > 1 or res == 0) printf("%d months\n", res);
		else printf("%d month\n", res);
	}	

	return 0;
}
