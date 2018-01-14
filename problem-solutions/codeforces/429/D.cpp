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

const int N = 300002;
int n, m;
int d[N], p[N], deg[N], p_edge[N];
bool vis[N], vis_edge[N];
vector<ii> adj[N];
vector<int> depth[N];

int dfs(int u, int last){
	vis[u] = 1;
	p[u] = last;


	int h = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i].fi;
		int e = adj[u][i].se;
		if(v != last and vis[v] and !vis_edge[e]){
			deg[u]--;
			deg[v]--;
			vis_edge[e] = 1;
			// printf("--deg: deg[%d] = %d, deg[%d] = %d\n", u, deg[u], v, deg[v]);
		}
		if(!vis[v]){
			p_edge[v] = e;
			p[v] = u;
			h = max(h, dfs(v, u));
		}
	}

	// printf("u = %d, last = %d, h = %d\n", u, last, h);
	depth[h].pb(u);
	return h+1;
}

int main(void){
	scanf("%d%d", &n, &m);

	int sum = 0, root = 1;
	bool flag = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
		if(d[i] != -1){
			sum += d[i];
		}
		else{
			flag = 1;
			root = i;
		}
	}

	if(!flag and sum%2 != 0){
		printf("-1\n");
		return 0;
	}

	int u, v;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(ii(v, i));
		adj[v].pb(ii(u, i));
		deg[u]++;
		deg[v]++;
	}

	int h = dfs(root, root);

	vector<int> ans;
	for(int i = 0; i < h-1; i++){
		// printf("h = %d\n", i);
		for(int j = 0; j < depth[i].size(); j++){
			int u = depth[i][j];
			// printf("%d ", u);
			if(d[u] == -1 or deg[u]%2 == d[u]){
				ans.pb(p_edge[u]);
				// printf("add edge from %d to %d, label = %d\n", u, p[u], p_edge[u]);
				// printf("deg[%d] = %d, d[%d] = %d\n", u, deg[u], u, d[u]);
			}
			else{
				deg[u]--;
				deg[p[u]]--;
			}
		}
		// printf("\n");
	}

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}