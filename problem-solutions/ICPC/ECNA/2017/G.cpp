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

const int N = 105, M = 20005;
int n, m;
int v[N], dp[N][M], lim[N];

int solve(int i, int l){
	if(i >= n) return 0;
	if(dp[i][l] != -1) return dp[i][l];

	int cur = min(v[i], lim[l]);
	int ret = cur + solve(i+1, l+1);
	ret = max(ret, cur + solve(i+2, l));
	ret = max(ret, cur + solve(i+3, 0));

	return dp[i][l] = ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	lim[0] = m;
	for(int i = 1; i < n; i++){
		lim[i] = (lim[i-1]*2)/3;
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(0,0);
	if(n > 1) ans = max(ans, solve(1,0));
	if(n > 2) ans = max(ans, solve(2,0));

	printf("%d\n", ans);

	return 0;
}