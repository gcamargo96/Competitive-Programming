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

const int N = 100005;
int n, m;
vi adj[N];
int dp[N][3];

int solve(int u, int label, int p){
	if(dp[u][label] != -1) return dp[u][label];
	int ret = label;
	for(int v : adj[u]){
		if(v == p) continue;

		if(label == 0){
			ret += max(solve(v, 0, u), solve(v, 1, u));
		}
		else{
			ret += solve(v, 0, u);
		}
	}
	return dp[u][label] = ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset(dp, -1, sizeof dp);
	int ans = max(solve(1,0,0), solve(1,1,0));
	printf("%d\n", ans);

	return 0;
}