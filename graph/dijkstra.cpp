#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int N = 1000;
const int INF = 0x3f3f3f3f;
int prv[N][N];
int dist[N];
int so;
vector <int> adj[N];


void dijkstra(){
	priority_queue <pii> pq;
	memset(dist, INF, sizeof(dist));
	//for(int i = 0; i <= 7; i++) cout << dist[i] << " ";
	dist[so] = 0;
	pq.push(mp(0,so));

	while(!pq.empty()){
		int cur = pq.top().se;
		int d = -pq.top().fi;
		pq.pop();

		//if(cur == si) return d;

		for(int i = 0; i < adj[cur].size(); i++){
			int nxt = adj[cur][i];
		    int	nd = d + prv[cur][nxt];
			//printf("de %d para %d tera dist %d\n", cur, nxt, nd);

			if(dist[nxt] > nd){
				//cout << "dist " << nd << endl;
				dist[nxt] = nd;
				pq.push(mp(-nd, nxt));
			}
		}
	}
}

int main(void){
	memset(prv, 0, sizeof prv);
	int n, m;
	cin >> n >> m;
	so = 0;

	for(int i = 0; i < m; i++){
		int u, v, cc;
		cin >> u >> v >> cc;
		adj[u].pb(v);
		prv[u][v] = cc;
	}

	dijkstra();

	for(int i = 1; i < n; i++){
		printf("distancia de 0 a %d = %d\n", i, dist[i]);
	}

	return 0;
}
