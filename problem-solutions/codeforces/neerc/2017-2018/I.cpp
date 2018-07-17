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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n;
ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;
ll x, y;

int main(void){
	freopen("intel.in", "r", stdin);
	freopen("intel.out", "w", stdout);

	scanf("%d", &n);

	ll total = 0;
	pair<ll,ll> fi, last;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &x, &y);

		if(i == 0){
			fi.fi = x;
			fi.se = y;
		}
		else{
			total += abs(x-last.fi) + abs(y-last.se);
		}
		if(i == n-1){
			total += abs(x-fi.fi) + abs(y-fi.se);
		}
		last = mp(x,y);

		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}

	// printf("maxx = %lld, minx = %lld, maxy = %lld, miny = %lld\n", maxx, minx, maxy, miny);

	// printf("total = %lld\n", total);

	ll visible = 2LL*(maxx-minx + maxy-miny);
	// printf("visible = %lld\n", visible);

	printf("%lld\n", total - visible);

	return 0;
}