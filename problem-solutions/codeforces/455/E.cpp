#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 100002;
int n, m;
int cor[N];
vi adj[N];
vi nodes;
bool vis[N];
int dp[N];

void toposort(int u){
	if(vis[u])
		return;

	vis[u] = 1;

	for(int v : adj[u]){
		toposort(v);
	}

	nodes.pb(u);
}

int solve(int u){
	if(dp[u] != -1)
		return dp[u];

	int ret = 0;
	for(int v : adj[u]){
		ret = max(ret, solve(v) + (cor[u] == 1 and cor[v] == 0));
	}

	if(cor[u] == 1 and adj[u].size() == 0)
		ret++;

	return dp[u] = ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &cor[i]);
	}

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &v, &u);
		adj[u].pb(v);
	}

	for(int i = 0; i < n; i++){
		toposort(i);
	}

	reverse(nodes.begin(), nodes.end());
	memset(dp, -1, sizeof dp);

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, solve(nodes[i]));
	}

	printf("%d\n", ans);

	return 0;
}