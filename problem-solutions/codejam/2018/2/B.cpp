#include <bits/stdc++.h>
using namespace std;
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

const int INF = 1000000000;
const int N = 502;
int t;
ll dp[N][N][N];
int r, b;
// vector<ii> p;

ll solve(int i, int cr, int cb){
	if(i == (r+1)*(b+1)){
		if(cr == r and cb == b) return 0;
		else return -INF;
	}
	if(cr > r or cb > b) return -INF;

	ll& DP = dp[i][cr][cb];
	if(DP != -1) return DP;

	ll ret1 = solve(i+1, cr, cb); // nao pega
	ll ret2 = solve(i+1, cr + i/(b+1), cb + i%(b+1)) + 1; // pega

	return DP = max(ret1, ret2);
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &r, &b);

		// p.clear();
		// for(int i = 0; i <= r; i++){
		// 	for(int j = 0; j <= b; j++){
		// 		p.pb(ii(i,j));
		// 	}
		// }

		// for(int i = 0; i < p.size(); i++){
		// 	printf("%d %d\n", p[i].fi, p[i].se);
		// }

		memset(dp, -1, sizeof dp);
		ll ans = solve(1, 0, 0);
	
		printf("Case #%d: %lld\n", caso, ans);
	}

	return 0;
}