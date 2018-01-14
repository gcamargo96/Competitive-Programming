#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

int t;
double d, v, u;

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%lf%lf%lf", &d, &v, &u);
		if(v == 0 or u <= v){
			printf("Case %d: can't determine\n", c);
		}
		else{
			double ux = sqrt(u*u-v*v);
			double t1 = d/ux;
			double t2 = d/u;
			double ans = t1-t2;
			printf("Case %d: %.3lf\n", c, ans);
		}
	}

	return 0;
}