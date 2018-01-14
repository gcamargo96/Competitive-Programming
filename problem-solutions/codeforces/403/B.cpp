#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define EPS 1e-6

const int N = 60002;
pair<double, double> v[N];
int n;

double f(double p){
	double ret = 0;
	For(i,0,n){
		ret = max(ret, abs(p - v[i].fi)/v[i].se);
	}
	return ret;
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lf", &v[i].fi);
	}
	
	For(i,0,n){
		scanf("%lf", &v[i].se);
	}

	sort(v, v+n);
	
	double l = v[0].fi, r = v[n-1].fi;

	while(r-l > EPS){
		double g = l + (r-l)/3.0;
		double h = l + 2*(r-l)/3.0;

		if(f(g) < f(h)){
			r = h;
		}
		else{
			l = g;
		}
	}

	printf("%lf\n", f(l));

	return 0;
}

