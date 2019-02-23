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

const int N = 1005;
int n, m, q;
vi adj[N], peso[N];
int dist[N][N], ans[N][N];

void dijkstra(){
	memset(dist, INF, sizeof dist);
	// for(int i = 0; i < N; i++)
	// 	for(int j = 0; j < N; j++)
	// 		dist[i][j] = INF;

	priority_queue<pair<ii, int> > pq;
	dist[1][0] = 0;
	pq.push(mp(ii(0,0), 1));

	while(!pq.empty()){
		int u = pq.top().se;
		int d = -pq.top().fi.fi;
		int steps = -pq.top().fi.se;
		pq.pop();

		if(steps == n) continue;

		// printf("u = %d, steps = %d, d = %d\n", u, steps, d);

		// if(dist[u][steps] < d) continue;

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			int w = peso[u][i];

			if(d + w < dist[v][steps+1]){
				dist[v][steps+1] = d+w;
				pq.push(mp(ii(-dist[v][steps+1], -(steps+1)), v));
			}
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

	for(int i = 0; i <= 3; i++){
		for(int u = 1; u <= n; u++){
			printf("%d ", dist[u][i]);
		}
		printf("\n");
	}

	// for(int u = 1; u <= n; u++){
	// 	int mn = INF;
	// 	for(int steps = 0; steps < n; steps++){
	// 		mn = min(mn, dist[u][steps]);
	// 		dist[u][steps] = mn;
	// 	}
	// }

	scanf("%d", &q);

	while(q--){
		int steps;
		scanf("%d%d", &u, &steps);

		if(ans[u][steps] != INF)
			printf("=] %d\n", ans[u][steps]);
		else
			printf("=[\n");
	}

	return 0;
}