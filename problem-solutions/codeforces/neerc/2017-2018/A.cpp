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

const int N = 1000005;
int n;
int w[] = {2, 3, 4, 5, 6, 7};
int v[] = {1, 7, 4, 5, 9, 8};
int dp[7][N];

ll solve(int i, int j){
	if(j == 0)
		return 0;
	if(j < 0 or i > 5)
		return -INF;
	if(dp[i][j] != -1)
		return dp[i][j];

	ll ret = max(solve(i, j-w[i])+v[i], solve(i+1, j));
	return dp[i][j] = ret;
}

int main(void){
	freopen("auxiliary.in", "r", stdin);
	freopen("auxiliary.out", "w", stdout);

	scanf("%d", &n);

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, n);

	printf("%lld\n", ans);

	return 0;
}