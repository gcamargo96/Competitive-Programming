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

#define A 0
#define B 1
#define M 100000000

const int N = 102;
int na, nb, ka, kb;
ll dp[N][N][N][3];

ll add(ll a, ll b){
	return (a+b)%M;
}

ll solve(int ca, int cb, int cl, int last){
	if(ca > na or cb > nb) return 0;
	if(last == A and cl > ka) return 0;
	if(last == B and cl > kb) return 0;
	if(ca+cb == na+nb) return 1;

	ll& DP = dp[ca][cb][cl][last];
	if(DP != -1) return DP;

	ll ret = 0;
	if(last == A){
		ret = add(ret, solve(ca+1, cb, cl+1, A));
		ret = add(ret, solve(ca, cb+1, 1, B));
	}
	else{
		ret = add(ret, solve(ca+1, cb, 1, A));
		ret = add(ret, solve(ca, cb+1, cl+1, B));
	}

	return DP = ret;
}

int main(void){
	scanf("%d%d%d%d", &na, &nb, &ka, &kb);

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 0, 0, 0);

	printf("%lld\n", ans);

	return 0;
}