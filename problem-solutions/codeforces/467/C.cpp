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

double k, d, t;

int main(void){
	scanf("%lf%lf%lf", &k, &d, &t);

	double p, c;
	if(k > d){
		p = ceil(k/d)*d;
	}
	else{
		p = d;
	}

	c = k + (p-k)/2.0;
	
	double q = floor(t/c);
	double r = t - q*c;

	// printf("c = %lf, q = %lf, r = %lf\n", c, q, r);

	double ans = q*p;
	if(r <= k){
		ans += r;
	}
	else{
		ans += k;
		r -= k;
		ans += 2.0*r;
	}

	printf("%.10lf\n", ans);

	return 0;
}