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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const ll INF = 1000000000000000000LL;
const int N = 1000005;
ll n, r, p;
ll dp[N];

ll solve(int x){
	if(x == 1) return 0;
	if(dp[x] != -1) return dp[x];

	ll ret = INF;
	for(int i = 1; i < x; i++){
		ret = min(ret, r + ll(i)*p + solve((x+i)/(i+1)));
	}

	return dp[x] = ret;
}

int main(void){
	scanf("%lld%lld%lld", &n, &r, &p);

	memset(dp, -1, sizeof dp);
	ll ans = solve(n);

	printf("%lld\n", ans);

	return 0;
}