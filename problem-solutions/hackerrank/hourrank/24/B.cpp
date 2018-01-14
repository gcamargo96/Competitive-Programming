#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
double tot = 0, dist[N], subtree[N];
vector<int> adj[N];
int n;
bool vis[N];

int dfs(int u, int d){
	vis[u] = 1;
	dist[u] = d;
	tot += d;
	subtree[u] = 1;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			subtree[u] += dfs(v, d+1);
		}
	}

	return subtree[u];
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	subtree[1] = dfs(1, 0);

	double ans = 0;
	for(int u = 1; u <= n; u++){
		ans += (double(n) - subtree[u]) * (dist[u]/tot);
	}

	printf("%lf\n", ans);

	return 0;
}