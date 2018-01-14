#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const double EPS = 1e-5;
int n;
double dist;
pair<double,double> points[500002];

double f(double x){
	double ret = -1;
	for(int i = 0; i < n; i++){
		if(hypot(x-points[i].fi, points[i].se) > ret){
			ret = hypot(x-points[i].fi, points[i].se);
		}
	}
	if(dist > ret) dist = ret;
	return ret;
}

double ternary_search(double l, double r){
	double g, h;
	
	while(r-l > EPS){
		g = l + (r-l)/3.0;
		h = l + 2*(r-l)/3.0;
		if(f(g) < f(h)){
			r = h;
		}
		else{
			l = g;
		}
	}
	return (l+r)/2.0;
}

int main(void){
	
	while(scanf("%d", &n), n != 0){
		dist = 1e10;
		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &points[i].fi, &points[i].se);
		}
		
		double res = ternary_search(-200000, 200000);

		printf("%lf %lf\n", res, dist);
	}

	return 0;
}
