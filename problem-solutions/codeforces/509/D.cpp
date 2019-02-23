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

const int N = 200005;
int n;
ll h;
ii v[N];
ll fly[N], fall[N], acfly[N], acfall[N];

int main(void){
	scanf("%d%lld", &n, &h);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].fi, &v[i].se);
	}

	fly[0] = 0;
	for(int i = 0; i < n; i++){
		fly[i+1] = v[i].se - v[i].fi;
	}

	for(int i = 1; i <= n; i++){
		acfly[i] = acfly[i-1] + fly[i];
	}

	fall[0] = v[0].fi;
	for(int i = 1; i < n; i++){
		fall[i] = v[i].fi - v[i-1].se;
	}

	acfall[0] = fall[0];
	for(int i = 1; i < n; i++){
		acfall[i] = acfall[i-1] + fall[i];
	}

	// for(int i = 0; i <= n; i++){
	// 	printf("%lld ", acfly[i]);
	// }
	// printf("\n");

	// for(int i = 0; i < n; i++){
	// 	printf("%lld ", acfall[i]);
	// }
	// printf("\n");

	if(n == 1){
		ll ans = h + ll(v[0].se - v[0].fi);
		printf("%lld\n", ans);
		return 0;
	}

	ll ans = h;
	for(int i = 1; i < n; i++){
		int pos = lower_bound(acfall, acfall+n, h + acfall[i-1]) - acfall;
		ll aux = h + acfly[pos] - acfly[i-1];
		// printf("pos = %d, aux = %lld\n", pos, aux);
		ans = max(ans, aux);
	}

	printf("%lld\n", ans);

	return 0;
}