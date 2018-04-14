#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

struct item{
	ll m, s, p;

	item() {}

	item(ll _m, ll _s, ll _p){
		m = _m;
		s = _s;
		p = _p;
	}
};

ll dp[7][7][25];
int t, r, b, c;
item v[25];
map<ll,ll> m;

ll solve(ll i, ll j, ll falta){
	if(i == c or j == r){
		if(falta == 0){
			auto it = m.end();
			it--;
			return it->fi;
		}
		else{
			return INF;
		}
	}

	// if(dp[i][j][falta] != -1){
	// 	return dp[i][j][falta];
	// }

	ll ret = solve(i+1, j, falta);

	for(ll x = 1; x <= min(v[i].m, falta); x++){
		ll cost = v[i].s*x + v[i].p;
		m[cost]++;
		ret = min(ret, solve(i+1, j+1, falta-x));
		
		m[cost]--;
		if(m[cost] == 0){
			m.erase(cost);
		}
	}

	return dp[i][j][falta] = ret;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d%d", &r, &b, &c);
	
		for(int i = 0; i < c; i++){
			scanf("%lld%lld%lld", &v[i].m, &v[i].s, &v[i].p);
		}
		
		m.clear();
		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0, b);

		printf("Case #%d: %lld\n", caso, ans);
	}


	return 0;
}