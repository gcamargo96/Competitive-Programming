#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_p0::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int t, n;
double p, dp[N][1005], p0;
pair<double, double> v[N];

double solve(int i, int peso){
	if(i == n){
		if(peso <= p-p0)
			return 0;
		else
			return -1000000000000000.0;
	}
	if(dp[i][peso] != -1){
		return dp[i][peso];
	}

	double cost = 2.0*sqrt(v[i].fi*v[i].fi + v[i].se*v[i].se);
	double ret = max(solve(i+1, peso), solve(i+1, peso + cost) + cost);
	return dp[i][peso] = cost;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%lf", &n, &p);

		p0 = 0;
		int w, h;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &w, &h);
			if(h > w)
				swap(h,w);
		
			p0 += (2*h+2*w);
			v[i].fi = h;
			v[i].se = w;
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < 1005; j++){
				dp[i][j] = -1;
			}
		}

		double ans = solve(0, 0);
	
		if(p0+ans > p){
			printf("%lf\n", p);
		}
		else{
			printf("%lf\n", p0+ans);
		}
	}

	return 0;
}