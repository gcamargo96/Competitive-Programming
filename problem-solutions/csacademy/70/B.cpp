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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define BEG 0
#define R 1
#define D 2
#define INF 1000000000

const int N = 302;
int n, m;
int g[N][N], dp[N][N][3];
int cntd = 0;

int solve(int i, int j, int dir){
	if(i < 1 or i > n or j < 1 or j > m or g[i][j] == 0){
		if(dir == D and cntd > 0){
			return 0;
		}
		else{
			return -INF;
		}
	}

	if(dp[i][j][dir] != -1)
		return dp[i][j][dir];

	int ret = 1;
	if(dir == D)
		cntd++;

	if(dir == BEG){
		ret = solve(i, j+1, R) + 1;
	}
	if(dir == R){
		ret = max(solve(i, j+1, R), solve(i+1, j, D)) + 1;
	}
	if(dir == D){
		ret = solve(i+1, j, D) + 1;
	}

	if(dir == D)
		cntd--;

	return dp[i][j][dir] = ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	int ans = 0;
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == 1){
				int aux = solve(i, j, BEG);
				// printf("%d ", aux);
				ans = max(ans, aux);
			}
		}
		// printf("\n");
	}

	printf("%d\n", ans);

	return 0;
}