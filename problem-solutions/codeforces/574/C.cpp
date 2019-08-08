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

const int N = 100005;
ll dp[N][3];
int n;
int v[N][3];

ll solve(int i, int row){
	if(i == n) return 0;
	if(dp[i][row] != -1) return dp[i][row];

	ll ret = solve(i+1, 1-row) + v[i][row];
	ret = max(ret, solve(i+1, row));

	return dp[i][row] = ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i][0]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i][1]);
	}

	memset(dp, -1, sizeof dp);
	ll ans = max(solve(0,0), solve(0, 1));

	printf("%lld\n", ans);

	return 0;
}