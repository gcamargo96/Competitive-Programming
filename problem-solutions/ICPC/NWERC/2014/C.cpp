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

#define INF 0x3f3f3f3f

const int N = 2005;
int n, d;
int p[N];
ll dp[N][25];

ll solve(int i, int d){
	if(d < 0 and i < n) return INF;
	if(i == n) return 0;
	if(dp[i][d] != -1) return dp[i][d];

	ll ret = INF, sum = 0;
	for(int j = i; j < n; j++){
		sum += p[j];

		int digit = sum%10;
		ll cost = digit < 5 ? sum - digit : sum + 10 - digit;
		ret = min(ret, solve(j+1, d-1) + cost);
	}

	return dp[i][d] = ret;
}

int main(void){
	scanf("%d%d", &n, &d);

	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, d);

	printf("%lld\n", ans);

	return 0;
}