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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1005;
int n, m;
double a[N], b[N];
const double EPS = 1e-9;

bool check(double fuel){
	for(int i = 0; i < n; i++){
		//take-off
		double x = (m+fuel)/a[i];
		fuel -= x;
		if(fuel < 0.0) return 0;

		// landing
		x = (m+fuel)/b[(i+1)%n];
		fuel -= x;
		if(fuel < 0.0) return 0;
	}

	return 1;
}

int main(void){
	scanf("%d", &n);
	scanf("%d", &m);

	for(int i = 0; i < n; i++){
		scanf("%lf", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lf", &b[i]);
	}

	double l = 0, r = 1000000010;
	double ans = -1;
	// while(r-l > EPS){
	for(int i = 0; i < 1000; i++){
		double mid = (l+r)/2.0;

		if(check(mid)){
			ans = mid;
			r = mid;
		}
		else{
			l = mid;
		}
	}

	// printf("ans = %.10lf\n", ans);

	if(ans != -1){
		printf("%.10lf\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}