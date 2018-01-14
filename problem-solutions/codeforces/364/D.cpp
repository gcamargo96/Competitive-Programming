#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define EPS 1e-6

int n, l, v1, v2, k;

int main(void){
	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);

	int trips = n/k;
	if(n%k) trips++;
	double d, ti, ta, tv, tbus, tpupil;
	double lo = 0.0, hi = l;

	while(1){
		d = (lo+hi)/2.0;
		//printf("lo = %lf, hi = %lf\n", lo, hi);

		ti = (d/v2); // tempo de ida do trecho de onibus
		ta = (l-d)/v1; // tempo do trecho a pe
		tv = (d - v1*ti)/(v1+v2); // tempo da volta do onibus

		tbus = trips*ti + (trips-1)*tv;
		tpupil = ti + ta;

		if(abs(tbus-tpupil) < EPS){
			printf("%.6lf\n", (tbus+tpupil)/2.0);
			break;
		}
		else if(tbus > tpupil){
			hi = d;
		}
		else{
			lo = d;
		}
	}

	return 0;
}
