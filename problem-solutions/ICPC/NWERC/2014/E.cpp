#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const double EPS = 1e-8;
double n, p, s, v;

double f(double c){
	double alg = (n*pow(log2(n), c*sqrt(2)))/(p*1e9);
	double travel = s*(1.0+1.0/c)/v;
	return alg + travel;
}

double ternary_search(double l, double r){
	double g, h;
	
	while(r-l > EPS){
		// cout << l << " " << r << endl;
		g = l + (r-l)/3.0;
		h = l + 2.0*(r-l)/3.0;
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
	scanf("%lf%lf%lf%lf", &n, &p, &s, &v);

	double l = 0, r = 100;
	double c = ternary_search(l, r);

	printf("%.10lf %.10lf\n", f(c), c);

	return 0;
}