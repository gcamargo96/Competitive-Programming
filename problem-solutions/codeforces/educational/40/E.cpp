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

const double EPS = 1e-7;
const int N = 200002;
int n;
int t;
pair<double,double> v[N];
double num[N], den[N];

int main(void){
	scanf("%d%d", &n, &t);

	for(int i = 1; i <= n; i++){
		scanf("%lf", &v[i].se);
	}

	for(int i = 1; i <= n; i++){
		scanf("%lf", &v[i].fi);
	}

	sort(v+1, v+n+1);

	if(t < v[1].fi or t > v[n].fi){
		printf("0\n");
		return 0;
	}

	for(int i = 1; i <= n; i++){
		num[i] = num[i-1] + v[i].fi*v[i].se;
		den[i] = den[i-1] + v[i].se;
	}

	if(num[n]/den[n] >= t){
		double l = 0, r = den[n], ans;
		while(r-l > EPS){
			double mid = (l+r)/2.0;
			int i = upper_bound(den+1, den+n+1, mid) - (den);
			double extra = mid-den[i-1];
			double temp = (num[i-1]+extra*v[i].fi)/(den[i-1]+extra);

			// printf("i = %d, mid = %lf, extra = %lf, temp = %lf\n", i, mid, extra, temp);

			if(temp <= t){
				ans = mid;
				l = mid;
			}
			else{
				r = mid;
			}
		}

		printf("%.6lf\n", (l+r)/2.0);		
	}
	else{
		reverse(v+1, v+n+1);
		for(int i = 1; i <= n; i++){
			num[i] = num[i-1] + v[i].fi*v[i].se;
			den[i] = den[i-1] + v[i].se;
		}

		double l = 0, r = den[n], ans;
		while(r-l > EPS){
			double mid = (l+r)/2.0;
			int i = upper_bound(den+1, den+n+1, mid) - (den);
			double extra = mid-den[i-1];
			double temp = (num[i-1]+extra*v[i].fi)/(den[i-1]+extra);

			// printf("i = %d, mid = %lf, extra = %lf, temp = %lf\n", i, mid, extra, temp);

			if(temp < t){
				// ans = mid;
				r = mid;
			}
			else{
				l = mid;
			}
		}		
	
		printf("%.6lf\n", (l+r)/2.0);		
	}


	return 0;
}