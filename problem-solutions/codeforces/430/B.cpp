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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double r, d;
int n;
double x, y, ri;

int main(void){
	scanf("%lf%lf", &r, &d);
	scanf("%d", &n);

	int ans = 0;
	For(i,0,n){
		scanf("%lf%lf%lf", &x, &y, &ri);
		double distcenter = sqrt(x*x + y*y);
		double distcorner1 = distcenter - ri;
		double distcorner2 = distcenter + ri;
		if(distcenter >= r-d and distcenter <= r and distcorner1 >= r-d and distcorner2 <= r){
			// printf("resposta em %d\n", i+1);
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}