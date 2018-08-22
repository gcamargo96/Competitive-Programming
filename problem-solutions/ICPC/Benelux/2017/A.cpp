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

double m, n, r;
double ax, ay, bx, by;

int main(void){
	scanf("%lf%lf%lf", &m, &n, &r);
	scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);

	if(ax == bx){
		printf("%.10lf\n", r/n * abs(ay-by));
		return 0;
	}

	double ans = DBL_MAX;
	double ang = PI/m * abs(ax-bx);
	for(int cur = 0; cur <= min(ay, by); cur++){
		double dr = r/n * ay +  r/n * by - 2.0 * r/n * double(cur);
		double raio = r/n * double(cur);
		double dc = ang * raio;
		ans = min(ans, dr + dc);
	}

	printf("%.10lf\n", ans);

	return 0;
}