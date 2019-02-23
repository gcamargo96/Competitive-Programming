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
#define INF 0x3f3f3f3f

const int N = 25;
int n, a;
int g[N][N][N];
int dist[N][N];
int dp[N][300005], choice[N][300005];
string path;

int calc_dist(int u, int v){
	int sum = 0;
	for(int i = 1; i <= 21; i++){
		for(int j = 1; j <= 21; j++){
			sum += (g[u][i][j] != g[v][i][j]);
		}
	}
	return sum;
}

int solve(int u, int mask){
	mask |= (1<<u);
	if(mask == ((1<<n)-1)) return 0;
	if(dp[u][mask] != -1) return dp[u][mask];

	int ret = INF;
	for(int v = 0; v < n; v++){
		if(((mask>>v)&1) == 0){
			int cur = solve(v, mask | (1<<v)) + min(dist[u][v], a+dist[n][v]);

			if(cur < ret){
				ret = cur;
				choice[u][mask] = v;
			}
		}
	}

	return dp[u][mask] = ret;
}

void get_path(int u, int mask){
	printf("%d\n", u+1);
	mask |= (1<<u);
	if(mask == ((1<<n)-1)) return;	
	
	int v = choice[u][mask];
	if(dist[u][v] > a+dist[n][v]) printf("*\n");
	get_path(v, mask);
}

int main(void){
	scanf("%d%d", &n, &a);

	for(int k = 0; k < n; k++){
		for(int i = 1; i <= 21; i++){
			for(int j = 1; j <= 21; j++){
				char c;
				scanf(" %c", &c);
				g[k][i][j] = (c == '1');
			}
		}
	}

	// for(int k = 0; k < n; k++){
	// 	for(int i = 1; i <= 21; i++){
	// 		for(int j = 1; j <= 21; j++){
	// 			printf("%d", g[k][i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < i; j++){
			dist[i][j] = dist[j][i] = calc_dist(i, j);
		}
	}

	memset(dp, -1, sizeof dp);
	int ans = INF, beg = 0;
	for(int i = 0; i < n; i++){
		int cur = solve(i, 0) + dist[n][i];
		if(cur < ans){
			ans = cur;
			beg = i;
		}
	}

	printf("%d\n", ans);

	get_path(beg, 0);

	return 0;
}