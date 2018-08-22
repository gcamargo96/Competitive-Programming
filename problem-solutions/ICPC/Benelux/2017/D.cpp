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

#define INF 1000000000000000000LL

const int N = 100005;
vi adj[N], peso[N];
ll dist[N];
int pai[N], prv[N];
bool vis[N];
int n, m;

void dijkstra(){
	priority_queue<pair<ll, int> > pq;
	for(int i = 0; i < n; i++){
		dist[i] = INF;
	}
	// dist[1] = 0;
	pai[1] = 1;
	pq.push(mp(0LL, 1));

	while(!pq.empty()){
		int u = pq.top().se;
		ll d = -pq.top().fi;
		pq.pop();

		// if(dist[u] != INF) continue;

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			ll w = peso[u][i];

			if(d+w < dist[v]){
				dist[v] = d+w;
				pai[v] = u;
				pq.push(mp(-dist[v], v));
			}
		}
	}
}

void dfs(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v] and pai[u] != v){
			prv[v] = u;
			dfs(v);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		adj[u].pb(v);
		adj[v].pb(u);
		peso[u].pb(w);
		peso[v].pb(w);
	}

	dijkstra();

	// for(int u = 0; u < n; u++){
	// 	printf("%lld ", dist[u]);
	// }
	// printf("\n");

	memset(prv, -1, sizeof prv);
	dfs(0);

	if(prv[1] == -1){
		printf("impossible\n");
	}
	else{
		vi ans;
		for(int u = 1; u != 0; u = prv[u]){
			ans.pb(u);
		}
		ans.pb(0);
		reverse(ans.begin(), ans.end());

		printf("%d ", int(ans.size()));
		for(int i = 0; i < ans.size(); i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}

	return 0;
}