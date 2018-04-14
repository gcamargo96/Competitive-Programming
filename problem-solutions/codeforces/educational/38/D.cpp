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

const int N = 200002;
int n, m;
vector< pair<int, ll> > adj[N];
ll dist[N];
bool vis[N];

void dijkstra(){
	priority_queue<pair<ll, int> > pq;
	for(int u = 1; u <= n; u++){
		pq.push(mp(-dist[u], u));
	}

	while(!pq.empty()){
		int u = pq.top().se;
		ll d = -pq.top().fi;
		pq.pop();

		if(vis[u]){
			continue;
		}
		vis[u] = 1;

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].fi;
			ll w = adj[u][i].se;

			if(d+w < dist[v]){
				dist[v] = d+w;
				pq.push(mp(-dist[v], v));
			}
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	ll w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%lld", &u, &v, &w);
		adj[u].emplace_back(v, 2LL*w);
		adj[v].emplace_back(u, 2LL*w);
	}

	for(int u = 1; u <= n; u++){
		scanf("%lld", &dist[u]);
	}

	dijkstra();

	for(int u = 1; u <= n; u++){
		printf("%lld ", dist[u]);
	}
	printf("\n");

	return 0;
}