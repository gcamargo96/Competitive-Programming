#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;
double a, b, c;

double f(double x){
	return a*x*x + b*x + c;
}

double ternary_search(double l, double r){
	double g, h;
	
	while(r-l > EPS){
	//	cout << r-l << endl;
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
	a = 1;
	b = c = 0;

	int l = -5, r = 5, g, h;
	double res = ternary_search(l, r);

	printf("%lf\n", res);

	return 0;
}
