#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

// #define 0 BOT
// #define 1 DIR
// #define 2 TOP
// #define 3 ESQ

const double EPS = 1e-7;
double a, d;
int n, lado = 0;
double x = 0, y = 0;
double dist = 0;

int main(void){
	scanf("%lf%lf", &a, &d);
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		// ll l = 0, r = 100000;
		// double resto = 0;
		// while(l <= r){
		// 	// printf("l = %d, r = %d\n", l, r);
		// 	ll k = (l+r)/2;
		// 	if(a*4.0*k <= d){
		// 		resto = d - a*4.0*k;
		// 		l = k+1;
		// 	}
		// 	else{
		// 		// resto = d - a*4.0*k;
		// 		r = k-1;
		// 	}
		// }

		double k = floor(d/(4.0*a));
		double resto = d - a*4.0*k;

		// printf("resto = %lf\n", resto);

		dist += resto;
		while(dist >= 4.0*a){
			dist -= 4.0*a;
		}

		// printf("dist = %lf\n", dist);

		if(0.0 <= dist and dist < a){
			lado = 0;
		}
		else if(a <= dist and dist < 2.0*a){
			lado = 1;
		}
		else if(2.0*a <= dist and dist < 3.0*a){
			lado = 2;
		}
		else if(3.0*a <= dist and dist < 4.0*a){
			lado = 3;
		}
		// lado %= 4;

		// printf("lado = %d\n", lado);

		if(lado == 0){
			printf("%lf %lf\n", dist, 0.0);
		}
		else if(lado == 1){
			printf("%lf %lf\n", a, dist-a);
		}
		else if(lado == 2){
			printf("%lf %lf\n", a - (dist-2.0*a), a);
		}
		else if(lado == 3){
			printf("%lf %lf\n", 0.0, a - (dist-3.0*a));
		}
	}

	return 0;
}