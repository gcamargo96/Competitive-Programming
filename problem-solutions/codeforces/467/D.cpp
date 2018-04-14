#include <bits/stdc++.h>
using namespace std;
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

#define INF 0x3f3f3f3f
#define L 0
#define W 1

const int N = 100002;
int n, m, s;
vi adj[N];
int vis[N], pai[N][2], dist[N][2];
bool cycle = 0;

void dfs(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(vis[v] == 1)
			cycle = 1;
		if(vis[v] == 0)
			dfs(v);
	}

	vis[u] = 2;
}

void bfs(int s){
	memset(dist, INF, sizeof dist);
	dist[s][W] = 0;
	queue<ii> q;
	q.emplace(s, W);	

	while(!q.empty()){
		int u = q.front().fi;
		int p = q.front().se;
		q.pop();

		for(int v : adj[u]){
			if(dist[u][p] + 1 < dist[v][p^1]){
				pai[v][p^1] = u;
				dist[v][p^1] = dist[u][p] + 1;
				q.emplace(v, p^1);
			}
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, c, v;
	for(int u = 1; u <= n; u++){
		scanf("%d", &c);

		while(c--){
			scanf("%d", &v);
			adj[u].pb(v);
		}
	}

	scanf("%d", &s);

	dfs(s);
	bfs(s);

	for(int u = 1; u <= n; u++){
		// printf("%d,  %d\n", dist[u][W], dist[u][L]);
		if(adj[u].size() == 0 and dist[u][L] < INF){
			printf("Win\n");

			vi ans;
			int p = W;
			for(int v = u; v != 0; v = pai[v][p]){
				ans.pb(v);
				p ^= 1;
			}
			
			reverse(ans.begin(), ans.end());
			for(int v : ans){
				printf("%d ", v);
			}
			printf("\n");
			return 0;
		}
	}

	if(cycle){
		printf("Draw\n");
	}
	else{
		printf("Lose\n");
	}

	return 0;
}