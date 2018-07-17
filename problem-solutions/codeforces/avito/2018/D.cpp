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

const int N = 52;
int dp[N][N];
int n, k;
ll a[N];
ll mask;

int solve(int pos, int cuts){
	if(cuts > k) 
		return 0;
	if(pos == n+1){
		if(cuts == k) return 1;
		return 0;
	}
	if(dp[pos][cuts] != -1)
		return dp[pos][cuts];

	int ret = 0;
	ll sum = 0;
	for(int i = pos; i <= n; i++){
		sum += a[i];
		if((mask & sum) == mask){
			ret |= solve(i+1, cuts+1);
		}
	}

	return dp[pos][cuts] = ret;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}

	ll ans = 0;
	for(int i = 60; i >= 0; i--){
		mask = ans | (1LL << i);

		memset(dp, -1, sizeof dp);
		int ok = solve(1, 0);

		if(ok){
			// printf("i = %d\n", i);
			ans |= (1LL << i);
		}
	}

	printf("%lld\n", ans);

	return 0;
}